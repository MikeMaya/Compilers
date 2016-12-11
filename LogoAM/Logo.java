import java.awt.*;
import javax.swing.*;

public class Logo extends javax.swing.JFrame {
    public static final int ANCHO = 800;
    public static final int LARGO = 650;
    private Parser parser;
    private Paleta paleta;
    private boolean modoDebug;
    private JScrollPane jScrollPane1;
    private JButton jButton1;
    private JButton jButton2;
    private JButton poligono;
    private JButton pentagrama;
    private JButton estrellaDavid;
    private JButton espiralC;
    private JButton cc;
    private JButton espirografo;
    private JButton regla;
    private JButton arbol;
    private JButton helecho;
    private JLabel jLabel1;
    private JTextArea jTextArea1;

    public Logo() {
        super("LOGO");
        initComponents();
    }

    private void initComponents() {
        modoDebug=false;
                      
        jTextArea1 = new JTextArea(20,20);
        jTextArea1.setFont(new Font("Courier New", Font.PLAIN, 14));
        jTextArea1.setLineWrap(true);
        jTextArea1.setWrapStyleWord(true);
        jTextArea1.setTabSize(4);
        jTextArea1.setBackground(new Color(238, 245, 252));
        jScrollPane1 = new JScrollPane (jTextArea1);
        jScrollPane1.setBounds(450,70,330,480);
        add(jScrollPane1);

        paleta = new Paleta(430, 600);
        paleta.setBounds(10,10, 430, 600);
        paleta.setBackground( new Color(255, 255, 255) );
        add(paleta);

        jButton1 = new JButton();
        jButton1.setText("Ejecutar");
        jButton1.setBounds(465, 565, 300, 20);
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        add(jButton1);

        jButton2 = new JButton();
        jButton2.setText("Reset");
        jButton2.setBounds(465, 590, 300, 20);
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });
        add(jButton2);
        
        //jLabel1 = new JLabel();
        //jLabel1.setBounds(465, 10, 300, 40);
        //jLabel1.setFont(new java.awt.Font("Noto Sans CJK KR Bold", 1, 24)); // NOI18N
        //jLabel1.setText("Lenguaje Logo");
        //add(jLabel1);
        
        /*Seccion de botones demos*/

        poligono = new JButton();
        poligono.setText("Poligon");
        poligono.setBounds(450, 10, 100, 15);
        poligono.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                poligonoAction(evt);
            }
        });
        add(poligono);

        pentagrama = new JButton();
        pentagrama.setText("Penta");
        pentagrama.setBounds(560, 10, 100, 15);
        pentagrama.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                pentagramaAction(evt);
            }
        });
        add(pentagrama);

        estrellaDavid = new JButton();
        estrellaDavid.setText("E. David");
        estrellaDavid.setBounds(670, 10, 100, 15);
        estrellaDavid.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                estrellaDavidAction(evt);
            }
        });
        add(estrellaDavid);

        espiralC = new JButton();
        espiralC.setText("E. Cuadrada");
        espiralC.setBounds(450, 30, 100, 15);
        espiralC.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                espiralCAction(evt);
            }
        });
        add(espiralC);

        cc = new JButton();
        cc.setText("Cir-Cua");
        cc.setBounds(560, 30, 100, 15);
        cc.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ccAction(evt);
            }
        });
        add(cc);

        espirografo = new JButton();
        espirografo.setText("Espirografo");
        espirografo.setBounds(670, 30, 100, 15);
        espirografo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                espirografoAction(evt);
            }
        });
        add(espirografo);

        regla = new JButton();
        regla.setText("Regla");
        regla.setBounds(450, 50, 100, 15);
        regla.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                reglaAction(evt);
            }
        });
        add(regla);

        arbol = new JButton();
        arbol.setText("Arbol");
        arbol.setBounds(560, 50, 100, 15);
        arbol.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                arbolAction(evt);
            }
        });
        add(arbol);

        helecho = new JButton();
        helecho.setText("Helecho");
        helecho.setBounds(670, 50, 100, 15);
        helecho.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                helechoAction(evt);
            }
        });
        add(helecho);
        /*FIN DE SECCION D BOTNOES */


        setLayout(null);
        setVisible(true);
        setResizable(false);
        this.getContentPane().setBackground(new java.awt.Color(1, 170, 170));
        setMinimumSize(new java.awt.Dimension(ANCHO, LARGO));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        setPreferredSize(new java.awt.Dimension(ANCHO, LARGO));
        
        

    }

    private void helechoAction(java.awt.event.ActionEvent evt) {                                         
        String code= "proc fern(){ \n"+
        "if($1 > 1) {\n"+
        "Forward($1);\n"+
        "Left(290 * $2);\n"+
        "fern($1 / 2 , $2 * -1);\n"+
        "Left(70 * $2);\n"+
        "Forward($1);\n"+
        "Left(70 * $2);\n"+
        "fern($1 / 2 , $2);\n"+
        "Left(290 * $2);\n"+
        "Left(353 * $2);\n"+
        "fern($1 - 1 , $2);\n"+
        "Left(7 * $2);\n"+
        "Left(180);\n"+
        "Forward($1 * 2);\n"+
        "Left(180);\n"+
        "} \n"+
        "}\n"+
        "Color(255, 255, 255);\n"+
        "Left(150);\n"+
        "Forward(300);\n"+
        "Left(210);\n"+
        "Color(1, 150, 0);\n"+
        "fern(25, 1);\n";
        jTextArea1.setText(code);
        paleta.limpiar();
        paleta.repaint();
    }

    private void reglaAction(java.awt.event.ActionEvent evt) {                                         
        String code= "proc Linea(){\n"+
        "Left(90);\n"+
        "Forward($1);\n"+
        "Left(180);\n"+
        "Forward($1 *2);\n"+
        "Right(180);\n"+
        "Forward($1);\n"+
        "Right(90);\n"+"}\n"+"proc Regla(){\n"+
        "if($1 > 5){\n"+
        "Linea($1);\n"+
        "Forward($2);\n"+
        "Backward($2*2);\n"+
        "Forward($2);\n"+
        "Forward($2 / 2);\n"+
        "Regla($1 / 2, $2 / 2);\n"+
        "Backward($2);\n"+
        "Regla($1 / 2 , $2 / 2);\n"+
        "Forward($2 / 2);\n"+
        "}\n"+
        "}\n"+
        "Regla(100, 500);\n";
        jTextArea1.setText(code);
        paleta.limpiar();
        paleta.repaint();
    }

    private void arbolAction(java.awt.event.ActionEvent evt) {                                         
        String code= "proc treeD(){\n"+
        "if($1 < 5) {\n"+
        "Forward($1);\n"+
        "Backward($1);\n"+
        "} else {\n"+
        "Forward($1 / 3);\n"+
        "Right(30);\n"+
        "treeD($1 * ( 2 / 3 ) );\n"+
        "Left(30);\n"+
        "Forward($1 / 6);\n"+
        "Right(25);\n"+
        "treeD($1 / 2);\n"+
        "Left(25); \n"+
        "Forward($1 / 3);\n"+
        "Right(25);\n"+
        "treeD($1 / 2);\n"+
        "Left(25);\n"+
        "Forward($1 / 6);\n"+
        "Backward($1);\n"+
        "}\n"+
        "}\n"+
        "proc treeI(){\n"+
        "if($1 < 5)  {\n"+
        "Forward($1);\n"+
        "Backward($1);\n"+
        "} else {\n"+
        "Forward($1 / 3);\n"+
        "Left(30);\n"+
        "treeI($1 * ( 2 / 3 ) );\n"+
        "Right(30);\n"+
        "Forward($1 / 6);\n"+
        "Left(25);\n"+
        "treeI($1 / 2);\n"+
        "Right(25); \n"+
        "Forward($1 / 3);\n"+
        "Left(25);\n"+
        "treeI($1 / 2);\n"+
        "Right(25);\n"+
        "Forward($1 / 6);\n"+
        "Backward($1);\n"+
        "}\n"+
        "} \n"+
        "Color(255,255,255);\n"+
        "Backward(200);\n"+
        "Color(1, 150, 0);\n"+
        "treeI(250);\n"+
        "treeD(250);\n";
        jTextArea1.setText(code);
        paleta.limpiar();
        paleta.repaint();
    }

    private void espirografoAction(java.awt.event.ActionEvent evt) {                                         
        String code= "proc circulo(){\n"+
        "for(aux=0; aux<360; aux=aux+1){\n"+
        "Color($1,$2,$3);\n"+
        "Forward(2);\n"+
        "Left(1);\n"+
        "}\n"+
        "}\n"+
        "proc espirografo(){\n"+
        "for(i=0;i<16;i=i+1){\n"+
        "circulo((i+1)*15, (i+1)*25, (i+1)*35);\n"+
        "Left(45);\n"+
        "}\n"+
        "}\n"+
        "espirografo();\n" ;
        jTextArea1.setText(code);
        paleta.limpiar();
        paleta.repaint();
    }

    private void ccAction(java.awt.event.ActionEvent evt) {                                           
        String code= "proc Cuadrado(){\n"+
        "Right(90);\n"+
        "Forward($1 /2);\n"+
        "Left(90);\n"+
        "Forward($1);\n"+
        "Left(90);\n"+
        "Forward($1);\n"+
        "Left(90);\n"+
        "Forward($1);\n"+
        "Left(90);\n"+
        "Forward($1 /2);\n"+
        "Left(90);\n"+
        "}\n"+
        "proc Circulo(){\n"+
        "for(i=0;i < 360;i =i +1){\n"+
        "Left(1);\n"+
        "Forward($1);\n"+
        "}\n"+
        "}\n"+
        "proc ciclo(){\n"+
        "if($3>0){\n"+
        "Cuadrado($2);\n"+
        "Color(255,255,255);\n"+
        "Backward($2 / 4);\n"+
        "Color(0,0,0);\n"+
        "Right(90);\n"+
        "Circulo($1);\n"+
        "Left(90);\n"+
        "Color(255,255,255);\n"+
        "Backward($2 / 4);\n"+
        "Color(0,0,0);\n"+
        "ciclo($1 + $1, $2 + $2, $3 - 1);\n"+
        "}\n"+
        "}\n"+
        "ciclo(1/7, 10, 10);\n" ;
        jTextArea1.setText(code);
        paleta.limpiar();
        paleta.repaint();
    }

    private void espiralCAction(java.awt.event.ActionEvent evt) {                                         
        String code= "proc espiral(){\n"+
        "if($1 < 500){\n"+
        "Forward($1);\n"+
        "Left(90);\n"+
        "Forward($1);\n"+
        "Left(90);\n"+
        "Forward($1 + $1/10 );\n"+
        "Left(90);\n"+
        "espiral($1+ 2 * ($1/10));\n"+
        "}\n"+
        "}\n"+
        "espiral(1);\n" ;
        jTextArea1.setText(code);
        paleta.limpiar();
        paleta.repaint();
    }  

    private void estrellaDavidAction(java.awt.event.ActionEvent evt) {                                         
        String code= "Color(255,255,255);\n"+
        "Backward(200);\n"+
        "Color(0,0,0);\n"+
        "Right(34);\n"+
        "Forward(360);\n"+
        "Left(124);\n"+
        "Forward(400);\n"+
        "Left(124);\n"+
        "Forward(360);\n"+
        "Left(146);\n"+
        "Color(255,255,255);\n"+
        "Forward(400);\n"+
        "Color(0,0,0);\n"+
        "Left(180);\n"+
        "Right(34);\n"+
        "Forward(360);\n"+
        "Left(124);\n"+
        "Forward(400);\n"+
        "Left(124);\n"+
        "Forward(360);\n";
        jTextArea1.setText(code);
        paleta.limpiar();
        paleta.repaint();
    }

    private void pentagramaAction(java.awt.event.ActionEvent evt) {                                         
        String code= "proc estrella(){\n"+
                    "for(i=0;i<5;i=i+1){\n"+
                    "Forward(100);\n"+
                    "Left(144);\n"+
                    "}\n"+
                    "}\n"+
                    "Color(211, 147, 0);\n"+
                    "estrella();" ;
        jTextArea1.setText(code);
        paleta.limpiar();
        paleta.repaint();
    }  
   
    private void poligonoAction(java.awt.event.ActionEvent evt) {                                         
        String code= "proc Poligono(){\n"+
        "for(i=0;i < $1;i =i +1){\n"+
        "Left(360 / $1);\n"+
        "Forward($2);\n"+
        "}\n"+
        "}\n"+
        "Color(1, 255, 150);\n"+
        "Poligono(3, 50);\n" ;
        jTextArea1.setText(code);
        paleta.limpiar();
        paleta.repaint();
    } 
    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {                                         
        jTextArea1.setText(null);
        paleta.limpiar();
        paleta.repaint();
    }                                        

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {                                         
        String codigo=jTextArea1.getText();
        //System.out.println(codigo);
        parser= new Parser();
        paleta.setDibujo(parser.ejecutarCodigo(codigo));
        paleta.repaint();
    }                                        

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        new Logo();
    }   
}
