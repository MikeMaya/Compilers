%{
	import java.lang.Math;
	import java.io.*;
	import java.util.StringTokenizer;
%}


%token IF
%token ELSE
%token WHILE
%token FOR
%token EQ
%token NE
%token GT
%token LT
%token GE
%token LE
%token FNCT
%token NUMBER
%token VAR
%token AND
%token OR
%token FUNC
%token RETURN
%token PARAMETRO
%token PROC
%right '='
%left '+' '-'
%left '*'  '/'
%left ';'
%left EQ
%left NE
%left GT
%left GE
%left LT
%left LE
%left '!'
%left AND
%left OR
%right RETURN
%%

list:   
	| list'\n'
	| list linea '\n'
	;

linea: exp ';' 		{$$ = $1;}
	| stmt 			{$$ = $1;}
	| linea exp ';' {$$ = $1;}
	| linea stmt 	{$$ = $1;}
	;
		
exp:  VAR 			{ $$ = new ParserVal(maquina.agregarOperacion("varPush_Eval")); 
					  maquina.agregar($1.sval);}
	| NUMBER 		{ $$ = new ParserVal(maquina.agregarOperacion("constPush"));
					  maquina.agregar($1.dval);}
	| VAR '=' exp 	{ $$ = new ParserVal($3.ival);
					  maquina.agregarOperacion("varPush");
		        	  maquina.agregar($1.sval);
		        	  maquina.agregarOperacion("assign");
		         	  maquina.agregarOperacion("varPush_Eval"); 
					  maquina.agregar($1.sval);}
	| '-' exp 		{ $$ = new ParserVal(maquina.agregarOperacion("neg"));}
	| exp '*' exp 	{ $$ = new ParserVal($1.ival);
					  maquina.agregarOperacion("mul");}
	| exp '/' exp 	{ $$ = new ParserVal($1.ival);
					  maquina.agregarOperacion("div");}
	| exp '+' exp   { $$ = new ParserVal($1.ival);
					  maquina.agregarOperacion("add");}
	| exp '-' exp 	{ $$ = new ParserVal($1.ival);
					  maquina.agregarOperacion("sub");}
	|'(' exp ')' 	{ $$ = new ParserVal($2.ival);}
	| exp EQ exp 	{ maquina.agregarOperacion("EQ");
				 	  $$ = $1;}
	| exp NE exp 	{ maquina.agregarOperacion("NE");
				 	  $$ = $1;}
	| exp LT exp 	{ maquina.agregarOperacion("LT");
				 	  $$ = $1;}
	| exp LE exp 	{ maquina.agregarOperacion("LE");
				 	  $$ = $1;}
	| exp GT exp 	{ maquina.agregarOperacion("GT");
				 	  $$ = $1;}
	| exp GE exp 	{ maquina.agregarOperacion("GE");
					  $$ = $1;}
	| exp AND exp 	{ maquina.agregarOperacion("AND");
				 	  $$ = $1;}
	| exp OR exp 	{ maquina.agregarOperacion("OR");
					  $$ = $1;}
	| '!' exp 		{ maquina.agregarOperacion("NOT");
					  $$ = $2; }
	| RETURN exp 	{ $$ = $2; maquina.agregarOperacion("returnCode"); } 
		
	| PARAMETRO 	{ $$ = new ParserVal(maquina.agregarOperacion("push_parametro")); 
					  maquina.agregar((int)$1.ival); }

					  //instrucciones tiene la estructura necesaria para la lista de argumentos
	| nombreProc '(' arglist ')' { $$ = new ParserVal(maquina.agregarOperacionEn("call",($1.ival))); 
								  maquina.agregar(null); } 
	;
		
arglist: 
	|exp 				{$$ = $1; maquina.agregar("Limite");}
	|arglist ',' exp 	{$$ = $1; maquina.agregar("Limite");}
	;
	
nop:{$$ = new ParserVal(maquina.agregarOperacion("nop"));}
	;
	
stmt:if_ '(' exp stop_ ')' '{' linea stop_ '}' ELSE '{' linea stop_'}' {
				$$ = $1;
				maquina.agregar($7.ival, $1.ival + 1);
				maquina.agregar($12.ival, $1.ival + 2);
				maquina.agregar(maquina.numeroDeElementos() - 1, $1.ival + 3);
			}
	| if_ '(' exp stop_ ')' '{' linea stop_ '}' nop stop_{
				$$ = $1;
				maquina.agregar($7.ival, $1.ival + 1);
				maquina.agregar($10.ival, $1.ival + 2);
				maquina.agregar(maquina.numeroDeElementos() - 1, $1.ival + 3);
			}
	| while_ '(' exp stop_ ')' '{' linea stop_ '}' stop_{ $$ = $1;
					  maquina.agregar($7.ival, $1.ival + 1);
					  maquina.agregar($10.ival, $1.ival + 2); }
	| for_ '(' instrucciones stop_ ';' exp stop_ ';' instrucciones stop_ ')' '{' linea stop_ '}' stop_{
				$$ = $1;
				maquina.agregar($6.ival, $1.ival + 1);
				maquina.agregar($9.ival, $1.ival + 2);
				maquina.agregar($13.ival, $1.ival + 3);
				maquina.agregar($16.ival, $1.ival + 4);
			}
	| funcion nombreProc '(' ')' '{' linea null_ '}'
	| procedimiento nombreProc '(' ')' '{' linea null_ '}'
	| instruccion '(' arglist ')' ';' 
					{ $$ = new ParserVal($1.ival);
					  maquina.agregar(null); }
	;

instruccion: FNCT 	{ $$ = new ParserVal(maquina.agregar((Funcion)($1.obj)));}
	;

procedimiento: PROC { maquina.agregarOperacion("declaracion"); }
	;
	
funcion: FUNC 		{ maquina.agregarOperacion("declaracion"); }
	;
		
nombreProc: VAR 	{ $$ = new ParserVal(maquina.agregar($1.sval));}
	;
		
null_: 				{ maquina.agregar(null);}
	;
		
stop_: 				{ $$ = new ParserVal(maquina.agregarOperacion("stop"));} 
	;

if_: IF 			{ $$ = new ParserVal(maquina.agregarOperacion("ifCode"));
	        		  maquina.agregarOperacion("stop");
	        	  	  maquina.agregarOperacion("stop");
	        	 	  maquina.agregarOperacion("stop");}
	;

while_: WHILE 		{ $$ = new ParserVal(maquina.agregarOperacion("whileCode"));
	        	  	  maquina.agregarOperacion("stop");
	        		  maquina.agregarOperacion("stop");}
	;

for_ : FOR {
			$$ = new ParserVal(maquina.agregarOperacion("forCode"));
	        maquina.agregarOperacion("stop");//condicion
	        maquina.agregarOperacion("stop");//instrucción final
	        maquina.agregarOperacion("stop");//cuerpo
	        maquina.agregarOperacion("stop");//final
		}		

instrucciones: 				{ $$ = new ParserVal(maquina.agregarOperacion("nop"));}
	|exp 					{$$ = $1;}
	|instrucciones ',' exp 	{$$ = $1;}
	;
%%


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
