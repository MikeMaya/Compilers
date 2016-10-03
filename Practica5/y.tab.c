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
  int follow();
  int init();
  void warning(char *s, char *t);
  void execerror(char *s, char *t);
#line 17 "comple.y"
typedef union {
  Inst *inst;
  Symbol *sym;
} YYSTYPE;
#line 25 "y.tab.c"
#define OR 257
#define AND 258
#define UNARYMINUS 259
#define NOT 260
#define GT 261
#define GE 262
#define LT 263
#define LE 264
#define EQ 265
#define NE 266
#define CNUMBER 267
#define VAR 268
#define BLTIN 269
#define INDEF 270
#define WHILE 271
#define IF 272
#define ELSE 273
#define PRINT 274
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    0,    0,    1,    7,    7,    7,    7,
    7,    7,    8,    8,    8,    6,    5,    3,    4,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,
};
short yylen[] = {                                         2,
    0,    2,    3,    3,    3,    3,    1,    2,    4,    4,
    7,    3,    0,    2,    2,    3,    0,    1,    1,    1,
    1,    4,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,
};
short yydefred[] = {                                      1,
    0,    0,   20,    0,    0,   18,   19,    0,    2,   13,
    0,    0,    0,    0,    0,    0,   23,    0,    0,    0,
    0,    0,    0,    3,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    4,    0,    0,
    0,    5,    0,    0,   14,   12,    0,   15,   29,    0,
    0,    0,    0,    0,    0,    0,   30,   31,   32,   33,
   34,   35,    0,   17,   17,   22,   16,    9,    0,    0,
   17,   11,
};
short yydgoto[] = {                                       1,
   17,   47,   14,   15,   68,   40,   16,   22,
};
short yysindex[] = {                                      0,
  286,  -35,    0,  -60,  -28,    0,    0,  -35,    0,    0,
  -35,    4,  352,  -25,  -25,    6,    0, -223,  -35,  -35,
  332,  220,  378,    0,  -35,  -35,  -35,  -35,  -35,  -35,
  -35,  -35,  -35,  -35,  -35,  -35,  -35,    0,  -35,  250,
  250,    0,  332,  396,    0,    0,  332,    0,    0,  332,
  305,  305, -255, -255, -237, -223,    0,    0,    0,    0,
    0,    0,  418,    0,    0,    0,    0,    0, -256,  250,
    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,  -10,    0,    0,    0,    0,    0,    0,
    0,  436,    0,    0,    0,    0,    0,    8,    0,    0,
  184,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  144,    0,    0,    0,  202,    0,    0,  162,
   98,  116,   64,   82,   46,   26,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  268,    0,
    0,    0,
};
short yygindex[] = {                                      0,
   19,  684,    0,    0,  -52,   29,  -18,    0,
};
#define YYTABLESIZE 723
short yytable[] = {                                      21,
   19,   30,   31,   48,   11,   32,   33,   34,   35,   36,
   37,   20,   69,   24,   39,   42,   70,   38,   72,   12,
   31,   64,   65,   32,   33,   34,   35,   36,   37,   21,
   21,   21,   21,    0,   21,   36,   21,   32,   33,   34,
   35,   36,   37,   41,    0,    0,    0,   38,   38,   38,
   38,   71,   38,    0,   38,   37,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   36,   36,   36,   36,    0,
   36,    0,   36,   26,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   21,    0,   37,   37,   37,   37,    0,
   37,   27,   37,    0,    0,    0,    0,    0,    0,    0,
    0,   38,    0,   26,   26,   26,   26,   24,   26,    0,
   26,    0,   21,    0,   21,    0,    0,    0,    0,   36,
    0,   27,   27,   27,   27,   25,   27,    0,   27,    0,
   38,    0,   38,    0,    0,    0,    0,   24,   24,   37,
   24,    0,   24,    0,    0,    0,    0,    0,   36,    0,
   36,    0,    0,    6,    0,   25,   25,   26,   25,    0,
   25,    0,    0,    0,    0,    0,    0,    0,   37,    0,
   37,   28,    0,    0,    0,   27,    0,    0,    0,    0,
    0,    0,    0,    6,    6,    0,   26,    0,   26,    0,
    0,   24,    0,    8,    0,    0,    0,    0,    0,    0,
    0,   28,   28,    0,   27,    0,   27,    0,    0,   25,
    0,    7,    0,    0,    0,    0,    0,    0,    0,    0,
   24,    0,   24,    8,    2,    0,    0,    0,    0,   45,
    0,    3,    4,    5,    0,    0,    0,    0,   25,    0,
   25,    7,    0,    0,    0,    0,   21,   21,    0,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   11,
   21,   21,   21,   21,   38,   38,    6,   38,    6,    0,
    0,    0,    0,    0,   38,   38,   38,   10,   38,   38,
   38,   38,   36,   36,   28,   36,   28,    0,    0,   11,
    0,    0,   36,   36,   36,    9,   36,   36,   36,   36,
    0,    0,   37,    0,    0,   37,    8,   10,    8,    0,
    0,    0,   37,   37,   37,    0,   37,   37,   37,   37,
    0,    0,    0,   26,    7,   11,    7,    0,    0,    0,
   26,   26,   26,    0,   26,   26,   26,   26,    0,    0,
    0,   27,   10,    0,   46,    0,   28,    0,   27,   27,
   27,   29,   27,   27,   27,   27,    0,   24,    0,    0,
    0,   38,    0,    0,   24,   24,   24,    0,   24,   24,
   24,   24,   10,   28,   26,   25,   27,    0,   29,    0,
    0,    0,   25,   25,   25,    0,   25,   25,   25,   25,
   10,    0,   10,   28,   26,    0,   27,    0,   29,    0,
    0,    0,    0,    6,    0,    0,    0,    0,   10,    0,
    6,    6,    6,    0,    6,    6,    6,    6,   49,   28,
   26,   28,   27,    0,   29,   25,    0,    0,   28,   28,
   28,    0,   28,   28,   28,   28,   66,   28,   26,    0,
   27,    0,   29,    8,    0,   25,    0,    0,    0,    0,
    8,    8,    8,    0,    8,    8,    8,    8,   67,   28,
   26,    7,   27,    0,   29,    0,    0,    0,    7,    7,
    7,   25,    7,    7,    7,    7,    0,   23,   23,    2,
   23,    0,   23,    0,    0,    0,    3,    4,    5,   25,
    6,    7,    0,    8,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    2,
    0,   25,    0,    0,    0,    0,    3,    4,    5,    0,
    6,    7,    0,    8,    0,    0,    0,   10,    0,   23,
    0,    0,    0,    0,   10,   10,   10,    0,   10,   10,
    0,   10,    0,    0,    0,    2,    0,    0,    0,    0,
    0,    0,    3,    4,    5,    0,    6,    7,    0,    8,
    0,   30,   31,    0,    0,   32,   33,   34,   35,   36,
   37,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   30,   31,
    0,    0,   32,   33,   34,   35,   36,   37,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   30,   31,
    0,    0,   32,   33,   34,   35,   36,   37,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   30,   31,    0,    0,   32,   33,
   34,   35,   36,   37,    0,    0,    0,    0,    0,    0,
    0,    0,   30,   31,    0,    0,   32,   33,   34,   35,
   36,   37,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   30,   31,    0,    0,   32,   33,
   34,   35,   36,   37,   13,   18,    0,    0,    0,    0,
    0,   21,   23,   23,   23,    0,   23,   23,   23,   23,
   23,   23,   43,   44,    0,    0,    0,    0,   50,   51,
   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,
   62,    0,   63,
};
short yycheck[] = {                                      10,
   61,  257,  258,   22,   40,  261,  262,  263,  264,  265,
  266,   40,   65,   10,   40,   10,  273,   10,   71,    1,
  258,   40,   41,  261,  262,  263,  264,  265,  266,   40,
   41,   42,   43,   -1,   45,   10,   47,  261,  262,  263,
  264,  265,  266,   15,   -1,   -1,   -1,   40,   41,   42,
   43,   70,   45,   -1,   47,   10,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   40,   41,   42,   43,   -1,
   45,   -1,   47,   10,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   94,   -1,   40,   41,   42,   43,   -1,
   45,   10,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   94,   -1,   40,   41,   42,   43,   10,   45,   -1,
   47,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   94,
   -1,   40,   41,   42,   43,   10,   45,   -1,   47,   -1,
  123,   -1,  125,   -1,   -1,   -1,   -1,   40,   41,   94,
   43,   -1,   45,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,   -1,   10,   -1,   40,   41,   94,   43,   -1,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  125,   10,   -1,   -1,   -1,   94,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   40,   41,   -1,  123,   -1,  125,   -1,
   -1,   94,   -1,   10,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   41,   -1,  123,   -1,  125,   -1,   -1,   94,
   -1,   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   -1,  125,   40,  260,   -1,   -1,   -1,   -1,   10,
   -1,  267,  268,  269,   -1,   -1,   -1,   -1,  123,   -1,
  125,   40,   -1,   -1,   -1,   -1,  257,  258,   -1,  260,
  261,  262,  263,  264,  265,  266,  267,  268,  269,   40,
  271,  272,  273,  274,  257,  258,  123,  260,  125,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,   10,  271,  272,
  273,  274,  257,  258,  123,  260,  125,   -1,   -1,   40,
   -1,   -1,  267,  268,  269,   10,  271,  272,  273,  274,
   -1,   -1,  257,   -1,   -1,  260,  123,   40,  125,   -1,
   -1,   -1,  267,  268,  269,   -1,  271,  272,  273,  274,
   -1,   -1,   -1,  260,  123,   40,  125,   -1,   -1,   -1,
  267,  268,  269,   -1,  271,  272,  273,  274,   -1,   -1,
   -1,  260,  123,   -1,  125,   -1,   42,   -1,  267,  268,
  269,   47,  271,  272,  273,  274,   -1,  260,   -1,   -1,
   -1,   10,   -1,   -1,  267,  268,  269,   -1,  271,  272,
  273,  274,  123,   42,   43,  260,   45,   -1,   47,   -1,
   -1,   -1,  267,  268,  269,   -1,  271,  272,  273,  274,
  123,   -1,  125,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,  260,   -1,   -1,   -1,   -1,  123,   -1,
  267,  268,  269,   -1,  271,  272,  273,  274,   41,   42,
   43,  260,   45,   -1,   47,   94,   -1,   -1,  267,  268,
  269,   -1,  271,  272,  273,  274,   41,   42,   43,   -1,
   45,   -1,   47,  260,   -1,   94,   -1,   -1,   -1,   -1,
  267,  268,  269,   -1,  271,  272,  273,  274,   41,   42,
   43,  260,   45,   -1,   47,   -1,   -1,   -1,  267,  268,
  269,   94,  271,  272,  273,  274,   -1,   42,   43,  260,
   45,   -1,   47,   -1,   -1,   -1,  267,  268,  269,   94,
  271,  272,   -1,  274,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  260,
   -1,   94,   -1,   -1,   -1,   -1,  267,  268,  269,   -1,
  271,  272,   -1,  274,   -1,   -1,   -1,  260,   -1,   94,
   -1,   -1,   -1,   -1,  267,  268,  269,   -1,  271,  272,
   -1,  274,   -1,   -1,   -1,  260,   -1,   -1,   -1,   -1,
   -1,   -1,  267,  268,  269,   -1,  271,  272,   -1,  274,
   -1,  257,  258,   -1,   -1,  261,  262,  263,  264,  265,
  266,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,
   -1,   -1,  261,  262,  263,  264,  265,  266,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,
   -1,   -1,  261,  262,  263,  264,  265,  266,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,   -1,   -1,  261,  262,
  263,  264,  265,  266,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,   -1,   -1,  261,  262,  263,  264,
  265,  266,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,   -1,   -1,  261,  262,
  263,  264,  265,  266,    1,    2,   -1,   -1,   -1,   -1,
   -1,    8,  257,  258,   11,   -1,  261,  262,  263,  264,
  265,  266,   19,   20,   -1,   -1,   -1,   -1,   25,   26,
   27,   28,   29,   30,   31,   32,   33,   34,   35,   36,
   37,   -1,   39,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 274
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'^'",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"OR","AND","UNARYMINUS","NOT","GT","GE","LT","LE","EQ","NE",
"CNUMBER","VAR","BLTIN","INDEF","WHILE","IF","ELSE","PRINT",
};
char *yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list asgn '\\n'",
"list : list exp '\\n'",
"list : list stmt '\\n'",
"asgn : VAR '=' exp",
"stmt : exp",
"stmt : PRINT exp",
"stmt : while cond stmt end",
"stmt : if cond stmt end",
"stmt : if cond stmt end ELSE stmt end",
"stmt : '{' stmtlist '}'",
"stmtlist :",
"stmtlist : stmtlist '\\n'",
"stmtlist : stmtlist stmt",
"cond : '(' exp ')'",
"end :",
"while : WHILE",
"if : IF",
"exp : CNUMBER",
"exp : VAR",
"exp : BLTIN '(' exp ')'",
"exp : asgn",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : exp '*' exp",
"exp : exp '/' exp",
"exp : exp '^' exp",
"exp : '(' exp ')'",
"exp : exp GT exp",
"exp : exp GE exp",
"exp : exp LT exp",
"exp : exp LE exp",
"exp : exp EQ exp",
"exp : exp NE exp",
"exp : exp AND exp",
"exp : exp OR exp",
"exp : NOT exp",
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
#line 97 "comple.y"

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
#line 495 "y.tab.c"
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
#line 36 "comple.y"
{ code2(pop, STOP); return 1; }
break;
case 4:
#line 37 "comple.y"
{ code2(print, STOP); return 1;}
break;
case 5:
#line 38 "comple.y"
{ code(STOP); return 1; }
break;
case 6:
#line 41 "comple.y"
{ yyval.inst=yyvsp[0].inst; code3(varpush, (Inst)yyvsp[-2].sym, assign);}
break;
case 7:
#line 44 "comple.y"
{ code(pop); }
break;
case 8:
#line 45 "comple.y"
{ code(prexpr); yyval.inst = yyvsp[0].inst;}
break;
case 9:
#line 46 "comple.y"
{ (yyvsp[-3].inst)[1] = (Inst)yyvsp[-1].inst;     /* cuerpo de la iteración */ 
                          (yyvsp[-3].inst)[2] = (Inst)yyvsp[0].inst; }
