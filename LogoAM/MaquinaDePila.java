import java.awt.Color;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Stack;

public class MaquinaDePila {
    
    private int contador;
    private ArrayList memoria;
    private Stack pila;
    private TablaDeSimbolos tabla;
    private boolean stop = false;
    private boolean returning = false;
    private Stack<Marco> pilaDeMarcos;
    private Dibujo dibujoActual;
    
    public MaquinaDePila(TablaDeSimbolos tabla){
        dibujoActual = new Dibujo();
        contador = 0;
        memoria = new ArrayList<Method>();
        pila = new Stack();
        this.tabla = tabla;
        pilaDeMarcos = new Stack();
    }
    
    public int numeroDeElementos(){
        return memoria.size() + 1;
    }
    
    //Funciones que se escriben en memoria
    public int agregarOperacion(String nombre){
        //System.out.println("agregarOperacion "+ nombre);
        int posicion = memoria.size();
        try{
            memoria.add(this.getClass().getDeclaredMethod(nombre, null));
            return posicion;
        }
        catch(Exception e ){
            //System.out.println("Error al agregar operación " + nombre + ". ");
        }
        return -1;
    }
    
    public int agregar(Object objeto){
        //System.out.println("agregar "+ objeto);
        int posicion = memoria.size();
        memoria.add(objeto);
        return posicion;
    }
    
    public void agregar(Object objeto, int posicion){
        //System.out.println("agregar "+ objeto);
        memoria.remove(posicion);
        memoria.add(posicion, objeto);
    }
    
    public int agregarOperacionEn(String nombre, int posicion){
         //System.out.println("agregarOperacion "+ nombre);
        try{
            memoria.add(posicion, this.getClass().getDeclaredMethod(nombre, null));
        }
        catch(Exception e ){
            //System.out.println("Error al agregar operación " + nombre + ". ");
        }
        return posicion;
    }
    
    //Funciones que la máquina ejecuta sobre la pila
    private void add(){
        //System.out.println("add");
        Object matriz2 = pila.pop();
        Object matriz1 = pila.pop();
        //System.out.println(matriz1+"+"+matriz2);
		pila.push((double)matriz1 + (double)matriz2);
    }
    
    private void sub(){
        //System.out.println("sub");
        Object matriz2 = pila.pop();
        Object matriz1 = pila.pop();
        //System.out.println(matriz2+"-"+matriz1);
		pila.push((double)matriz1 - (double)matriz2);
    }

    private void mul(){
        //System.out.println("mul");
        Object matriz2 = pila.pop();
        Object matriz1 = pila.pop();
        //System.out.println(matriz1+"*"+matriz2);
		pila.push((double)matriz1 * (double)matriz2);
    }

    private void div(){
        //System.out.println("div");
        Object matriz2 = pila.pop();
        Object matriz1 = pila.pop();
        //System.out.println(matriz1+"/"+matriz2);
        pila.push((double)matriz1 / (double)matriz2);
    }
    
    private void neg(){
        //System.out.println("neg");
        Object matriz1 = pila.pop();
        //System.out.println(matriz1);
        pila.push(-(double)matriz1);
    }
    
    private void constPush(){
        //System.out.println("constPush "+ memoria.get(contador+1));
        pila.push(memoria.get(++contador));
    }
    
    private void varPush(){
        //System.out.println("varPush "+ memoria.get(1+contador));
        pila.push(memoria.get(++contador));
    }
    
    private void varPush_Eval(){
        //System.out.println("varPush_Eval "+ (String)memoria.get(1+contador) + " "+ tabla.encontrar((String)memoria.get(1+contador)) );
        pila.push(tabla.encontrar((String)memoria.get(++contador)));
    }

    private void assign(){
        //System.out.println("assign");
        String variable = (String)pila.pop();
        Object objeto = pila.pop();
        //System.out.println(variable+" = "+objeto);
        tabla.insertar(variable, objeto);
    }
    
    private void EQ(){
        Object A = pila.pop();
        Object B = pila.pop();
		pila.push((boolean)((double)A==(double)B));
    }

    private void NE(){
        Object A = pila.pop();
        Object B = pila.pop();
		pila.push((double)A!=(double)B);
    }

    private void LT(){
        //System.out.println("LT");
        double a;
        double b;
        Object B = pila.pop();
        Object A = pila.pop(); //Se sacan en orden inverso por la forma de la pila
		a = (double)A;
		b = (double)B;
        //System.out.println(a+"<"+b);
        pila.push(a < b);
    }

    private void GT(){
        //System.out.println("GT");
        double a;
        double b;
        Object B = pila.pop();
        Object A = pila.pop(); //Se sacan en orden inverso por la forma de la pila
		a = (double)A;
		b = (double)B;
        //System.out.println(a+">"+b);
        pila.push(a > b);
    }

