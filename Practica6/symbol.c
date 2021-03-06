#include "complejo_cal.h"
#include <string.h>
#include <stdio.h>
static Symbol *symlist=0;    /* tabla de simbolos: lista ligada */

Symbol *lookup(char *s){    /* encontrar s en la tabla de símbolos */
	Symbol  *sp;
	for (sp = symlist; sp != (Symbol *)0; sp = sp->next) 
		if (strcmp(sp->name, s)== 0) 
			return sp;
	return 0;      /* 0 ==> no se encontró */ 
}

Symbol *install(char *s, int t, Complejo* d) /* instalar s en la tabla de símbolos */
{
	Symbol *sp;
	char *emalloc();
	sp = (Symbol *) emalloc(sizeof(Symbol));
	sp->name = emalloc(strlen(s)+ 1) ; /* +1 para '\0' */
	strcpy(sp->name, s);
	sp->type = t;
	sp->u.com = d;
	sp->next  =  symlist;   /*  poner al frente de la lista   */
	symlist =  sp; 
    return sp; 
}

char  *emalloc(unsigned n)	/*   revisar el regreso desde malloc  */
{
	char *p, *malloc();
	p = malloc(n); 
	if(p == 0)
		puts("out of memory"); 
	return p; 
}
