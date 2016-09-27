#include "complejo_cal.h" 
#include <string.h>
#include "y.tab.h"
#define NSTACK  256
static  Datum  stack[NSTACK];  /* la pila */
static  Datum   *stackp;       /* siguiente lugar libre en la pila */
#define NPROG   2000
Inst    prog[NPROG];    /* la máquina */
Inst    *progp;         /* siguiente lugar libre para la generación de código */
Inst    *pc;  /* contador de programa durante la ejecución */

/* inicialización para la generación de código */ 
void initcode(){
  stackp = stack;
  progp = prog;
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
  for  (pc  =  p;   *pc  != STOP; ) 
    (*(*pc++))();
}

/*  meter d en la pila  */
void push(Datum d){
  if (stackp >= &stack[NSTACK])
    puts("stack overflow");
  *stackp++ = d;
}

/* sacar y retornar de la pila el elemento del tope */
Datum pop(){
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

/* asignar el valor superior al siguientevalor */ 
void assign(){
  Datum d1, d2;
  d1 = pop(); //variable 
  d2 = pop(); //complejo
  if (d1.sym->type != VAR && d1.sym->type != INDEF) 
    puts("assignment to non-variable");
  d1.sym->u.com = d2.com;
  d1.sym->type = VAR;
  push(d2); 
} 

/* meter una variable a la pila   */
void varpush(){
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