    private void LE(){
        double a;
        double b;
        Object B = pila.pop();
        Object A = pila.pop(); //Se sacan en orden inverso por la forma de la pila
		a = (double)A;
		b = (double)B;
        pila.push(a <= b);
    }

    private void GE(){
        double a;
        double b;
        Object B = pila.pop();
        Object A = pila.pop(); //Se sacan en orden inverso por la forma de la pila
		a = (double)A;
		b = (double)B;
        pila.push(a >= b);
    }

    private void NOT(){
        pila.push(! (boolean)pila.pop());
    }

    private void AND(){
        pila.push((boolean)pila.pop() && (boolean)pila.pop());
    }

    private void OR(){
        pila.push((boolean)pila.pop() || (boolean)pila.pop());
    }
    
    private void stop(){
        stop = true;
    }
    
    private void returnCode(){
        returning = true;
    }

    private void nop(){
    }
    
    private void whileCode(){
        int condicion = contador;
        boolean continua = true;
        while(continua && !returning){
            ejecutar(condicion + 3);           
            if((boolean)pila.pop()){ //lee el resultado de la condición de la pila
                ejecutar((int)memoria.get(condicion+1));//Ejecuta el cuerpo
            }
            else{
                contador = (int)memoria.get(condicion+2); 
                continua = false;
            }
        }     
    }
    
    private void ifCode(){
        //System.out.println("IF");
        int condicion = contador;
        ejecutar(condicion + 4); //Evalúa la condicion
        boolean resultado = true;
        try{
            //System.out.println("condicion "+resultado);
            resultado = (boolean)pila.pop();
        }
        catch(Exception e ){
        }
        if(resultado){ //lee el resultado de la condición de la pila
            //System.out.println("cuerpo");
            ejecutar((int)memoria.get(condicion+1));//Ejecuta el cuerpo
        }
        else{
            //System.out.println("else");
            ejecutar((int)memoria.get(condicion+2));
        }
        contador = (int)memoria.get(condicion+3) - 1; //El -1 es para corregir el aumento del cp al final de cada instrucción
    }

    private void forCode(){
        //System.out.println("FOR");
        int condicion = contador;
        //System.out.println("INICIO");
        ejecutar(condicion + 5);  // Ejecutamos la primera parte
        boolean continua = true;
        while(continua && !returning){
            //System.out.println("condicion");
            ejecutar((int)memoria.get(condicion+1)); //evaluamos la condición        
            if((boolean)pila.pop()){ //lee el resultado de la condición de la pila
                //System.out.println("CUERPO");
                ejecutar((int)memoria.get(condicion+3));//Ejecuta el cuerpo
                //System.out.println("FINAL");
                ejecutar((int)memoria.get(condicion+2));//Ejecuta la última parte del for
            }
            else{
                contador = (int)memoria.get(condicion+4); 
                continua = false;
            }
        } 
    }
    
    private void declaracion(){
        //System.out.println("declaracion");
        tabla.insertar((String)memoria.get(++contador), ++contador); //Apuntamos a la primera instrucción de la función
        int invocados = 0;
        while(memoria.get(contador) != null || invocados != 0){ //Llevamos cp hasta la siguiente instrucción después de la declaración
            if( memoria.get(contador) instanceof Method)
                if(((Method)memoria.get(contador)).getName().equals("call"))
                    invocados++;
            if( memoria.get(contador) instanceof Funcion)
                invocados++;
            if(memoria.get(contador) == null)
                invocados--;
            contador++;
        }
    }
    
    private void call(){   
        Marco marco = new Marco();
        String nombre = (String)memoria.get(++contador);
        //System.out.println("Call "+nombre);
        marco.setNombre(nombre);
        contador++;
        while(memoria.get(contador) != null){ //Aquí también usamos null como delimitador. Aquí se agregan los parámetros al marco
            //System.out.println("buscando delimitador " + memoria.get(contador));
            if(memoria.get(contador) instanceof String){
                if(((String)(memoria.get(contador))).equals("Limite")){
                    
                    Object parametro = pila.pop();
                    //System.out.println("Parametro "+parametro);
                    marco.agregarParametro(parametro);
                    contador++;
                }
            }
            else{ 
                ejecutarInstruccion(contador);
            }

        }
        marco.setRetorno(contador);
        pilaDeMarcos.add(marco);
        ejecutarFuncion((int)tabla.encontrar(nombre)); 
    }
    
