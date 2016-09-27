#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "comple.y"
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
#line 16 "comple.y"
typedef union {
  Inst *inst;
  Symbol *sym;
} YYSTYPE;
#line 24 "y.tab.c"
#define CNUMBER 257
#define VAR 258
#define BLTIN 259
#define INDEF 260
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    0,    1,    2,    2,    2,    2,    2,
    2,    2,    2,    2,
};
short yylen[] = {                                         2,
    0,    2,    3,    3,    3,    1,    3,    3,    3,    3,
    3,    3,    1,    4,
};
short yydefred[] = {                                      1,
    0,    6,    0,    0,    2,    0,    0,    0,    0,    0,
   13,    0,    3,    0,    0,    0,    0,    0,    4,    0,
    0,   12,    0,    0,    0,    9,   10,   14,
};
short yydgoto[] = {                                       1,
    7,    8,
};
short yysindex[] = {                                      0,
  -10,    0,  -55,  -30,    0,  -39,    2,   -8,  -39,  -39,
    0,  -38,    0,  -39,  -39,  -39,  -39,  -39,    0,  -22,
  -28,    0,  -22,  -18,  -18,    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,   -2,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    8,
    0,    0,   12,    1,    6,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,   53,
};
#define YYTABLESIZE 249
short yytable[] = {                                       5,
    6,   19,   22,   17,   15,    9,   16,   13,   18,   10,
    7,   13,   28,   17,   15,    8,   16,    5,   18,   17,
   15,   11,   16,   17,   18,    0,    0,    0,   18,    6,
    0,    0,    0,   17,   15,    0,   16,    0,   18,   13,
   13,    7,   13,    7,   13,    7,    8,    0,    8,    0,
    8,    0,   11,    0,    0,   14,    0,    0,   12,    0,
    0,   20,   21,    0,    0,   14,   23,   24,   25,   26,
   27,   14,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   14,    0,    0,    0,    0,
    0,   13,    0,    0,    7,    0,    0,    0,    0,    8,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    2,   11,    4,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    2,    3,    4,
};
short yycheck[] = {                                      10,
   40,   10,   41,   42,   43,   61,   45,   10,   47,   40,
   10,   10,   41,   42,   43,   10,   45,   10,   47,   42,
   43,   10,   45,   42,   47,   -1,   -1,   -1,   47,   40,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   42,
   43,   41,   45,   43,   47,   45,   41,   -1,   43,   -1,
   45,   -1,   41,   -1,   -1,   94,   -1,   -1,    6,   -1,
   -1,    9,   10,   -1,   -1,   94,   14,   15,   16,   17,
   18,   94,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   94,   -1,   -1,   -1,   -1,
   -1,   94,   -1,   -1,   94,   -1,   -1,   -1,   -1,   94,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 260
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'^'",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"CNUMBER","VAR","BLTIN","INDEF",
};
char *yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list asgn '\\n'",
"list : list exp '\\n'",
"asgn : VAR '=' exp",
"exp : CNUMBER",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : exp '*' exp",
"exp : exp '/' exp",
"exp : exp '^' exp",
"exp : '(' exp ')'",
"exp : VAR",
"exp : BLTIN '(' exp ')'",
};
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 49 "comple.y"

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
#line 306 "y.tab.c"
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: state %d, shifting to state %d (%s)\n",
                    yystate, yytable[yyn],yyrule[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 3:
#line 31 "comple.y"
{ code2(pop, STOP); return 1; }
break;
case 4:
#line 32 "comple.y"
{ code2(print, STOP); return 1;}
break;
case 5:
#line 35 "comple.y"
{ code3(varpush, (Inst)yyvsp[-2].sym, assign);}
break;
case 6:
#line 38 "comple.y"
{ code2(constpush, (Inst)yyvsp[0].sym); }
break;
case 7:
#line 39 "comple.y"
{ code(add); }
break;
case 8:
#line 40 "comple.y"
{ code(sub); }
break;
case 9:
#line 41 "comple.y"
{ code(mul); }
break;
case 10:
#line 42 "comple.y"
{ code(divi); }
break;
case 11:
#line 43 "comple.y"
{ code(power); }
break;
case 13:
#line 45 "comple.y"
{ code3(varpush, (Inst)yyvsp[0].sym, eval);}
break;
case 14:
#line 46 "comple.y"
{ code2(bltin, (Inst)yyvsp[-3].sym->u.ptr);}
break;
#line 490 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
