%{
  #include "complejo_cal.h"
  #include <string.h>
  #include <math.h>
  #include <errno.h>
  #include <stdlib.h>
  #define code2(c1, c2)     code(c1); code(c2);
  #define code3(c1, c2, c3) code(c1); code(c2); code(c3);
  void yyerror (char *s);
  int yylex ();
  int init();
  void warning(char *s, char *t);
  void execerror(char *s, char *t);
%}

%union {
  Inst *inst;
  Symbol *sym;
}

%right '=' '^'
%left '+' '-'
%left '*' '/'
%token <sym> CNUMBER VAR BLTIN INDEF


%% /* A continuación las reglas gramaticales y las acciones */

list:   
	| list'\n'
  | list asgn '\n' { code2(pop, STOP); return 1; }
  | list exp '\n'  { code2(print, STOP); return 1;}
	;

asgn: VAR '=' exp  { code3(varpush, (Inst)$1, assign);}
  ;

exp: CNUMBER        { code2(constpush, (Inst)$1); }
  | exp '+' exp     { code(add); }
  | exp '-' exp     { code(sub); }
  | exp '*' exp     { code(mul); }
  | exp '/' exp     { code(divi); }
  | exp '^' exp     { code(power); }
  | '(' exp ')'     
  | VAR             { code3(varpush, (Inst)$1, eval);}
  | BLTIN  '(' exp ')'   { code2(bltin, (Inst)$1->u.ptr);}
	;
%%

#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf begin;
char *progname;
int lineno = 1;

int main (int argc, char *argv[]){
	progname=argv[0];
  init();
  for(initcode(); yyparse (); initcode()){
    execute(prog);
  }
  return 0;
}

int yylex (){
  int c;
  double rm, cm, num;
  while ((c = getchar ()) == ' ' || c == '\t') ; 
 	if (c == EOF)                            
   	return 0;
  if ( c == '.' || isdigit (c)){
    ungetc (c, stdin);
    scanf ("%lf", &rm);
    c=getchar();
    if(!(c == '+' || c=='-')) {
  		yyerror("Complejo mal formado + - "); 
   		return 0;
    }
  	if(c == '+')  cm=1;
  	else cm=-1;
    c=getchar();
    if (!(c == '.' ||  isdigit (c))){
	   	yyerror("Complejo mal formado numero 2 ");
	   	return 0;
    }
    ungetc (c, stdin);
    scanf ("%lf", &num);
    cm*=num;
    c=getchar();
    if(c != 'i') {
    	yyerror("Complejo mal formado i");
    	return(0);
    }
    yylval.sym=install("", CNUMBER,creaComplejo(rm,cm));
	  return CNUMBER;
  }

  if(isalpha(c)){
    Symbol *s;
    char sbuf[200], *p=sbuf;
    do {
      *p++=c;
    } while ((c=getchar())!=EOF && isalnum(c));
    ungetc(c, stdin);
    *p='\0';
    if((s=lookup(sbuf))==(Symbol *)NULL)
      s=install(sbuf, INDEF, creaComplejo(0,0));
    yylval.sym=s;   
    if(s->type == INDEF){
      return VAR;
    } else {
      //printf("func=(%s) tipo=(%d) \n", s->name, s->type);
      return s->type;
    }
  }
  if(c == '\n')
		lineno++;
  return c;                                
}


void yyerror (char *s)  /* Llamada por yyparse ante un error */{
	warning(s, (char *) 0);
}

void warning(char *s, char *t){
	fprintf (stderr, "%s: %s", progname, s);
	if(t) fprintf (stderr, " %s", t);
	fprintf (stderr, "cerca de la linea %d\n", lineno);
}

//extern Complejo *Log(),* Log10(),* Sqrt(),* Exp( ) ,* integer ( ) ;

struct {         /* Constantes */ 
  char *name; Complejo* cval;
} consts[6];

void agregar(){
  consts[0].name="PI";
  consts[0].cval=creaComplejo (3.14159265358979323846, 0);
  consts[1].name="E";
  consts[1].cval=creaComplejo (2.71828182845904523536, 0);
  consts[2].name="GAMMA";
  consts[2].cval=creaComplejo (0.57721566490153286060, 0);
  consts[3].name="DEG";
  consts[3].cval=creaComplejo (57.29577951308232087680,0);
  consts[4].name="PHI";
  consts[4].cval=creaComplejo (1.6180339887498948*820, 0);
  consts[5].name=0;
  consts[5].cval=0;
} 

static struct { /*  Predefinidos */
char *name;
Complejo *(*func)();
} builtins[] =  {
"sin",  Sin,
"cos" , Cos,
"tan", Tan,
"log", Log,
"log10", Log10,
"exp", Exp,
"abs",  Fabs,
0,  0
};
 /* instalar constantes y predefinidos en la tabla */
int init( ) {
  int i;
  Symbol *s;
  agregar();
  for (i = 0; consts[i].name; i++)
    install(consts[i].name, VAR, consts[i].cval);
  for (i = 0; builtins[i].name; i++) {
    s = install(builtins[i].name, BLTIN, creaComplejo(0,0));
    s->u.ptr = builtins[i].func;
  }
}