    private void push_parametro(){
        //System.out.println("PUSH PARAMETRO");
        pila.push(pilaDeMarcos.lastElement().getParametro((int)memoria.get(++contador)-1));
    }
    
    
    //Métodos para la ejecución
    public void imprimirMemoria(){
        for(int i = 0; i < memoria.size(); i++)
            System.out.println("" + i + ": " +memoria.get(i));
    }
    
    public void ejecutar(){
        //imprimirMemoria();
        stop = false;
        while(contador < memoria.size())
            ejecutarInstruccion(contador);
    }
    
    public boolean ejecutarSiguiente(){
        //imprimirMemoria();
        if(contador < memoria.size()){
            ejecutarInstruccion(contador);
            return true;
        }
        return false;
    }
    
    public void ejecutar(int indice){//ejecuta hasta que se encuentra Stop     
        contador = indice;
        while(!stop && !returning){
            ejecutarInstruccion(contador);
        }
        stop = false;
    }
    
    public void ejecutarFuncion(int indice){
        contador = indice;
        while(!returning && memoria.get(contador) != null){
            ejecutarInstruccion(contador);
        }
        returning = false;
        contador = pilaDeMarcos.lastElement().getRetorno();
        pilaDeMarcos.removeElement(pilaDeMarcos.lastElement());
    }
    
    public void ejecutarInstruccion(int indice){
        try{         
            Object objetoLeido = memoria.get(indice);
            if(objetoLeido instanceof Method){
                Method metodo = (Method)objetoLeido;
                metodo.invoke(this, null);
            }
            if(objetoLeido instanceof Funcion){
                ArrayList parametros = new ArrayList();
                Funcion funcion = (Funcion)objetoLeido;
                contador++;
                while(memoria.get(contador) != null){ //Aquí también usamos null como delimitador. Aquí se agregan los parámetros al marco
                    if(memoria.get(contador) instanceof String){
                        if(((String)(memoria.get(contador))).equals("Limite")){
                            Object parametro = pila.pop();
                            parametros.add(parametro);
                            contador++;
                        }
                    }
                    else{ 
                        ejecutarInstruccion(contador);
                    }

                }
                funcion.ejecutar(dibujoActual, parametros);
            }
            contador++;
        }
        catch(Exception e){}
    }
    
    public Dibujo getDibujo(){
        return dibujoActual;
    }
    
    public static class Left implements Funcion{
        @Override
        public void ejecutar(Object A, ArrayList parametros) {
            Dibujo dibujo = (Dibujo)A;
            int angulo = (dibujo.getAngulo() + (int)(double)parametros.get(0))%360;
            dibujo.setAngulo(angulo);
        }
    }

    public static class Right implements Funcion{
        @Override
        public void ejecutar(Object A, ArrayList parametros) {
            Dibujo dibujo = (Dibujo)A;
            int angulo = (dibujo.getAngulo() - (int)(double)parametros.get(0))%360;
            dibujo.setAngulo(angulo);
        }
    }
    
    public static class Forward implements Funcion{
        @Override
        public void ejecutar(Object A, ArrayList parametros) {
            Dibujo dibujo = (Dibujo)A;
            int angulo = dibujo.getAngulo();
            double x0 = dibujo.getX();
            double y0 = dibujo.getY();
            double x1 = x0 + Math.cos(Math.toRadians(angulo))*(double)parametros.get(0);
            double y1 = y0 + Math.sin(Math.toRadians(angulo))*(double)parametros.get(0);
            dibujo.setPosicion(x1, y1);
            dibujo.agregarLinea(new Linea((int)x0,(int)y0,(int)x1,(int)y1, dibujo.getColor()));
        }
    }
    
    public static class Backward implements Funcion{
        @Override
        public void ejecutar(Object A, ArrayList parametros) {
            Dibujo dibujo = (Dibujo)A;
            int angulo = dibujo.getAngulo();
            angulo+=180;
            angulo%=360;            
            double x0 = dibujo.getX();
            double y0 = dibujo.getY();
            double x1 = x0 + Math.cos(Math.toRadians(angulo))*(double)parametros.get(0);
            double y1 = y0 + Math.sin(Math.toRadians(angulo))*(double)parametros.get(0);
            dibujo.setPosicion(x1, y1);
            dibujo.agregarLinea(new Linea((int)x0,(int)y0,(int)x1,(int)y1, dibujo.getColor()));
        }
    }

    public static class Colour implements Funcion{
        @Override
        public void ejecutar(Object A, ArrayList parametros) {
            Dibujo dibujo = (Dibujo)A;
            dibujo.setColor(new Color((int)(double)parametros.get(0)%256, (int)(double)parametros.get(1)%256, (int)(double)parametros.get(2)%256));
        }
    }
}
