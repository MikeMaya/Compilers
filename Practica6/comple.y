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
  int follow();
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
%left ';'
%left OR
%left AND
%left UNARYMINUS NOT
%left GT GE LT LE EQ NE
%token <sym> CNUMBER VAR BLTIN INDEF WHILE IF ELSE PRINT FOR 
%type  <inst> asgn exp while if end cond stmt stmtlist for ';' ')'

%% /* A continuación las reglas gramaticales y las acciones */

list:   
	| list'\n'
  | list asgn '\n'      { code2(pop, STOP); return 1; }
  | list exp '\n'       { code2(print, STOP); return 1;}
  | list stmt '\n'      { code(STOP); return 1; }
	;

asgn: VAR '=' exp       { $$=$3; code3(varpush, (Inst)$1, assign);}
  ;

stmt: exp               { code(pop); }
  | PRINT exp           { code(prexpr); $$ = $2;} 
  | while cond stmt end { ($1)[1] = (Inst)$3;     /* cuerpo de la iteración */ 
                          ($1)[2] = (Inst)$4; }   /* terminar si la condición no se cumple */
  | if cond stmt end    {   /* proposición if que no emplea else */ 
                          ($1)[1] = (Inst)$3;     /* parte then */ 
                          ($1)[3] = (Inst)$4; }   /* terminar si la condición no se cumple */ 
  | if cond stmt end ELSE stmt end {  /* proposición if con parte else */
                          ($1)[1]   =   (Inst)$3; /*  parte then  */
                          ($1)[2]   =   (Inst)$6; /* parte else   */
                          ($1)[3]   =   (Inst)$7;
                        }

  | for '(' stmtlist end ';' cond ';' stmtlist end ')' stmt end {
                          ($1)[1] = (Inst)$6; /*condicional*/
                          ($1)[2] = (Inst)$8; /*instruciones finales*/ 
                          ($1)[3] = (Inst)$11; /*cuerpo si cumple*/
                          ($1)[4] = (Inst)$12; /* final del for*/ 
                        } 
  | '{'stmtlist'}'      { $$  =  $2; }
  ;

stmtlist:               { $$ = progp; }
  | stmtlist '\n' 
  | stmtlist stmt
  ;

cond: '('exp')'         { code(STOP);  $$= $2;}
  | exp                 { code(STOP);  $$= $1;}
  ;

end:                    { code(STOP); $$ = progp; }
  ;

while: WHILE            { $$=code3(whilecode,STOP,STOP);}
  ;

if:IF                   { $$=code(ifcode); code3(STOP, STOP, STOP); }
  ;

for: FOR                { $$=code(forcode); code(STOP); code3(STOP,STOP,STOP);}
  ;

exp: CNUMBER            { $$=code2(constpush, (Inst)$1); }
  | VAR                 { $$=code3(varpush, (Inst)$1, eval);}
  | BLTIN  '(' exp ')'  { $$=code2(bltin, (Inst)$1->u.ptr);}
  | asgn
  | exp '+' exp         { code(add); }
  | exp '-' exp         { code(sub); }
  | exp '*' exp         { code(mul); }
  | exp '/' exp         { code(divi); }
  | exp '^' exp         { code(power); }
  | '(' exp ')'         { $$=$2; }
  | exp GT exp          { code(gt); }
  | exp GE exp          { code(ge); }
  | exp LT exp          { code(lt); }
  | exp LE exp          { code(le); }
  | exp EQ exp          { code(eq); }
  | exp NE exp          { code(ne); }
  | exp AND exp         { code(and); }
  | exp OR exp          { code(or); }
  | NOT exp             { $$ = $2; code(not); }
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
      return s->type;
    }
  }
  switch (c) {
    case '>':
      return follow('=', GE, GT);
    case '<':                
      return follow('=', LE, LT);
    case '=':                
      return follow('=', EQ, '=');
    case '!':                
      return follow('=', NE, NOT);
    case '|':                
      return follow('|', OR, '|');
    case '&':                
      return follow('&', AND, '&');
    case '\n':              
      lineno++; return '\n';
    default:                  
      return c; 
  }
}

//Completa las sentencias codicinales
int follow(expect,   ifyes,   ifno){
  int c  = getchar();
  if  (c  ==  expect)
    return ifyes; 
  ungetc(c,   stdin); 
  return  ifno;
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

static struct { char   *name; /* Palabras clave */
int    kval;
} keywords[] = {
"if",   IF,
"else" ,  ELSE,
"while",  WHILE,
"print",  PRINT,
"for", FOR,
0,      0,
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
  for(i=0; keywords[i].name; i++)
    install(keywords[i].name, keywords[i].kval, creaComplejo(0,0));
}
