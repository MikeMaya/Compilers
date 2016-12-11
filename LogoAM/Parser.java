//### This file created by BYACC 1.8(/Java extension  1.15)
//### Java capabilities added 7 Jan 97, Bob Jamison
//### Updated : 27 Nov 97  -- Bob Jamison, Joe Nieten
//###           01 Jan 98  -- Bob Jamison -- fixed generic semantic constructor
//###           01 Jun 99  -- Bob Jamison -- added Runnable support
//###           06 Aug 00  -- Bob Jamison -- made state variables class-global
//###           03 Jan 01  -- Bob Jamison -- improved flags, tracing
//###           16 May 01  -- Bob Jamison -- added custom stack sizing
//###           04 Mar 02  -- Yuval Oren  -- improved java performance, added options
//###           14 Mar 02  -- Tomas Hurka -- -d support, static initializer workaround
//### Please send bug reports to tom@hukatronic.cz
//### static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";






//#line 2 "logo.y"
	import java.lang.Math;
	import java.io.*;
	import java.util.StringTokenizer;
//#line 21 "Parser.java"




public class Parser
{

boolean yydebug;        //do I want debug output?
int yynerrs;            //number of errors so far
int yyerrflag;          //was there an error?
int yychar;             //the current working character

//########## MESSAGES ##########
//###############################################################
// method: debug
//###############################################################
void debug(String msg)
{
  if (yydebug)
    System.out.println(msg);
}

//########## STATE STACK ##########
final static int YYSTACKSIZE = 500;  //maximum stack size
int statestk[] = new int[YYSTACKSIZE]; //state stack
int stateptr;
int stateptrmax;                     //highest index of stackptr
int statemax;                        //state when highest index reached
//###############################################################
// methods: state stack push,pop,drop,peek
//###############################################################
final void state_push(int state)
{
  try {
		stateptr++;
		statestk[stateptr]=state;
	 }
	 catch (ArrayIndexOutOfBoundsException e) {
     int oldsize = statestk.length;
     int newsize = oldsize * 2;
     int[] newstack = new int[newsize];
     System.arraycopy(statestk,0,newstack,0,oldsize);
     statestk = newstack;
     statestk[stateptr]=state;
  }
}
final int state_pop()
{
  return statestk[stateptr--];
}
final void state_drop(int cnt)
{
  stateptr -= cnt; 
}
final int state_peek(int relative)
{
  return statestk[stateptr-relative];
}
//###############################################################
// method: init_stacks : allocate and prepare stacks
//###############################################################
final boolean init_stacks()
{
  stateptr = -1;
  val_init();
  return true;
}
//###############################################################
// method: dump_stacks : show n levels of the stacks
//###############################################################
void dump_stacks(int count)
{
int i;
  System.out.println("=index==state====value=     s:"+stateptr+"  v:"+valptr);
  for (i=0;i<count;i++)
    System.out.println(" "+i+"    "+statestk[i]+"      "+valstk[i]);
  System.out.println("======================");
}


//########## SEMANTIC VALUES ##########
//public class ParserVal is defined in ParserVal.java


String   yytext;//user variable to return contextual strings
ParserVal yyval; //used to return semantic vals from action routines
ParserVal yylval;//the 'lval' (result) I got from yylex()
ParserVal valstk[];
int valptr;
//###############################################################
// methods: value stack push,pop,drop,peek.
//###############################################################
void val_init()
{
  valstk=new ParserVal[YYSTACKSIZE];
  yyval=new ParserVal();
  yylval=new ParserVal();
  valptr=-1;
}
void val_push(ParserVal val)
{
  if (valptr>=YYSTACKSIZE)
    return;
  valstk[++valptr]=val;
}
ParserVal val_pop()
{
  if (valptr<0)
    return new ParserVal();
  return valstk[valptr--];
}
void val_drop(int cnt)
{
int ptr;
  ptr=valptr-cnt;
  if (ptr<0)
    return;
  valptr = ptr;
}
ParserVal val_peek(int relative)
{
int ptr;
  ptr=valptr-relative;
  if (ptr<0)
    return new ParserVal();
  return valstk[ptr];
}
final ParserVal dup_yyval(ParserVal val)
{
  ParserVal dup = new ParserVal();
  dup.ival = val.ival;
  dup.dval = val.dval;
  dup.sval = val.sval;
  dup.obj = val.obj;
  return dup;
}
//#### end semantic value section ####
public final static short IF=257;
public final static short ELSE=258;
public final static short WHILE=259;
public final static short FOR=260;
public final static short EQ=261;
public final static short NE=262;
public final static short GT=263;
public final static short LT=264;
public final static short GE=265;
public final static short LE=266;
public final static short FNCT=267;
public final static short NUMBER=268;
public final static short VAR=269;
public final static short AND=270;
public final static short OR=271;
public final static short FUNC=272;
public final static short RETURN=273;
public final static short PARAMETRO=274;
public final static short PROC=275;
public final static short YYERRCODE=256;
final static short yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    5,    5,
    5,    6,    3,    3,    3,    3,    3,    3,    3,   15,
   14,   12,    4,   13,    8,    7,    9,   10,   11,   11,
   11,
};
final static short yylen[] = {                            2,
    0,    2,    3,    2,    1,    3,    2,    1,    1,    3,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    2,    1,    4,    0,    1,
    3,    0,   14,   11,   10,   16,    8,    8,    5,    1,
    1,    1,    1,    0,    0,    1,    1,    1,    0,    1,
    3,
};
final static short yydefred[] = {                         1,
    0,   46,   47,   48,   40,    9,    0,   42,    0,   27,
   41,    0,    0,    2,    0,    0,    0,    5,    0,    0,
    0,    0,    0,    0,    0,    0,   26,    0,    0,    0,
    3,    0,    7,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    4,    0,    0,    0,    0,
   43,    0,    0,    0,    0,   16,    6,    0,    0,    0,
    0,    0,    0,    0,   24,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   28,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   39,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   37,   38,
    0,   45,    0,    0,   45,   35,    0,    0,   34,    0,
    0,    0,    0,    0,   33,    0,   45,   36,
};
final static short yydgoto[] = {                          1,
   16,   17,   18,   19,   71,  115,   20,   81,   21,   22,
   75,   23,  104,   24,   25,
};
final static short yysindex[] = {                         0,
    9,    0,    0,    0,    0,    0,  -51,    0,  -13,    0,
    0,  -13,  -13,    0,  -13,   28,   75,    0,  -18,  -14,
   -9,   -3, -245, -245,   -1,  -13,    0,  108, -224,   54,
    0,   86,    0,  -13,  -13,  -13,  -13,  -13,  -13,  -13,
  -13,  -13,  -13,  -13,  -13,    0,  -13,  -13,  -13,  -13,
    0,   13,   23,  -13,   97,    0,    0,  224,  160,  205,
 -237, -166, -224, -206,    0,  108,  108,  202,  202,   97,
   16,   97,   97,   97,   25,   40,   52,   18,    0,  -13,
   62,   73,  -13,   30,   -4,   -2,   71,   97,   14,   24,
   97,  -13,  -32,  -32,    0,  -32,  -32,   97,  -32,  -32,
  -32,  -32,   77,   26,   27,   34,   51,  -13,    0,    0,
 -126,    0,   25,   42,    0,    0,  107,  -32,    0,   56,
  -32,  -32,   74,  -32,    0,   88,    0,    0,
};
final static short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,   43,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    7,  119,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   38,    0,    0,  -42,
    0,    0,    0,   38,  -16,    0,    0,   33,  -38,  159,
  139,  146,  126,   65,    0,   82,  113,  167,  415,   50,
    0,  134,  134,   94,   90,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   72,    0,    0,
  133,    0,    0,    0,    0,    0,    0,   90,   92,   92,
   96,   96,    0,    0,    0,    0,    0,  102,    0,    0,
  -10,    0,  134,    0,    0,    0,    0,    0,    0,    0,
   96,    0,    0,   96,    0,    0,    0,    0,
};
final static short yygindex[] = {                         0,
  -82,  401,   95,   48,  153,    0,    0,  -57,    0,    0,
  112,    0,  115,    0,    0,
};
final static int YYTABLESIZE=525;
static short yytable[];
static { yytable();}
static void yytable(){
yytable = new short[]{                         32,
   13,   49,   18,   18,   18,   18,   18,   15,   18,   26,
   99,  100,   12,  101,  102,   82,   49,   84,   14,   13,
   18,   47,   32,   51,   10,   48,   15,   10,   39,   32,
   49,   12,   40,   41,   32,  121,   50,   31,   54,  124,
  103,   13,   10,  106,  107,   40,   41,   11,   15,   11,
   11,   11,   76,   12,  116,  117,   79,  119,   87,   80,
   13,   80,   77,  123,   41,   11,  126,   15,   83,  128,
   52,   53,   12,   17,   17,   17,   17,   17,   29,   17,
   85,   29,   43,    8,    8,    8,    8,    8,   92,    8,
   30,   17,   86,   30,   56,   44,   42,   37,   43,   39,
   45,    8,   89,   40,   41,   23,   23,   23,   23,   23,
   33,   23,   31,   90,   32,   31,   44,   42,   93,   43,
   94,   45,   14,   23,   14,   14,   14,   44,   42,   95,
   43,  114,   45,   46,   50,  108,   96,   50,   44,   42,
   14,   43,   49,   45,   57,   49,   97,  120,   45,   44,
  109,  110,   50,   15,   45,   15,   15,   15,  111,   25,
   25,   25,   25,   25,  118,   25,   20,   20,   20,   20,
   20,   15,   20,   51,   45,  112,   51,   25,  122,   19,
   19,   19,   19,   19,   20,   19,   22,   22,   22,   22,
   22,   51,   22,   33,   33,   33,   33,   19,  125,   21,
   21,   21,   21,   21,   22,   21,   78,   12,   12,   12,
   12,   12,  127,   12,  105,   33,   44,   21,   33,  113,
   45,    0,   18,   18,    2,   12,    3,    4,    0,    0,
    0,    0,    0,    0,    5,    6,    7,    0,    0,    8,
    9,   10,   11,    0,    0,    0,   32,    0,   32,   32,
    0,    0,    0,    0,    6,    7,   32,   32,   32,    9,
   10,   32,   32,   32,   32,    2,    0,    3,    4,    0,
    0,    0,    0,    0,    0,    5,    6,    7,    0,    0,
    8,    9,   10,   11,    2,    0,    3,    4,    0,    0,
    0,    0,    0,   17,    5,    6,    7,    0,    0,    8,
    9,   10,   11,    8,    8,    8,    8,    8,    8,    0,
    0,    0,    8,    8,   34,   35,   36,   37,   38,   39,
    0,    0,    0,   40,   41,   23,   23,   23,   23,   23,
   23,    0,    0,    0,   23,   34,   35,   36,   37,   38,
   39,    0,    0,    0,   40,   41,   34,   35,   36,   37,
   38,   39,    0,    0,    0,   40,   41,   34,   35,   36,
   37,   38,   39,    0,    0,    0,   40,   41,   34,   35,
   36,   37,   38,   39,    0,    0,    0,   40,   41,   25,
   25,   25,   25,   25,   25,    0,   20,   20,   20,   20,
   20,   20,    0,    0,    0,    0,    0,    0,    0,   19,
   19,   19,   19,   19,    0,    0,   22,   22,   22,   27,
   22,    0,   28,   29,    0,   30,   32,    0,    0,   21,
   21,   21,   36,   37,   38,   39,   55,    0,    0,   40,
   41,    0,    0,    0,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,    0,   70,   72,   73,
   74,    0,    0,    0,   70,   13,   13,   13,   13,   13,
    0,   13,   34,   35,   36,   37,   38,   39,   37,   38,
   39,   40,   41,   13,   40,   41,    0,    0,    0,    0,
   88,    0,    0,   91,    0,   35,   36,   37,   38,   39,
    0,    0,   98,   40,   41,    0,    0,    0,    0,   32,
   32,   32,   32,    0,    0,    0,    0,    0,   74,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   32,    0,    0,   32,
};
}
static short yycheck[];
static { yycheck(); }
static void yycheck() {
yycheck = new short[] {                         10,
   33,   44,   41,   42,   43,   44,   45,   40,   47,   61,
   93,   94,   45,   96,   97,   73,   59,   75,   10,   33,
   59,   40,   33,  269,   41,   40,   40,   44,  266,   40,
   40,   45,  270,  271,   45,  118,   40,   10,   40,  122,
   98,   33,   59,  101,  102,  270,  271,   41,   40,   43,
   44,   45,   40,   45,  112,  113,   41,  115,   41,   44,
   33,   44,   40,  121,  271,   59,  124,   40,   44,  127,
   23,   24,   45,   41,   42,   43,   44,   45,   41,   47,
   41,   44,   40,   41,   42,   43,   44,   45,   59,   47,
   41,   59,   41,   44,   41,   42,   43,  264,   45,  266,
   47,   59,   41,  270,  271,   41,   42,   43,   44,   45,
   16,   47,   41,   41,  125,   44,   42,   43,  123,   45,
  123,   47,   41,   59,   43,   44,   45,   42,   43,   59,
   45,  258,   47,   59,   41,   59,  123,   44,   42,   43,
   59,   45,   41,   47,   59,   44,  123,   41,   59,   42,
  125,  125,   59,   41,   47,   43,   44,   45,  125,   41,
   42,   43,   44,   45,  123,   47,   41,   42,   43,   44,
   45,   59,   47,   41,   41,  125,   44,   59,  123,   41,
   42,   43,   44,   45,   59,   47,   41,   42,   43,   44,
   45,   59,   47,   99,  100,  101,  102,   59,  125,   41,
   42,   43,   44,   45,   59,   47,   54,   41,   42,   43,
   44,   45,  125,   47,  100,  121,  125,   59,  124,  108,
  125,   -1,  261,  262,  257,   59,  259,  260,   -1,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,
  273,  274,  275,   -1,   -1,   -1,  257,   -1,  259,  260,
   -1,   -1,   -1,   -1,  268,  269,  267,  268,  269,  273,
  274,  272,  273,  274,  275,  257,   -1,  259,  260,   -1,
   -1,   -1,   -1,   -1,   -1,  267,  268,  269,   -1,   -1,
  272,  273,  274,  275,  257,   -1,  259,  260,   -1,   -1,
   -1,   -1,   -1,  261,  267,  268,  269,   -1,   -1,  272,
  273,  274,  275,  261,  262,  263,  264,  265,  266,   -1,
   -1,   -1,  270,  271,  261,  262,  263,  264,  265,  266,
   -1,   -1,   -1,  270,  271,  261,  262,  263,  264,  265,
  266,   -1,   -1,   -1,  270,  261,  262,  263,  264,  265,
  266,   -1,   -1,   -1,  270,  271,  261,  262,  263,  264,
  265,  266,   -1,   -1,   -1,  270,  271,  261,  262,  263,
  264,  265,  266,   -1,   -1,   -1,  270,  271,  261,  262,
  263,  264,  265,  266,   -1,   -1,   -1,  270,  271,  261,
  262,  263,  264,  265,  266,   -1,  261,  262,  263,  264,
  265,  266,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,
  262,  263,  264,  265,   -1,   -1,  261,  262,  263,    9,
  265,   -1,   12,   13,   -1,   15,   16,   -1,   -1,  261,
  262,  263,  263,  264,  265,  266,   26,   -1,   -1,  270,
  271,   -1,   -1,   -1,   34,   35,   36,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   -1,   47,   48,   49,
   50,   -1,   -1,   -1,   54,   41,   42,   43,   44,   45,
   -1,   47,  261,  262,  263,  264,  265,  266,  264,  265,
  266,  270,  271,   59,  270,  271,   -1,   -1,   -1,   -1,
   80,   -1,   -1,   83,   -1,  262,  263,  264,  265,  266,
   -1,   -1,   92,  270,  271,   -1,   -1,   -1,   -1,   99,
  100,  101,  102,   -1,   -1,   -1,   -1,   -1,  108,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  121,   -1,   -1,  124,
};
}
final static short YYFINAL=1;
final static short YYMAXTOKEN=275;
final static String yyname[] = {
"end-of-file",null,null,null,null,null,null,null,null,null,"'\\n'",null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,"'!'",null,null,null,null,null,null,"'('","')'","'*'","'+'",
"','","'-'",null,"'/'",null,null,null,null,null,null,null,null,null,null,null,
"';'",null,"'='",null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,"'{'",null,"'}'",null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,"IF","ELSE","WHILE","FOR","EQ","NE",
"GT","LT","GE","LE","FNCT","NUMBER","VAR","AND","OR","FUNC","RETURN",
"PARAMETRO","PROC",
};
final static String yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list linea '\\n'",
"linea : exp ';'",
"linea : stmt",
"linea : linea exp ';'",
"linea : linea stmt",
"exp : VAR",
"exp : NUMBER",
"exp : VAR '=' exp",
"exp : '-' exp",
"exp : exp '*' exp",
"exp : exp '/' exp",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : '(' exp ')'",
"exp : exp EQ exp",
"exp : exp NE exp",
"exp : exp LT exp",
"exp : exp LE exp",
"exp : exp GT exp",
"exp : exp GE exp",
"exp : exp AND exp",
"exp : exp OR exp",
"exp : '!' exp",
"exp : RETURN exp",
"exp : PARAMETRO",
"exp : nombreProc '(' arglist ')'",
"arglist :",
"arglist : exp",
"arglist : arglist ',' exp",
"nop :",
"stmt : if_ '(' exp stop_ ')' '{' linea stop_ '}' ELSE '{' linea stop_ '}'",
"stmt : if_ '(' exp stop_ ')' '{' linea stop_ '}' nop stop_",
"stmt : while_ '(' exp stop_ ')' '{' linea stop_ '}' stop_",
"stmt : for_ '(' instrucciones stop_ ';' exp stop_ ';' instrucciones stop_ ')' '{' linea stop_ '}' stop_",
"stmt : funcion nombreProc '(' ')' '{' linea null_ '}'",
"stmt : procedimiento nombreProc '(' ')' '{' linea null_ '}'",
"stmt : instruccion '(' arglist ')' ';'",
"instruccion : FNCT",
"procedimiento : PROC",
"funcion : FUNC",
"nombreProc : VAR",
"null_ :",
"stop_ :",
"if_ : IF",
"while_ : WHILE",
"for_ : FOR",
"instrucciones :",
"instrucciones : exp",
"instrucciones : instrucciones ',' exp",
};

