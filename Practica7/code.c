#include "complejo_cal.h" 
#include <string.h>
#include "y.tab.h"
#define NSTACK  1024
#define NFRAME  100 
#define NPROG   2000
static  Datum  stack[NSTACK];  /* la pila */
static  Datum   *stackp;       /* siguiente lugar libre en la pila */

Inst    prog[NPROG];     /* la máquina */
Inst    *progp;          /* siguiente lugar libre para la generación de código */
Inst    *pc;             /* contador de programa durante la ejecución */
Inst   *progbase = prog; /* Inicie del subprograaa actual */
int    returning;        /* 1 si se ve la proposiolón de retorno */

typedef struct Frame {     /* nivel da pila par» Huida a proc/func */
  Symbol  *sp;         /* entrada en la tabla da simbolos */
  Inst    *retpc;   /* dónde reanudar después del retorno */
  Datum  *argn;     /* n-esimo argumento en la pila */
  int    nargs;     /* número da argumentos */
} Frame;


Frame  frame[NFRAME] ;
Frame   *fp;  /* apuntador a nivel */

/* inicialización para la generación de código */ 
void initcode(){
  stackp = stack;
  progp = progbase;
  fp = frame;
  returning = 0;
}

/* instalar una instrucción u operando   */
Inst *code(Inst f) {
  Inst *oprogp = progp;
  if (progp >= &prog [ NPROG ])
    puts("program too big");
  *progp++ = f;
  return oprogp;
}

/*   ejecución con la máquina   */
void execute(Inst p) {
  for  (pc  =  p;   *pc  != STOP && !returning; ) 
    (*((++pc)[-1]))();
}

/*  meter d en la pila  */
void push(Datum d){
  if (stackp >= &stack[NSTACK])
    puts("stack overflow");
  *stackp++ = d;
}

/* sacar y retornar de la pila el elemento del tope */
Datum pop(){
//  puts("pop");
  if (stackp <= stack)
    puts("stack underflow");
  return  *--stackp;
}

/* sacar el valor superior de la pila e imprimirlo */ 
void print() {
  Datum d;
  d = pop();
  imprimirC(d.com);
}

/*   imprimir el valor numérico   */
void prexpr( ) {
  Datum d;
  d = pop();
  imprimirC(d.com);
}

/* asignar el valor superior al siguientevalor */ 
void assign(){
//  puts("assign");
  Datum d1, d2;
  d1 = pop(); //variable 
  d2 = pop(); //complejo
  if (d1.sym->type != VAR && d1.sym->type != INDEF) 
    puts("assignment to non-variable");
  d1.sym->u.com = creaComplejo(d2.com->real, d2.com->img);
  d1.sym->type = VAR;
  push(d2); 
} 

/* meter una variable a la pila   */
void varpush(){
  //puts("varpush");
  Datum d;
  d.sym  =  (Symbol*)(*pc++);
  push(d);
}

/* meter una constante a la pila  */
void constpush(){
  Datum d;
  d.com  =  ((Symbol  *)*pc++)->u.com;
  push(d);
}

/*  evaluar una variable en la pila   */
void eval(){
  Datum  d;
  d = pop();
  if   (d.sym->type   ==   INDEF)
    puts("undefined variable");   
  d.com = d.sym->u.com; 
  push(d);
}
/*   sumar los dos elementos superiores de la pila   */
void add() {
  Datum d1, d2; 
  d2 = pop(); 
  d1 = pop();
  d1.com = Complejo_add(d1.com,d2.com);
  push(d1); 
}

void sub(){
  Datum d1,  d2; 
  d2  = pop(); 
  d1  = pop(); 
  d1.com = Complejo_sub(d1.com, d2.com); 
  push(d1);
}

void mul(){
  Datum d1, d2;
  d2 = pop(); 
  d1 = pop(); 
  d1.com = Complejo_mul(d1.com, d2.com); 
  push(d1);
}

void divi( ){
  Datum d1, d2;
  d2 = pop();
  if (Equal_cero(d2.com))
    puts("division by zero");
  d1 = pop(); 
  d1.com = Complejo_div(d1.com, d2.com);
  push(d1);
}

void power(){
  Datum d1, d2;
  d2 = pop();
  d1 = pop();
  d1.com = Pow(d1.com, d2.com);
  push(d1);
}
/*  evaluar un predefinido en el tope de la pila  */
void bltin(){
  Datum d;
  d  =  pop();
  d.com  =   (*(Complejo * (*)()) (*pc++)) (d.com);
  push(d);
}

/** FUNCIONES DE COMPARACION**/ 
/*Al ser un lenguaje que trata con nuermos complejos, 
todas las comparaciones se realiza en la parte real de los mismos*/

//Greater than
void gt() {
  Datum d1, d2, d3;
  d2 = pop();
  d1 = pop();
  d3.com  = creaComplejo( (double) (d1.com ->real > d2.com -> real ),0);
  push(d3);
}
//Less than
void lt() {
  Datum d1, d2, d3;
  d2 = pop();
  d1 = pop();
  d3.com = creaComplejo( (double) (d1.com ->real < d2.com -> real ),0);
  push(d3);
}

