#include "complejo_cal.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

extern    int errno;
double    errcheck();

Complejo *creaComplejo(double real, double img){
   Complejo *nvo = (Complejo*)malloc(sizeof(Complejo));
   nvo -> real = real;
   nvo -> img = img;
   return nvo;
}
Complejo *Complejo_add(Complejo *c1, Complejo *c2){
  return creaComplejo(c1->real + c2
  ->real, c1->img + c2->img);
}
Complejo *Complejo_sub(Complejo *c1, Complejo *c2){
  return creaComplejo(c1->real - c2->real, c1->img - c2->img);
}
Complejo *Complejo_mul(Complejo *c1, Complejo *c2){
  return creaComplejo( c1->real*c2->real - c1->img*c2->img,
                       c1->img*c2->real + c1->real*c2->img);
}
Complejo *Complejo_div(Complejo *c1, Complejo *c2){
   double d = c2->real*c2->real + c2->img*c2->img;
   return creaComplejo( (c1->real*c2->real + c1->img*c2->img) / d,
                        (c1->img*c2->real - c1->real*c2->img) / d);
}
Complejo *Complejo_neg(Complejo *c1){
   return creaComplejo( c1->real*-1, c1->img*-1);
}
int Equal_cero(Complejo *c){
  //Implementar verificacion
  return 0;
}
void imprimirC(Complejo *c){
   if(c->img != 0)
      printf("%f%+fi\n", c->real, c->img);
   else
      printf("%f\n", c->real);
}

Complejo* Sin(Complejo *x){
  double real, imaginario;
  real=sin(x->real)*cosh(x->img);
  imaginario=cos(x->real)*sinh(x->img);
  //printf("%lf %lf\n",real, imaginario);
  return creaComplejo(real, imaginario);
}

Complejo* Cos(Complejo *x){
  double real, imaginario;
  real=cos(x->real)*cosh(x->img);
  imaginario=-1*sin(x->real)*sinh(x->img);
  //printf("%lf %lf\n",real, imaginario);
  return creaComplejo(real, imaginario);
}

Complejo* Tan(Complejo *x){
  return Complejo_div(Cos(x),Sin(x));
}

Complejo* Log(Complejo *x){
  double real, imaginario;
  if(x->real == 0) real=0 ;
  else real= log(x->real);
  imaginario= x->img * atan (x->img / x->real);
  return creaComplejo(real,imaginario);
}

Complejo*  Log10(Complejo *x){
  puts("LOG 10");
  return x;
}

Complejo*  Exp(Complejo *x){
  double real, imaginario, e;
  e= exp(x->real);
  real= e* cos(x->img);
  imaginario= e* sin(x->img);
  return creaComplejo(real,imaginario);
} 

Complejo* Pow(Complejo *x, Complejo *y){
  Complejo* co= creaComplejo(x->real, x->img);
  int n= y->real;
  int i;
  if(n== 0) return creaComplejo(0,0);
  for(i=0;i<n-1;i++)
    co=Complejo_mul(x,co);
  return co;
}

Complejo* Fabs(Complejo *x) {
  double real, imaginario;
  real = x->real;
  imaginario = x-> img;
  return creaComplejo(sqrt(real*real + imaginario* imaginario),0);
}