//#line 181 "logo.y"


String OPERADORES[] = {">=", "&&", "||", "<=","==", "!=", "=", "{", 
						"}", ",", "*", "/", "+", "-", "(", ")", "|", "[", 
						"]", ";", "!", "<", ">"};
TablaDeSimbolos tablaDeSimbolos = new TablaDeSimbolos();
MaquinaDePila maquina = new MaquinaDePila(tablaDeSimbolos);
int i = 0;
int j = 0;
double[][] auxiliar;
Funcion funcionAux;
boolean huboError;
boolean newline;

String ins;
StringTokenizer st;

void yyerror(String s){
	huboError = true;
	System.out.println("error:"+s);
    System.exit(0);
}

int yylex(){
	String s;
	int tok = 0;
	Double d;
	if (!st.hasMoreTokens()){
		if (!newline){
			newline=true;
			return '\n'; //So we look like classic YACC example
		}
		else return 0;
	}
	s = st.nextToken();
	try{
		d = Double.valueOf(s);/*this may fail*/
		yylval = new ParserVal(d.doubleValue()); //SEE BELOW
		return NUMBER;
	}
	catch (Exception e){}
	if(esVariable(s)){
		if(s.equals("proc"))	return PROC;
		if(s.charAt(0) == '$'){
			yylval = new ParserVal((int)Integer.parseInt(s.substring(1)));
			return PARAMETRO;
		}
		if(s.equals("return"))	return RETURN;
		if(s.equals("func"))	return FUNC;
		if(s.equals("if"))		return IF;
		if(s.equals("else"))	return ELSE;
		if(s.equals("while"))	return WHILE;
		if(s.equals("for"))		return FOR;

		boolean esFuncion = false;
		Object objeto = tablaDeSimbolos.encontrar(s);

		if(objeto instanceof Funcion){
			funcionAux = (Funcion)objeto;
			yylval = new ParserVal(objeto);
			esFuncion = true;
			return FNCT;
		}
		if(!esFuncion){
			yylval = new ParserVal(s);
			return VAR;
		}
	} else {
        if(s.equals("==")) 	return EQ;
        if(s.equals("!="))  return NE;
        if(s.equals("<"))   return LT;
        if(s.equals("<="))  return LE;
        if(s.equals(">"))   return GT;
        if(s.equals(">="))  return GE;
        if(s.equals("&&"))  return AND;
        if(s.equals("||"))  return OR;
        tok = s.charAt(0);
	}
	return tok;
}