//Greater Equal
void ge() {
  Datum d1, d2, d3;
  d2  = pop();
  d1  = pop();
  d3.com = creaComplejo( (double) (d1.com ->real >= d2.com -> real ),0);
  push(d3) ;
}

//Less Equal 
void le() {
  Datum d1, d2, d3;
  d2   =  pop();
  d1   =  pop();
  d3.com = creaComplejo( (double) (d1.com ->real <= d2.com -> real ),0);
  push(d3);
}

//Equal
void eq( ) {
  Datum d1, d2, d3;
  d2  = pop();
  d1  = pop();
  //printf("%f %f %d", d1.com->real, d2.com->real, d1.com->real == d2.com->real);
  d3.com = creaComplejo( (double) (d1.com ->real == d2.com -> real ),0);
  push(d3);
}

//Not equal
void ne(){
  Datum d1, d2, d3;
  d2 = pop();
  d1 = pop();
  d3.com = creaComplejo( (double) (d1.com ->real != d2.com -> real ),0);
  push(d3);
}

void and(){
  Datum d1, d2, d3;
  d2   = pop();
  d1   = pop();
  d3.com = creaComplejo( (double) (d1.com ->real != 0.0 && d2.com -> real !=0.0 ),0);
  push(d3);
}

void or(){
  Datum d1, d2, d3;
  d2 = pop();
  d1 = pop();
  d3.com = creaComplejo( (double) (d1.com ->real != 0.0 || d2.com -> real !=0.0 ),0);
  push(d3);
}

void not(){
  Datum d, d1;
  d = pop();
  d1.com = creaComplejo( (double) (d.com ->real == 0.0),0);
  push(d1);
}

//Codificacion de WHILE
void whilecode() {
  Datum d;
  Inst  *savepc  = pc;  /*  cuerpo de la iteración  */
  execute(savepc+2);     /*   condición   */ 
  d  =  pop(); 
  while (d.com -> real){ 
    execute(*((Inst  **)(savepc)));     /*  cuerpo  */
    execute(savepc+2);
    d  = pop(); 
  } 
  pc  =  *((Inst  **)(savepc+1));     /*   siguiente proposición   */
}

//Codificacion de IF
void ifcode(){
  Datum d;
  Inst  *savepc  = pc;  /* parte then */
  execute(savepc+3);  /*  condición   */
  d  =  pop(); 
  if (d.com -> real > 0.0)
    execute (*((Inst   **)(savepc))); 
  else  if   (*((Inst  **)(savepc+1)))   /*  ¿parte else?   */
    execute (*(( Inst  **) (savepc+1)));
  pc  =  *((Inst  **)(savepc+2)); /*  siguiente proposición   */ 
}

//Codificacion de FOR
void forcode(){
  Datum d;
  Inst *savepc = pc;
  //Ejecutar la inicializacion
  execute(savepc+4);
  //Conducion
  execute(*((Inst   **)(savepc)));
  d = pop();
  
  while (d.com -> real){ 
    execute(*((Inst   **)(savepc+2))); /*parte del cuerpo*/
    execute(*((Inst   **)(savepc+1))); /*parte final del for*/
    execute(*((Inst   **)(savepc)));   /*condicional*/
    d = pop();
  }
  pc  = (*((Inst   **)(savepc+3)));     /*   siguiente proposición   */
}

void call()  {             /*   llamar función  */
  Symbol  *sp  =   (Symbol *)pc[0];   /*   entrada en tabla da simbolos  */ 
  /*   para la función   */
  if   (fp++   >=  &frame[NFRAME-1]){
    puts(sp->name);   puts("call  nested too deeply");
  }
  fp->sp = sp;
  fp->nargs =   (int)pc[1];
  fp->retpc = pc  + 2;
  fp->argn  =  stackp  -   1;     /*   último argumento   */
  execute(sp->u.defn);
  returning = 0; 
} 

/*   retorno de un prooedimiento   */
void procret( ) {            
  if   (fp->sp->type  ==  FUNCTION){
    puts(fp->sp->name);
    puts("(func) returns no value"); }
  ret(); 
}

/* return from a function */
void funcret(){
  Datum d;
  if (fp->sp->type == PROCEDURE){
    puts(fp->sp->name); puts("(proc) returns value");
  }
  d = pop();  /* preserve function return value */
  ret();
  push(d);
}

/* retorno común de func o proc */
void ret( ) {                         
  int i;
  for (i = 0; i < fp->nargs; i++)
    pop();  /* sacar argunentos de la pila */
  pc = (Inst *)fp->retpc;
  --fp;
  returning = 1; 
}

/* poner func/proc en tabla de símbolos */
void define(sp)  Symbol *sp; {
  sp->u.defn = (Inst)progbase;     /* lnlolo de código */ 
  progbase = progp;      /* el siguiente código comienza aquí */
}

 /* return pointer to argument */
Complejo* getarg() {
  int nargs = (int) *pc++;
  if (nargs > fp->nargs){
      puts(fp->sp->name); puts("not enough arguments");}
  return fp->argn[nargs - fp->nargs].com;
}
 
/* push argument onto stack */
void arg(){  
  Datum d;
  d.com = getarg();
  push(d);
}

/* store top of stack in argument */
void argassign(){
  Datum d;
  d = pop();
  push(d);  /* leave value on stack */
  (*getarg()) = *d.com;
}