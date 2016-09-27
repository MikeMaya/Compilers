#define CNUMBER 257
#define VAR 258
#define BLTIN 259
#define INDEF 260
typedef union {
  Inst *inst;
  Symbol *sym;
} YYSTYPE;
extern YYSTYPE yylval;