public String ajustarCadena(String cadena){
    String nueva = "";
    boolean encontrado = false;
    for(int i = 0; i < cadena.length() - 1; i++){
        encontrado = false;
        for(int j = 0; j < OPERADORES.length; j++){
            if(cadena.substring(i, i + OPERADORES[j].length()).equals(OPERADORES[j])){
                i += OPERADORES[j].length()-1;
                nueva += " " + OPERADORES[j] + " ";
                encontrado = true;
                break;
            }
        }
        if(!encontrado)
            nueva += cadena.charAt(i);
    }
    nueva += cadena.charAt(cadena.length()-1);
    return nueva;
}

boolean esVariable(String s){
	for(int i = 0; i < OPERADORES.length; i++)
		if(s.equals(OPERADORES[i])) return false;
	return true;
}

public void inicializar(){
	tablaDeSimbolos= new TablaDeSimbolos();
	tablaDeSimbolos.insertar("Left", new MaquinaDePila.Left());
	tablaDeSimbolos.insertar("Right", new MaquinaDePila.Right());
	tablaDeSimbolos.insertar("Forward", new MaquinaDePila.Forward());
	tablaDeSimbolos.insertar("Backward", new MaquinaDePila.Backward());
	tablaDeSimbolos.insertar("Color", new MaquinaDePila.Colour());
	maquina= new MaquinaDePila(tablaDeSimbolos);
}

