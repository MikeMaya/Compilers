%{
import java.lang.Math;
import java.io.*;
import java.util.StringTokenizer;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;
import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;
import javax.swing.JFrame;
import javax.swing.JPanel;

%}

/* YACC Declarations */
%token LIN
%token COL
%token CIR
%token REC
%token COOR

/* Grammar follows */
%%
input: /* empty string */
 | input line
 ;

line: '\n'
 |  linea'\n' {}
 |  rectangulo'\n' {}
 |  circulo'\n' {}
 ;


linea: LIN { $$ = $1; }
 | linea cor cor cor cor col{ makeLine($2.dval, $3.dval, $4.dval, $5.dval, $6.sval);}
 ;

rectangulo: REC { $$ = $1; }
 | rectangulo cor cor cor cor col{ makeRectangle($2.dval, $3.dval, $4.dval, $5.dval, $6.sval);}
 ;

circulo: CIR {$$ = $1;}
 | circulo cor cor cor col{ makeCircle($2.dval, $3.dval, $4.dval, $5.sval);}
 ;

 cor: COOR {$$ = new ParserVal($1.dval);}
 ;

 col: COL {$$ = new ParserVal($1.sval);}
 ;
%%

String ins;
StringTokenizer st;
MiPanel mipanel;
boolean newline;

void yyerror(String s){
 System.out.println("par:"+s);
}

void makeCircle(double radio, double x,  double y, String color){
	Figura f= new Figura("circulo");
	f.setTam(x, y, radio, radio);
	f.setColor(color);
	mipanel.agregar(f);
}
void makeLine(double x1, double y1, double x2, double y2, String color){
	Figura f= new Figura("linea");
	f.setTam(x1, y1, x2, y2);
	f.setColor(color);
	mipanel.agregar(f);
}
void makeRectangle(double x, double y, double largo, double ancho, String color){
	Figura f= new Figura("rectangulo");
	f.setTam(x, y, largo, ancho);
	f.setColor(color);
	mipanel.agregar(f);
}

int yylex(){
	String s;
	int tok;
	Double d;
 	//System.out.print("yylex ");
 	if (!st.hasMoreTokens())
 	if (!newline){
 		newline=true;
 		return '\n'; //So we look like classic YACC example
 	} else return 0;
 	s = st.nextToken();
 	//System.out.println("tk: "+s);
 	if(s.equals("circulo")){
 		tok=CIR;
 	} else if(s.equals("linea")){
 		tok=LIN;
 	} else if(s.equals("rectangulo")){
 		tok=REC;
 	} else if(s.equals("rojo") || s.equals("azul") || s.equals("verde") 
 		||s.equals("amarillo") || s.equals("negro")){
 		tok=COL;
 		yylval = new ParserVal(s);
 	} else {
	 	try {
	 		d = Double.valueOf(s);/*this may fail*/
	 		yylval = new ParserVal(d.doubleValue()); //SEE BELOW
	 		tok = COOR;
	 	} catch (Exception e) {
	 		tok = s.charAt(0);/*if not float, return char*/
	 	}
	}
 	return tok;
}

void dotest(){
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	mipanel= new MiPanel();
 	while (true) {
 		try {
 			ins = in.readLine();
 		} catch (Exception e) {

 		}
 		st = new StringTokenizer(ins);
 		newline=false;
 		yyparse();
 	}
}

public static void main(String args[]) {
 	Parser par = new Parser(false);
 	par.dotest();
}

class MiPanel extends JFrame{
    Paleta paleta;
    public MiPanel(){
        paleta= new Paleta();
        setSize(500, 500);
        setVisible(true);
        add(paleta);
    }
    public void agregar(Figura f){
        paleta.newFigure(f);
        paleta.repaint();
    }
}

class Paleta extends JPanel{
    ArrayList<Figura> elementos = new ArrayList();
    public void newFigure(Figura f){
        elementos.add(f);
        repaint();
    }
    @Override
    public void paint(Graphics g) {
        super.paint(g); 
        for(Figura f: elementos){
            f.draw(g);
        }
    }
    
}
class Figura {
    String tipo;
    double x1, x2, y1, y2;
    Color color;
    public Figura(String t){
        tipo=t;
    }
    public void setTam(double x, double y, double l, double a){
        x1=x; y1=y; x2=l; y2=a;
    }
    public void setColor(String s){
        switch(s){
            case "rojo": 
                color=Color.RED;
                break;
            case "azul": 
                color=Color.BLUE;
                break;
            case "verde": 
                color=Color.GREEN;
                break;
            case "amarillo": 
                color=Color.YELLOW;
                break;   
            case "negro": 
                color=Color.BLACK;
                break;    
        }
    }
    public void draw(Graphics g){
        g.setColor(color);
        switch(tipo){
            case "linea": 
                g.drawLine((int) x1,(int) y1,(int) x2,(int) y2);
                break;
            case "circulo": 
                g.drawOval((int) x1,(int) y1,(int) x2,(int) y2);
                break;
            case "rectangulo": 
                g.drawRect((int) x1,(int) y1,(int) x2,(int) y2);
                break;
        }
    }
}
