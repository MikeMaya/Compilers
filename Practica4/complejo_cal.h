struct Complejo {
  double real, img;
};
typedef struct Complejo Complejo;
typedef struct Complejo *ComplejoAP;
/*  prototypes of the provided functions */ 
Complejo *creaComplejo(double real, double img);
Complejo *Complejo_add(Complejo *, Complejo *);
Complejo *Complejo_sub(Complejo *, Complejo *);
Complejo *Complejo_mul(Complejo *, Complejo *);
Complejo *Complejo_div(Complejo *, Complejo *);
Complejo *Complejo_neg(Complejo *);
int Equal_cero(Complejo *);
Complejo *Sin(Complejo *);
Complejo *Cos(Complejo *);
Complejo *Tan(Complejo *);
Complejo *Log(Complejo *);
Complejo *Log10(Complejo *);
Complejo *Exp(Complejo *);
Complejo *Fabs(Complejo *);
Complejo *Pow(Complejo *, Complejo *);

void imprimirC(Complejo *c);
/*  prototypes of the provided functions */ 
/* define the return type of FLEX */
typedef struct Symbol { /* entrada de la tabla de símbolos */
	char   *name;
	short   type;   /* VAR, BLTIN, UNDEF */
	union {
		Complejo *com;	       /* si es VAR */
		Complejo * (*ptr)();      /* sí es BLTIN */
	} u;
	struct Symbol   *next;  /* para ligarse a otro */ 
} Symbol;

Symbol *install(char *s,int t, Complejo* d), *lookup(char *s);

typedef union Datum {   /* tipo de la pila del intérprete */
	Complejo *com;
	Symbol  *sym; 
} Datum; 

typedef int (*Inst)();  /* instrucción de máquina */ 
#define STOP (Inst) 0
extern	Inst prog[];
extern void initcode();
extern Inst *code(Inst f);
extern void execute(Inst p);
extern void push(Datum d);
extern Datum pop();
extern void print();
extern void assign();
extern void varpush();
extern void constpush();
extern void eval();
extern void add() ;
extern void sub();
extern void mul();
extern void divi();
extern void power();
extern void bltin();
