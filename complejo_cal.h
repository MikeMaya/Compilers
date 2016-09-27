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
