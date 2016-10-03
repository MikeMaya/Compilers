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
typedef union {
  Inst *inst;
  Symbol *sym;
} YYSTYPE;
extern YYSTYPE yylval;
