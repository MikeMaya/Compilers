import java.util.ArrayList;
import java.util.Vector;

public class TablaDeSimbolos {
    ArrayList<Pareja> simbolos;
    
    public TablaDeSimbolos(){
        simbolos = new ArrayList<Pareja>();
    }

    public Object encontrar(String nombre){
        for(int i = 0; i < simbolos.size(); i++)
            if(nombre.equals(simbolos.get(i).getNombre()))
                return simbolos.get(i).getObjeto();
        return null;
    }

    public boolean insertar(String nombre, Object objeto){
        Pareja par = new Pareja(nombre, objeto);
        for(int i = 0; i < simbolos.size(); i++)
            if(nombre.equals(simbolos.get(i).getNombre())){
                simbolos.get(i).setObjeto(objeto);
                return true;
            }
        simbolos.add(par);
        return false;
    }

    public void imprimir(){
        for(int i = 0; i < simbolos.size(); i++){
            System.out.println(simbolos.get(i).getNombre() + simbolos.get(i).getObjeto().toString());
        }
    }
}
