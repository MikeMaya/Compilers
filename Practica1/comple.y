%{
#include <math.h>

#include "complejo_cal.h"
#define YYSTYPE ComplejoAP

void yyerror (char *s);
int yylex ();
void warning(char *s, char *t);
%}

%token CNUMBER
%left '+' '-'
%left '*' '/'

%% /* A continuación las reglas gramaticales y las acciones */

list:   
	| list'\n'
        | list exp '\n'  { imprimirC($2); }
	;

exp:      CNUMBER          { $$ = $1;  }
        | exp '+' exp     { $$ = Complejo_add($1, $3);  }
        | exp '-' exp     { $$ = Complejo_sub($1, $3);  }
        | exp '*' exp     { $$ = Complejo_mul($1, $3);  }
        | exp '/' exp     { $$ = Complejo_div($1, $3);  }
        | '(' exp ')'     { $$ = $2;}
	;
%%

#include <stdio.h>
#include <ctype.h>
char *progname;
int lineno = 1;

void main (int argc, char *argv[])
{
	progname=argv[0];
  	yyparse ();
}

void yyerror (char *s)  /* Llamada por yyparse ante un error */{
	warning(s, (char *) 0);
}

void warning(char *s, char *t){
	fprintf (stderr, "%s: %s", progname, s);
	if(t) fprintf (stderr, " %s", t);
	fprintf (stderr, "cerca de la linea %d\n", lineno);
}