break;
case 10:
#line 48 "comple.y"
{   /* proposición if que no emplea else */ 
                          (yyvsp[-3].inst)[1] = (Inst)yyvsp[-1].inst;     /* parte then */ 
                          (yyvsp[-3].inst)[3] = (Inst)yyvsp[0].inst; }
break;
case 11:
#line 51 "comple.y"
{  /* proposición if con parte else */
                          (yyvsp[-6].inst)[1]   =   (Inst)yyvsp[-4].inst; /*  parte then  */
                          (yyvsp[-6].inst)[2]   =   (Inst)yyvsp[-1].inst; /* parte else   */
                          (yyvsp[-6].inst)[3]   =   (Inst)yyvsp[0].inst;
                          }
break;
case 12:
#line 56 "comple.y"
{ yyval.inst  =  yyvsp[-1].inst; }
break;
case 13:
#line 59 "comple.y"
{ yyval.inst = progp; }
break;
case 16:
#line 64 "comple.y"
{ code(STOP);  yyval.inst= yyvsp[-1].inst;}
break;
case 17:
#line 67 "comple.y"
{ code(STOP); yyval.inst = progp; }
break;
case 18:
#line 70 "comple.y"
{ yyval.inst=code3(whilecode,STOP,STOP);}
break;
case 19:
#line 73 "comple.y"
{ yyval.inst=code(ifcode); code3(STOP, STOP, STOP); }
break;
case 20:
#line 76 "comple.y"
{ yyval.inst=code2(constpush, (Inst)yyvsp[0].sym); }
break;
case 21:
#line 77 "comple.y"
{ yyval.inst=code3(varpush, (Inst)yyvsp[0].sym, eval);}
break;
case 22:
#line 78 "comple.y"
{ yyval.inst=code2(bltin, (Inst)yyvsp[-3].sym->u.ptr);}
break;
case 24:
#line 80 "comple.y"
{ code(add); }
break;
case 25:
#line 81 "comple.y"
{ code(sub); }
break;
case 26:
#line 82 "comple.y"
{ code(mul); }
break;
case 27:
#line 83 "comple.y"
{ code(divi); }
break;
case 28:
#line 84 "comple.y"
{ code(power); }
break;
case 29:
#line 85 "comple.y"
{ yyval.inst=yyvsp[-1].inst; }
break;
case 30:
#line 86 "comple.y"
{ code(gt); }
break;
case 31:
#line 87 "comple.y"
{ code(ge); }
break;
case 32:
#line 88 "comple.y"
{ code(lt); }
break;
case 33:
#line 89 "comple.y"
{ code(le); }
break;
case 34:
#line 90 "comple.y"
{ code(eq); }
break;
case 35:
#line 91 "comple.y"
{ code(ne); }
break;
case 36:
#line 92 "comple.y"
{ code(and); }
break;
case 37:
#line 93 "comple.y"
{ code(or); }
break;
case 38:
#line 94 "comple.y"
{ yyval.inst = yyvsp[0].inst; code(not); }
break;
#line 774 "y.tab.c"
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
