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
  int indef;
  void yyerror (char *s);
  int yylex ();
  int follow();
  int init();
  void warning(char *s, char *t);
  void execerror(char *s, char *t);
#line 18 "comple.y"
typedef union {
  Inst *inst;
  Symbol *sym;
  int narg; 
} YYSTYPE;
#line 27 "y.tab.c"
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
#define FOR 275
#define PROCEDURE 276
#define RETURN 277
#define PROC 278
#define FUNC 279
#define FUNCTION 280
#define ARG 281
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    0,    0,    0,   13,   14,   13,   15,
   13,    3,    3,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,    7,   11,   11,   11,    2,    2,    2,
    9,    9,    8,    5,    6,   12,    1,    1,    1,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
};
short yylen[] = {                                         2,
    0,    2,    3,    3,    3,    3,    0,    0,    6,    0,
    6,    3,    3,    1,    2,    4,    4,    7,   12,    3,
    1,    2,    5,    0,    0,    2,    2,    0,    1,    3,
    3,    1,    0,    1,    1,    1,    1,    1,    1,    1,
    1,    4,    1,    5,    1,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    2,
};
short yydefred[] = {                                      1,
    0,    0,   40,    0,    0,   34,   35,    0,   36,   24,
    0,    0,    0,   24,    0,    2,    0,   25,    0,    0,
    0,    0,    0,    0,    0,   45,    0,    0,    0,    0,
    0,    0,   37,   39,   38,    8,   10,    0,    0,    0,
    0,    3,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    4,    0,    0,    0,    0,
    5,   25,    6,    0,    0,    0,    0,    0,    0,    0,
   51,   26,   20,    0,   27,    0,    0,    0,    0,    0,
    0,    0,   52,   53,   54,   55,   56,   57,    0,   33,
   33,    0,   42,    0,    0,    0,    0,    0,    0,   16,
    0,    0,   23,    0,    0,    0,   44,    0,    0,    0,
    9,   11,   33,    0,   18,   25,    0,    0,    0,   33,
   19,
};
short yydgoto[] = {                                       1,
   36,   94,   26,   74,   21,   22,   31,  100,   59,   75,
   41,   24,   25,   67,   68,
};
short yysindex[] = {                                      0,
  558,  -38,    0,  -58,  -34,    0,    0,  -38,    0,    0,
  -38, -264, -264,    0,  -50,    0,  -38,    0,   18,  150,
   33,   33,   19,   -1,   32,    0, -244,  -38,  -38,  918,
    4,  918,    0,    0,    0,    0,    0,    5,  -38,  870,
  581,    0,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
  -38,  -38,  -38,  -38,  -38,    0,  -38,  918,  628,  628,
    0,    0,    0,  918,  896,  -38,    7,    8,  -38,  918,
    0,    0,    0,  918,    0,  918,  299,  299, -186, -186,
 -159, -244,    0,    0,    0,    0,    0,    0,  907,    0,
    0,  610,    0,  -36,  918,    9,   10,  -31,    0,    0,
 -227,   -7,    0,  -38,  628,  628,    0,  628,   33,  918,
    0,    0,    0,   -6,    0,    0,  610,   13,  628,    0,
    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,  -10,    0,    0,    0,    0,    0,    0,
   87,    0,    0,    0,   15,    0,    0,    0,  931,    0,
    0,    0,    0,    0,    0,    0,   51,    0,    0,  518,
    0,  540,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  742,    0,    0,
    0,    0,    0,  448,    0,  -18,    0,    0,  -18,  472,
    0,    0,    0,  654,    0,  494,  380,  416,  174,  358,
  112,   76,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   11,    0,    0,  -17,    0,    0,    0,  824,    0,
  717,    0,    0,    0,    0,    0,    0,    0,    0,   -3,
    0,    0,    0,    0,    0,    0,   23,    0,    0,    0,
    0,
};
short yygindex[] = {                                      0,
   54,   12,   67, 1197,    0,    0,   55,  -77,  -21,    6,
  -53,    0,    0,    0,    0,
};
#define YYTABLESIZE 1306
short yytable[] = {                                      41,
   60,   17,   28,   33,  103,   29,   23,  104,   92,  107,
   39,   34,  104,  101,  102,   35,   50,   51,   52,   53,
   54,   55,   28,   29,   43,   28,   29,   42,   61,   41,
   41,   41,   41,   41,   41,  115,   41,   30,   62,  118,
   30,   63,  121,   66,   69,  108,   96,   97,   41,  105,
  106,  109,  116,  119,   43,   43,   43,   43,   43,   43,
   60,   43,  117,   33,   90,   91,   37,   19,   38,   33,
   48,   49,   57,   43,   50,   51,   52,   53,   54,   55,
   98,    0,    0,   41,    0,   58,    0,  114,    0,    0,
   60,   60,   60,   60,   60,   60,   21,   60,   49,    0,
    0,   50,   51,   52,   53,   54,   55,    0,   43,   60,
  111,  112,   41,  113,   41,   58,   58,   58,   58,   58,
   58,   59,   58,    0,  120,    0,    0,   21,    0,    0,
    0,    0,    0,    0,   58,    0,    0,   43,    0,   43,
    0,    0,    0,    0,   60,   21,    0,    0,    0,    0,
    0,   59,   59,   59,   59,   59,   59,    0,   59,   56,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   58,
   59,    0,    0,   60,    0,   60,    0,    0,    0,    0,
    0,    0,    0,   48,    0,    0,    0,    0,    0,    0,
    0,   46,   44,    0,   45,    0,   47,    0,   58,    0,
   58,    0,    0,    0,    0,   59,    0,    0,    0,   21,
    0,   21,    0,   48,   48,   48,   48,   48,   48,    0,
   48,    2,    0,    0,    0,    0,    0,    0,    3,    4,
    5,    0,   48,    0,   59,    0,   59,    0,    0,    0,
    0,   14,   15,   43,    0,    0,   41,   41,    0,   41,
   41,   41,   41,   41,   41,   41,   41,   41,   41,    0,
   41,   41,   41,   41,   41,   41,   41,   48,    0,   41,
   41,   43,   43,    0,   43,   43,   43,   43,   43,   43,
   43,   43,   43,   43,    0,   43,   43,   43,   43,   43,
   43,   43,    2,    0,   43,   43,   48,    0,   48,    3,
    4,    5,    0,    0,    0,    0,    0,   60,   60,    0,
   60,    0,   14,   15,    0,    0,    0,   60,   60,   60,
    0,   60,   60,   60,   60,   60,   60,   60,    0,    0,
   60,   60,   58,   58,    0,   58,    0,    0,    0,    0,
   46,    0,   58,   58,   58,   47,   58,   58,   58,   58,
   58,   58,   58,    0,    0,   58,   58,   21,   21,   21,
   21,   21,   21,   21,    0,    0,    0,   49,   59,    0,
    0,   59,    0,    0,    0,    0,    0,    0,   59,   59,
   59,    0,   59,   59,   59,   59,   59,   59,   59,   46,
    0,   59,   59,    0,    0,    0,    0,   49,   49,   49,
   49,   49,   49,    0,   49,    0,   48,   49,    0,    0,
   50,   51,   52,   53,   54,   55,   49,    0,    0,   46,
   46,    0,   46,   46,   46,   47,    0,    0,    0,    0,
    0,    0,    0,   48,    0,    0,    0,    0,   46,    0,
   48,   48,   48,    0,   48,   48,   48,   48,   48,   48,
   48,   49,    0,   48,   48,   47,   47,   12,   47,   47,
   47,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   46,   47,    0,    0,    0,    0,    0,
   49,   13,   49,    0,    0,    0,    0,   12,   12,    0,
    0,   12,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   46,   50,   46,    0,   12,    0,    0,   47,
    0,   13,   13,    0,    0,   13,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   15,    0,    0,
   13,    0,    0,   50,   50,    0,    0,   50,   47,    0,
   47,    0,    0,    0,    0,    0,    0,    0,    0,   22,
    0,    0,   50,    0,    0,   48,   49,   15,   15,   50,
   51,   52,   53,   54,   55,    0,    0,   16,    0,    0,
   12,    0,   12,    0,    0,    0,   15,    0,    0,   22,
   22,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   72,    0,    0,    0,   13,    0,   13,   17,   22,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   50,   49,   50,   72,
   17,    0,    0,    0,   49,   49,   49,    0,   49,   49,
   49,   49,   49,   49,   49,    0,    0,   49,   49,   46,
   15,    0,   15,    0,    0,    0,   46,   46,   46,   17,
   46,   46,   46,   46,   46,   46,   46,    0,    0,   46,
   46,    0,   22,   14,   22,    0,    0,   17,    0,    0,
    0,    0,    0,    0,    0,   47,    0,    0,    0,    0,
   18,    0,   47,   47,   47,    0,   47,   47,   47,   47,
   47,   47,   47,   14,   14,   47,   47,    0,    0,    0,
    0,    0,    0,   18,    0,   73,    0,   12,    0,    0,
    0,    0,   14,    0,   12,   12,   12,    0,   12,   12,
   12,   12,   12,   12,   12,    0,   17,   12,   12,    0,
    0,   13,   18,    0,    0,    0,    0,    0,   13,   13,
   13,    0,   13,   13,   13,   13,   13,   13,   13,    0,
   18,   13,   13,   50,    0,    0,   17,   17,    0,    0,
   50,   50,   50,    0,   50,   50,   50,   50,   50,   50,
   50,    0,    0,   50,   50,   17,   14,   15,   14,    0,
    0,   32,    0,    0,   15,   15,   15,    0,   15,   15,
   15,   15,   15,   15,   15,    0,    0,   15,   15,   22,
   32,    0,    0,    0,    0,    0,   22,   22,   22,    0,
   22,   22,   22,   22,   22,   22,   22,    2,    0,   22,
   22,    0,    0,    0,    3,    4,    5,    0,    6,    7,
    0,    8,    9,   10,   11,   12,   13,   14,   15,   17,
    2,   17,    0,    0,    0,    0,    0,    3,    4,    5,
    0,    6,    7,    0,    8,    9,   10,   11,    0,    0,
   14,   15,    0,   31,   32,   51,   51,    0,   51,    2,
   51,    0,    0,    0,    0,    0,    3,    4,    5,    0,
    6,    7,   31,    8,    9,   10,   11,    2,    0,   14,
   15,    0,    0,    0,    3,    4,    5,    0,    6,    7,
    0,    8,    9,   10,   11,    0,    0,   14,   15,    0,
   71,   46,   44,   14,   45,    0,   47,   51,    0,    0,
   14,   14,   14,    0,   14,   14,   14,   14,   14,   14,
   14,    0,    0,   14,   14,    0,   93,   46,   44,    0,
   45,    0,   47,    0,    0,    0,   31,   99,   46,   44,
    0,   45,    0,   47,    0,    0,    0,    0,    0,   46,
   44,    0,   45,   43,   47,    0,    0,    0,    0,    0,
    0,    0,   45,   45,    0,   45,   17,   45,    0,    0,
    0,    0,    0,   17,   17,   17,    0,   17,   17,   43,
   17,   17,   17,   17,    0,    0,   17,   17,    0,    0,
   43,   32,    0,    0,    0,    0,    0,    0,   32,   32,
   32,   43,   32,   32,    0,   32,   32,   32,   32,    0,
    0,   32,   32,    0,   45,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   51,   51,    0,   31,   51,   51,   51,   51,   51,   51,
   31,   31,   31,    0,   31,   31,    0,   31,   31,   31,
   31,    0,    0,   31,   31,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   48,   49,    0,    0,
   50,   51,   52,   53,   54,   55,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   48,   49,    0,    0,   50,   51,   52,   53,
   54,   55,    0,   48,   49,    0,    0,   50,   51,   52,
   53,   54,   55,    0,   48,   49,    0,    0,   50,   51,
   52,   53,   54,   55,    0,    0,    0,   45,   45,    0,
    0,   45,   45,   45,   45,   45,   45,   20,   27,    0,
    0,    0,    0,    0,   30,    0,    0,   32,    0,    0,
    0,    0,    0,   40,    0,    0,    0,   58,   58,    0,
    0,    0,    0,    0,   64,   65,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   70,    0,    0,    0,   76,
   77,   78,   79,   80,   81,   82,   83,   84,   85,   86,
   87,   88,    0,   89,    0,    0,    0,    0,    0,    0,
    0,    0,   95,    0,    0,   95,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  110,    0,    0,    0,    0,   58,
};
short yycheck[] = {                                      10,
   22,   40,   61,  268,   41,   40,    1,   44,   62,   41,
   61,  276,   44,   91,   92,  280,  261,  262,  263,  264,
  265,  266,   41,   41,   10,   44,   44,   10,   10,   40,
   41,   42,   43,   44,   45,  113,   47,   41,   40,  117,
   44,   10,  120,   40,   40,  273,   40,   40,   59,   41,
   41,   59,   59,   41,   40,   41,   42,   43,   44,   45,
   10,   47,  116,   41,   59,   60,   13,    1,   14,   59,
  257,  258,   40,   59,  261,  262,  263,  264,  265,  266,
   69,   -1,   -1,   94,   -1,   10,   -1,  109,   -1,   -1,
   40,   41,   42,   43,   44,   45,   10,   47,  258,   -1,
   -1,  261,  262,  263,  264,  265,  266,   -1,   94,   59,
  105,  106,  123,  108,  125,   40,   41,   42,   43,   44,
   45,   10,   47,   -1,  119,   -1,   -1,   41,   -1,   -1,
   -1,   -1,   -1,   -1,   59,   -1,   -1,  123,   -1,  125,
   -1,   -1,   -1,   -1,   94,   59,   -1,   -1,   -1,   -1,
   -1,   40,   41,   42,   43,   44,   45,   -1,   47,   10,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   94,
   59,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   42,   43,   -1,   45,   -1,   47,   -1,  123,   -1,
  125,   -1,   -1,   -1,   -1,   94,   -1,   -1,   -1,  123,
   -1,  125,   -1,   40,   41,   42,   43,   44,   45,   -1,
   47,  260,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,   -1,   59,   -1,  123,   -1,  125,   -1,   -1,   -1,
   -1,  280,  281,   94,   -1,   -1,  257,  258,   -1,  260,
  261,  262,  263,  264,  265,  266,  267,  268,  269,   -1,
  271,  272,  273,  274,  275,  276,  277,   94,   -1,  280,
  281,  257,  258,   -1,  260,  261,  262,  263,  264,  265,
  266,  267,  268,  269,   -1,  271,  272,  273,  274,  275,
  276,  277,  260,   -1,  280,  281,  123,   -1,  125,  267,
  268,  269,   -1,   -1,   -1,   -1,   -1,  257,  258,   -1,
  260,   -1,  280,  281,   -1,   -1,   -1,  267,  268,  269,
   -1,  271,  272,  273,  274,  275,  276,  277,   -1,   -1,
  280,  281,  257,  258,   -1,  260,   -1,   -1,   -1,   -1,
   42,   -1,  267,  268,  269,   47,  271,  272,  273,  274,
  275,  276,  277,   -1,   -1,  280,  281,  271,  272,  273,
  274,  275,  276,  277,   -1,   -1,   -1,   10,  257,   -1,
   -1,  260,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,   -1,  271,  272,  273,  274,  275,  276,  277,   10,
   -1,  280,  281,   -1,   -1,   -1,   -1,   40,   41,   42,
   43,   44,   45,   -1,   47,   -1,  257,  258,   -1,   -1,
  261,  262,  263,  264,  265,  266,   59,   -1,   -1,   40,
   41,   -1,   43,   44,   45,   10,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  260,   -1,   -1,   -1,   -1,   59,   -1,
  267,  268,  269,   -1,  271,  272,  273,  274,  275,  276,
  277,   94,   -1,  280,  281,   40,   41,   10,   43,   44,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   94,   59,   -1,   -1,   -1,   -1,   -1,
  123,   10,  125,   -1,   -1,   -1,   -1,   40,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  123,   10,  125,   -1,   59,   -1,   -1,   94,
   -1,   40,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   10,   -1,   -1,
   59,   -1,   -1,   40,   41,   -1,   -1,   44,  123,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   10,
   -1,   -1,   59,   -1,   -1,  257,  258,   40,   41,  261,
  262,  263,  264,  265,  266,   -1,   -1,   10,   -1,   -1,
  123,   -1,  125,   -1,   -1,   -1,   59,   -1,   -1,   40,
   41,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   10,   -1,   -1,   -1,  123,   -1,  125,   40,   59,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  123,  260,  125,   10,
   40,   -1,   -1,   -1,  267,  268,  269,   -1,  271,  272,
  273,  274,  275,  276,  277,   -1,   -1,  280,  281,  260,
  123,   -1,  125,   -1,   -1,   -1,  267,  268,  269,   40,
  271,  272,  273,  274,  275,  276,  277,   -1,   -1,  280,
  281,   -1,  123,   10,  125,   -1,   -1,   40,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  260,   -1,   -1,   -1,   -1,
  123,   -1,  267,  268,  269,   -1,  271,  272,  273,  274,
  275,  276,  277,   40,   41,  280,  281,   -1,   -1,   -1,
   -1,   -1,   -1,  123,   -1,  125,   -1,  260,   -1,   -1,
   -1,   -1,   59,   -1,  267,  268,  269,   -1,  271,  272,
  273,  274,  275,  276,  277,   -1,   10,  280,  281,   -1,
   -1,  260,  123,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,   -1,  271,  272,  273,  274,  275,  276,  277,   -1,
  123,  280,  281,  260,   -1,   -1,   40,   41,   -1,   -1,
  267,  268,  269,   -1,  271,  272,  273,  274,  275,  276,
  277,   -1,   -1,  280,  281,   59,  123,  260,  125,   -1,
   -1,   40,   -1,   -1,  267,  268,  269,   -1,  271,  272,
  273,  274,  275,  276,  277,   -1,   -1,  280,  281,  260,
   59,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,   -1,
  271,  272,  273,  274,  275,  276,  277,  260,   -1,  280,
  281,   -1,   -1,   -1,  267,  268,  269,   -1,  271,  272,
   -1,  274,  275,  276,  277,  278,  279,  280,  281,  123,
  260,  125,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,
   -1,  271,  272,   -1,  274,  275,  276,  277,   -1,   -1,
  280,  281,   -1,   40,  123,   42,   43,   -1,   45,  260,
   47,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,   -1,
  271,  272,   59,  274,  275,  276,  277,  260,   -1,  280,
  281,   -1,   -1,   -1,  267,  268,  269,   -1,  271,  272,
   -1,  274,  275,  276,  277,   -1,   -1,  280,  281,   -1,
   41,   42,   43,  260,   45,   -1,   47,   94,   -1,   -1,
  267,  268,  269,   -1,  271,  272,  273,  274,  275,  276,
  277,   -1,   -1,  280,  281,   -1,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,  123,   41,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   42,
   43,   -1,   45,   94,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   42,   43,   -1,   45,  260,   47,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,   -1,  271,  272,   94,
  274,  275,  276,  277,   -1,   -1,  280,  281,   -1,   -1,
   94,  260,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,   94,  271,  272,   -1,  274,  275,  276,  277,   -1,
   -1,  280,  281,   -1,   94,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,   -1,  260,  261,  262,  263,  264,  265,  266,
  267,  268,  269,   -1,  271,  272,   -1,  274,  275,  276,
  277,   -1,   -1,  280,  281,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,   -1,   -1,
  261,  262,  263,  264,  265,  266,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,   -1,   -1,  261,  262,  263,  264,
  265,  266,   -1,  257,  258,   -1,   -1,  261,  262,  263,
  264,  265,  266,   -1,  257,  258,   -1,   -1,  261,  262,
  263,  264,  265,  266,   -1,   -1,   -1,  257,  258,   -1,
   -1,  261,  262,  263,  264,  265,  266,    1,    2,   -1,
   -1,   -1,   -1,   -1,    8,   -1,   -1,   11,   -1,   -1,
   -1,   -1,   -1,   17,   -1,   -1,   -1,   21,   22,   -1,
   -1,   -1,   -1,   -1,   28,   29,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   39,   -1,   -1,   -1,   43,
   44,   45,   46,   47,   48,   49,   50,   51,   52,   53,
   54,   55,   -1,   57,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   66,   -1,   -1,   69,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  104,   -1,   -1,   -1,   -1,  109,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 281
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,0,"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"OR","AND","UNARYMINUS","NOT","GT","GE","LT","LE","EQ","NE",
"CNUMBER","VAR","BLTIN","INDEF","WHILE","IF","ELSE","PRINT","FOR","PROCEDURE",
"RETURN","PROC","FUNC","FUNCTION","ARG",
};
char *yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list asgn '\\n'",
"list : list exp '\\n'",
"list : list stmt '\\n'",
"list : list defn '\\n'",
"defn :",
"$$1 :",
"defn : PROC procname $$1 '(' ')' stmt",
"$$2 :",
"defn : FUNC procname $$2 '(' ')' stmt",
"asgn : VAR '=' exp",
"asgn : ARG '=' exp",
"stmt : exp",
"stmt : PRINT exp",
"stmt : while cond stmt end",
"stmt : if cond stmt end",
"stmt : if cond stmt end ELSE stmt end",
"stmt : for '(' stmtlist end ';' cond ';' stmtlist end ')' stmt end",
"stmt : '{' stmtlist '}'",
"stmt : RETURN",
"stmt : RETURN exp",
"stmt : PROCEDURE begin '(' arglist ')'",
"begin :",
"stmtlist :",
"stmtlist : stmtlist '\\n'",
"stmtlist : stmtlist stmt",
"arglist :",
"arglist : exp",
"arglist : arglist ',' exp",
"cond : '(' exp ')'",
"cond : exp",
"end :",
"while : WHILE",
"if : IF",
"for : FOR",
"procname : VAR",
"procname : FUNCTION",
"procname : PROCEDURE",
"exp : CNUMBER",
"exp : VAR",
"exp : BLTIN '(' exp ')'",
"exp : ARG",
"exp : FUNCTION begin '(' arglist ')'",
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
#line 143 "comple.y"

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
    execute(progbase);
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
  if (c == '$') { 
    int n = 0; 
    while (isdigit(c=getchar()))
      n = 10 * n + c - '0'; 
    ungetc(c, stdin); 
    if (n == 0) puts("strange $... 0"); 
    yylval.narg = n; 
    return ARG;
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

void defnonly( char *s ){     /* advertena la si hay definición i legal */
  if (!indef) puts("used outside definition"); 
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
"proc" ,  PROC,
"func" ,  FUNC,
"return", RETURN,
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
#line 681 "y.tab.c"
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
#line 43 "comple.y"
{ code2(pop, STOP); return 1; }
break;
case 4:
#line 44 "comple.y"
{ code2(print, STOP); return 1;}
break;
case 5:
#line 45 "comple.y"
{ code(STOP); return 1; }
break;
case 8:
#line 50 "comple.y"
{ yyvsp[0].sym->type=PROCEDURE; indef=1; }
break;
case 9:
#line 51 "comple.y"
{ code(procret); define(yyvsp[-4].sym); indef=0; }
break;
case 10:
#line 52 "comple.y"
{ yyvsp[0].sym->type=FUNCTION; indef=1; }
break;
case 11:
#line 53 "comple.y"
{ code(procret); define(yyvsp[-4].sym); indef=0; }
break;
case 12:
#line 56 "comple.y"
{ yyval.inst=yyvsp[0].inst; code3(varpush, (Inst)yyvsp[-2].sym, assign);}
break;
case 13:
#line 57 "comple.y"
{ defnonly("$"); code2(argassign,(Inst)yyvsp[-2].narg); yyval.inst=yyvsp[0].inst;}
break;
case 14:
#line 60 "comple.y"
{ code(pop); }
break;
case 15:
#line 61 "comple.y"
{ code(prexpr); yyval.inst = yyvsp[0].inst;}
break;
case 16:
#line 62 "comple.y"
{ (yyvsp[-3].inst)[1] = (Inst)yyvsp[-1].inst;     /* cuerpo de la iteración */ 
                          (yyvsp[-3].inst)[2] = (Inst)yyvsp[0].inst; }
break;
case 17:
#line 64 "comple.y"
{   /* proposición if que no emplea else */ 
                          (yyvsp[-3].inst)[1] = (Inst)yyvsp[-1].inst;     /* parte then */ 
                          (yyvsp[-3].inst)[3] = (Inst)yyvsp[0].inst; }
break;
case 18:
#line 67 "comple.y"
{  /* proposición if con parte else */
                          (yyvsp[-6].inst)[1]   =   (Inst)yyvsp[-4].inst; /*  parte then  */
                          (yyvsp[-6].inst)[2]   =   (Inst)yyvsp[-1].inst; /* parte else   */
                          (yyvsp[-6].inst)[3]   =   (Inst)yyvsp[0].inst;
                        }
break;
case 19:
#line 73 "comple.y"
{
                          (yyvsp[-11].inst)[1] = (Inst)yyvsp[-6].inst; /*condicional*/
                          (yyvsp[-11].inst)[2] = (Inst)yyvsp[-4].inst; /*instruciones finales*/ 
                          (yyvsp[-11].inst)[3] = (Inst)yyvsp[-1].inst; /*cuerpo si cumple*/
                          (yyvsp[-11].inst)[4] = (Inst)yyvsp[0].inst; /* final del for*/ 
                        }
break;
case 20:
#line 79 "comple.y"
{ yyval.inst  =  yyvsp[-1].inst; }
break;
case 21:
#line 80 "comple.y"
{ defnonly("return"); code(procret); }
break;
case 22:
#line 81 "comple.y"
{ defnonly("return"); yyval.inst=yyvsp[0].inst; code(funcret); }
break;
case 23:
#line 82 "comple.y"
{ yyval.inst = yyvsp[-3].inst; code3(call, (Inst)yyvsp[-4].sym, (Inst)yyvsp[-1].narg); }
break;
case 24:
#line 85 "comple.y"
{ yyval.inst = progp; }
break;
case 25:
#line 88 "comple.y"
{ yyval.inst = progp; }
break;
case 28:
#line 93 "comple.y"
{ yyval.narg = 0; }
break;
case 29:
#line 94 "comple.y"
{ yyval.narg = 1; }
break;
case 30:
#line 95 "comple.y"
{ yyval.narg = yyvsp[-2].narg + 1; }
break;
case 31:
#line 98 "comple.y"
{ code(STOP);  yyval.inst= yyvsp[-1].inst;}
break;
case 32:
#line 99 "comple.y"
{ code(STOP);  yyval.inst= yyvsp[0].inst;}
break;
case 33:
#line 102 "comple.y"
{ code(STOP); yyval.inst = progp; }
break;
case 34:
#line 105 "comple.y"
{ yyval.inst=code3(whilecode,STOP,STOP);}
break;
case 35:
#line 108 "comple.y"
{ yyval.inst=code(ifcode); code3(STOP, STOP, STOP); }
break;
case 36:
#line 111 "comple.y"
{ yyval.inst=code(forcode); code(STOP); code3(STOP,STOP,STOP);}
break;
case 40:
#line 119 "comple.y"
{ yyval.inst=code2(constpush, (Inst)yyvsp[0].sym); }
break;
case 41:
#line 120 "comple.y"
{ yyval.inst=code3(varpush, (Inst)yyvsp[0].sym, eval);}
break;
case 42:
#line 121 "comple.y"
{ yyval.inst=code2(bltin, (Inst)yyvsp[-3].sym->u.ptr);}
break;
case 43:
#line 122 "comple.y"
{ defnonly("$"); yyval.inst = code2(arg, (Inst)yyvsp[0].narg); }
break;
case 44:
#line 124 "comple.y"
{ yyval.inst = yyvsp[-3].inst; code3(call,(Inst)yyvsp[-4].sym,(Inst)yyvsp[-1].narg); }
break;
case 46:
#line 126 "comple.y"
{ code(add); }
break;
case 47:
#line 127 "comple.y"
{ code(sub); }
break;
case 48:
#line 128 "comple.y"
{ code(mul); }
break;
case 49:
#line 129 "comple.y"
{ code(divi); }
break;
case 50:
#line 130 "comple.y"
{ code(power); }
break;
case 51:
#line 131 "comple.y"
{ yyval.inst=yyvsp[-1].inst; }
break;
case 52:
#line 132 "comple.y"
{ code(gt); }
break;
case 53:
#line 133 "comple.y"
{ code(ge); }
break;
case 54:
#line 134 "comple.y"
{ code(lt); }
break;
case 55:
#line 135 "comple.y"
{ code(le); }
break;
case 56:
#line 136 "comple.y"
{ code(eq); }
break;
case 57:
#line 137 "comple.y"
{ code(ne); }
break;
case 58:
#line 138 "comple.y"
{ code(and); }
break;
case 59:
#line 139 "comple.y"
{ code(or); }
break;
case 60:
#line 140 "comple.y"
{ yyval.inst = yyvsp[0].inst; code(not); }
break;
#line 1033 "y.tab.c"
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
