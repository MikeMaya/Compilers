import java.awt.Color;
import javax.swing.ImageIcon;
import java.awt.Image;
import java.awt.RenderingHints;
import java.awt.image.BufferedImage;
import java.awt.Graphics2D;
import java.awt.Graphics;
import java.awt.Polygon;
import java.util.ArrayList;
import javax.swing.JPanel;

public class Paleta extends JPanel{
    private Dibujo dibujo;
    private int ANCHO;    
    private int LARGO;
    private Image turtle;
    public Paleta(int a, int l){
        ANCHO=a;
        LARGO=l;
        dibujo= new Dibujo();
        loadTurtle();
    }
    
    public void limpiar(){
        dibujo= new Dibujo();
    }

    private void loadTurtle(){
        ImageIcon image = new ImageIcon("turtle.png");
        turtle=getScaledImage(image.getImage(), 20, 20);
    }

    private Image getScaledImage(Image srcImg, int w, int h){
        BufferedImage resizedImg = new BufferedImage(w, h, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g2 = resizedImg.createGraphics();

        g2.setRenderingHint(RenderingHints.KEY_INTERPOLATION, RenderingHints.VALUE_INTERPOLATION_BILINEAR);
        g2.drawImage(srcImg, 0, 0, w, h, null);
        g2.dispose();

        return resizedImg;
    }

    public void setDibujo(Dibujo dibujo){
        this.dibujo = dibujo;
    }
    
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        int lastx=ANCHO/2, lasty=LARGO/2;
        ArrayList<Linea> lineas = dibujo.getLineas();
        for(int i = 0; i < lineas.size(); i++){
            int x0 = (ANCHO/2) + lineas.get(i).getX0();
            int y0 = (LARGO/2) - lineas.get(i).getY0();
            int x1 = (ANCHO/2) + lineas.get(i).getX1();
            int y1 = (LARGO/2) - lineas.get(i).getY1();;
            lastx=x1;
            lasty=y1;
            g.setColor(lineas.get(i).getColor());
            g.drawLine(x0, y0, x1, y1);
        }
        g.drawImage(turtle,lastx-10, lasty-10, 20, 20, null);
    }
    
}