public Dibujo ejecutarCodigo(String codigo){
	inicializar();
    st = new StringTokenizer(ajustarCadena(codigo));
    newline=false;
    yyparse();
    if(!huboError) {
    	maquina.ejecutar();
    }
    return maquina.getDibujo();
} 
//#line 504 "Parser.java"
//###############################################################
// method: yylexdebug : check lexer state
//###############################################################
void yylexdebug(int state,int ch)
{
String s=null;
  if (ch < 0) ch=0;
  if (ch <= YYMAXTOKEN) //check index bounds
     s = yyname[ch];    //now get it
  if (s==null)
    s = "illegal-symbol";
  debug("state "+state+", reading "+ch+" ("+s+")");
}





//The following are now global, to aid in error reporting
int yyn;       //next next thing to do
int yym;       //
int yystate;   //current parsing state from state table
String yys;    //current token string


//###############################################################
// method: yyparse : parse input and execute indicated items
//###############################################################
int yyparse()
{
boolean doaction;
  init_stacks();
  yynerrs = 0;
  yyerrflag = 0;
  yychar = -1;          //impossible char forces a read
  yystate=0;            //initial state
  state_push(yystate);  //save it
  val_push(yylval);     //save empty value
  while (true) //until parsing is done, either correctly, or w/error
    {
    doaction=true;
    if (yydebug) debug("loop"); 
    //#### NEXT ACTION (from reduction table)
    for (yyn=yydefred[yystate];yyn==0;yyn=yydefred[yystate])
      {
      if (yydebug) debug("yyn:"+yyn+"  state:"+yystate+"  yychar:"+yychar);
      if (yychar < 0)      //we want a char?
        {
        yychar = yylex();  //get next token
        if (yydebug) debug(" next yychar:"+yychar);
        //#### ERROR CHECK ####
        if (yychar < 0)    //it it didn't work/error
          {
          yychar = 0;      //change it to default string (no -1!)
          if (yydebug)
            yylexdebug(yystate,yychar);
          }
        }//yychar<0
      yyn = yysindex[yystate];  //get amount to shift by (shift index)
      if ((yyn != 0) && (yyn += yychar) >= 0 &&
          yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
        {
        if (yydebug)
          debug("state "+yystate+", shifting to state "+yytable[yyn]);
        //#### NEXT STATE ####
        yystate = yytable[yyn];//we are in a new state
        state_push(yystate);   //save it
        val_push(yylval);      //push our lval as the input for next rule
        yychar = -1;           //since we have 'eaten' a token, say we need another
        if (yyerrflag > 0)     //have we recovered an error?
           --yyerrflag;        //give ourselves credit
        doaction=false;        //but don't process yet
        break;   //quit the yyn=0 loop
        }

    yyn = yyrindex[yystate];  //reduce
    if ((yyn !=0 ) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
      {   //we reduced!
      if (yydebug) debug("reduce");
      yyn = yytable[yyn];
      doaction=true; //get ready to execute
      break;         //drop down to actions
      }
    else //ERROR RECOVERY
      {
      if (yyerrflag==0)
        {
        yyerror("syntax error");
        yynerrs++;
        }
      if (yyerrflag < 3) //low error count?
        {
        yyerrflag = 3;
        while (true)   //do until break
          {
          if (stateptr<0)   //check for under & overflow here
            {
            yyerror("stack underflow. aborting...");  //note lower case 's'
            return 1;
            }
          yyn = yysindex[state_peek(0)];
          if ((yyn != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
            if (yydebug)
              debug("state "+state_peek(0)+", error recovery shifting to state "+yytable[yyn]+" ");
            yystate = yytable[yyn];
            state_push(yystate);
            val_push(yylval);
            doaction=false;
            break;
            }
          else
            {
            if (yydebug)
              debug("error recovery discarding state "+state_peek(0)+" ");
            if (stateptr<0)   //check for under & overflow here
              {
              yyerror("Stack underflow. aborting...");  //capital 'S'
              return 1;
              }
            state_pop();
            val_pop();
            }
          }
        }
      else            //discard this token
        {
        if (yychar == 0)
          return 1; //yyabort
        if (yydebug)
          {
          yys = null;
          if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
          if (yys == null) yys = "illegal-symbol";
          debug("state "+yystate+", error recovery discards token "+yychar+" ("+yys+")");
          }
        yychar = -1;  //read another
        }
      }//end error recovery
    }//yyn=0 loop
    if (!doaction)   //any reason not to proceed?
      continue;      //skip action
    yym = yylen[yyn];          //get count of terminals on rhs
    if (yydebug)
      debug("state "+yystate+", reducing "+yym+" by rule "+yyn+" ("+yyrule[yyn]+")");
    if (yym>0)                 //if count of rhs not 'nil'
      yyval = val_peek(yym-1); //get current semantic value
    yyval = dup_yyval(yyval); //duplicate yyval if ParserVal is used as semantic value
    switch(yyn)
      {
//########## USER-SUPPLIED ACTIONS ##########
case 4:
//#line 48 "logo.y"
{yyval = val_peek(1);}
break;
case 5:
//#line 49 "logo.y"
{yyval = val_peek(0);}
break;
case 6:
//#line 50 "logo.y"
{yyval = val_peek(2);}
break;
case 7:
//#line 51 "logo.y"
{yyval = val_peek(1);}
break;
case 8:
//#line 54 "logo.y"
{ yyval = new ParserVal(maquina.agregarOperacion("varPush_Eval")); 
					  maquina.agregar(val_peek(0).sval);}
break;
case 9:
//#line 56 "logo.y"
{ yyval = new ParserVal(maquina.agregarOperacion("constPush"));
					  maquina.agregar(val_peek(0).dval);}
break;
case 10:
//#line 58 "logo.y"
{ yyval = new ParserVal(val_peek(0).ival);
					  maquina.agregarOperacion("varPush");
		        	  maquina.agregar(val_peek(2).sval);
		        	  maquina.agregarOperacion("assign");
		         	  maquina.agregarOperacion("varPush_Eval"); 
					  maquina.agregar(val_peek(2).sval);}
break;
case 11:
//#line 64 "logo.y"
{ yyval = new ParserVal(maquina.agregarOperacion("neg"));}
break;
case 12:
//#line 65 "logo.y"
{ yyval = new ParserVal(val_peek(2).ival);
					  maquina.agregarOperacion("mul");}
break;
case 13:
//#line 67 "logo.y"
{ yyval = new ParserVal(val_peek(2).ival);
					  maquina.agregarOperacion("div");}
break;
case 14:
//#line 69 "logo.y"
{ yyval = new ParserVal(val_peek(2).ival);
					  maquina.agregarOperacion("add");}
break;
case 15:
//#line 71 "logo.y"
{ yyval = new ParserVal(val_peek(2).ival);
					  maquina.agregarOperacion("sub");}
break;
case 16:
//#line 73 "logo.y"
{ yyval = new ParserVal(val_peek(1).ival);}
break;
case 17:
//#line 74 "logo.y"
{ maquina.agregarOperacion("EQ");
				 	  yyval = val_peek(2);}
break;
case 18:
//#line 76 "logo.y"
{ maquina.agregarOperacion("NE");
				 	  yyval = val_peek(2);}
break;
case 19:
//#line 78 "logo.y"
{ maquina.agregarOperacion("LT");
				 	  yyval = val_peek(2);}
break;
case 20:
//#line 80 "logo.y"
{ maquina.agregarOperacion("LE");
				 	  yyval = val_peek(2);}
break;
case 21:
//#line 82 "logo.y"
{ maquina.agregarOperacion("GT");
				 	  yyval = val_peek(2);}
break;
case 22:
//#line 84 "logo.y"
{ maquina.agregarOperacion("GE");
					  yyval = val_peek(2);}
break;
case 23:
//#line 86 "logo.y"
{ maquina.agregarOperacion("AND");
				 	  yyval = val_peek(2);}
break;
case 24:
//#line 88 "logo.y"
{ maquina.agregarOperacion("OR");
					  yyval = val_peek(2);}
break;
case 25:
//#line 90 "logo.y"
{ maquina.agregarOperacion("NOT");
					  yyval = val_peek(0); }
break;
case 26:
//#line 92 "logo.y"
{ yyval = val_peek(0); maquina.agregarOperacion("returnCode"); }
break;
case 27:
//#line 94 "logo.y"
{ yyval = new ParserVal(maquina.agregarOperacion("push_parametro")); 
					  maquina.agregar((int)val_peek(0).ival); }
break;
case 28:
//#line 98 "logo.y"
{ yyval = new ParserVal(maquina.agregarOperacionEn("call",(val_peek(3).ival))); 
								  maquina.agregar(null); }
break;
case 30:
//#line 103 "logo.y"
{yyval = val_peek(0); maquina.agregar("Limite");}
break;
case 31:
//#line 104 "logo.y"
{yyval = val_peek(2); maquina.agregar("Limite");}
break;
case 32:
//#line 107 "logo.y"
{yyval = new ParserVal(maquina.agregarOperacion("nop"));}
break;
case 33:
//#line 110 "logo.y"
{
				yyval = val_peek(13);
				maquina.agregar(val_peek(7).ival, val_peek(13).ival + 1);
				maquina.agregar(val_peek(2).ival, val_peek(13).ival + 2);
				maquina.agregar(maquina.numeroDeElementos() - 1, val_peek(13).ival + 3);
			}
break;
case 34:
//#line 116 "logo.y"
{
				yyval = val_peek(10);
				maquina.agregar(val_peek(4).ival, val_peek(10).ival + 1);
				maquina.agregar(val_peek(1).ival, val_peek(10).ival + 2);
				maquina.agregar(maquina.numeroDeElementos() - 1, val_peek(10).ival + 3);
			}
break;
case 35:
//#line 122 "logo.y"
{ yyval = val_peek(9);
					  maquina.agregar(val_peek(3).ival, val_peek(9).ival + 1);
					  maquina.agregar(val_peek(0).ival, val_peek(9).ival + 2); }
break;
case 36:
//#line 125 "logo.y"
{
				yyval = val_peek(15);
				maquina.agregar(val_peek(10).ival, val_peek(15).ival + 1);
				maquina.agregar(val_peek(7).ival, val_peek(15).ival + 2);
				maquina.agregar(val_peek(3).ival, val_peek(15).ival + 3);
				maquina.agregar(val_peek(0).ival, val_peek(15).ival + 4);
			}
break;
case 39:
//#line 135 "logo.y"
{ yyval = new ParserVal(val_peek(4).ival);
					  maquina.agregar(null); }
break;
case 40:
//#line 139 "logo.y"
{ yyval = new ParserVal(maquina.agregar((Funcion)(val_peek(0).obj)));}
break;
case 41:
//#line 142 "logo.y"
{ maquina.agregarOperacion("declaracion"); }
break;
case 42:
//#line 145 "logo.y"
{ maquina.agregarOperacion("declaracion"); }
break;
case 43:
//#line 148 "logo.y"
{ yyval = new ParserVal(maquina.agregar(val_peek(0).sval));}
break;
case 44:
//#line 151 "logo.y"
{ maquina.agregar(null);}
break;
case 45:
//#line 154 "logo.y"
{ yyval = new ParserVal(maquina.agregarOperacion("stop"));}
break;
case 46:
//#line 157 "logo.y"
{ yyval = new ParserVal(maquina.agregarOperacion("ifCode"));
	        		  maquina.agregarOperacion("stop");
	        	  	  maquina.agregarOperacion("stop");
	        	 	  maquina.agregarOperacion("stop");}
break;
case 47:
//#line 163 "logo.y"
{ yyval = new ParserVal(maquina.agregarOperacion("whileCode"));
	        	  	  maquina.agregarOperacion("stop");
	        		  maquina.agregarOperacion("stop");}
break;
case 48:
//#line 168 "logo.y"
{
			yyval = new ParserVal(maquina.agregarOperacion("forCode"));
	        maquina.agregarOperacion("stop");/*condicion*/
	        maquina.agregarOperacion("stop");/*instrucción final*/
	        maquina.agregarOperacion("stop");/*cuerpo*/
	        maquina.agregarOperacion("stop");/*final*/
		}
break;
case 49:
//#line 176 "logo.y"
{ yyval = new ParserVal(maquina.agregarOperacion("nop"));}
break;
case 50:
//#line 177 "logo.y"
{yyval = val_peek(0);}
break;
case 51:
//#line 178 "logo.y"
{yyval = val_peek(2);}
break;
//#line 885 "Parser.java"
//########## END OF USER-SUPPLIED ACTIONS ##########
    }//switch
    //#### Now let's reduce... ####
    if (yydebug) debug("reduce");
    state_drop(yym);             //we just reduced yylen states
    yystate = state_peek(0);     //get new state
    val_drop(yym);               //corresponding value drop
    yym = yylhs[yyn];            //select next TERMINAL(on lhs)
    if (yystate == 0 && yym == 0)//done? 'rest' state and at first TERMINAL
      {
      if (yydebug) debug("After reduction, shifting from state 0 to state "+YYFINAL+"");
      yystate = YYFINAL;         //explicitly say we're done
      state_push(YYFINAL);       //and save it
      val_push(yyval);           //also save the semantic value of parsing
      if (yychar < 0)            //we want another character?
        {
        yychar = yylex();        //get next character
        if (yychar<0) yychar=0;  //clean, if necessary
        if (yydebug)
          yylexdebug(yystate,yychar);
        }
      if (yychar == 0)          //Good exit (if lex returns 0 ;-)
         break;                 //quit the loop--all DONE
      }//if yystate
    else                        //else not done yet
      {                         //get next state and push, for next yydefred[]
      yyn = yygindex[yym];      //find out where to go
      if ((yyn != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn]; //get new state
      else
        yystate = yydgoto[yym]; //else go to new defred
      if (yydebug) debug("after reduction, shifting from state "+state_peek(0)+" to state "+yystate+"");
      state_push(yystate);     //going again, so push state & val...
      val_push(yyval);         //for next action
      }
    }//main loop
  return 0;//yyaccept!!
}
//## end of method parse() ######################################



//## run() --- for Thread #######################################
/**
 * A default run method, used for operating this parser
 * object in the background.  It is intended for extending Thread
 * or implementing Runnable.  Turn off with -Jnorun .
 */
public void run()
{
  yyparse();
}
//## end of method run() ########################################



//## Constructors ###############################################
/**
 * Default constructor.  Turn off with -Jnoconstruct .

 */
public Parser()
{
  //nothing to do
}


/**
 * Create a parser, setting the debug to true or false.
 * @param debugMe true for debugging, false for no debug.
 */
public Parser(boolean debugMe)
{
  yydebug=debugMe;
}
//###############################################################



}
//################### END OF CLASS ##############################
