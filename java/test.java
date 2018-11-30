
import java.util.Random;
abstract class Prueba implements Runnable{
	public static int numeroPublico;
	public Prueba(){numeroPublico = 1;}
	
	public int Modifica(int numero){
		return numeroPublico = 1;
	}
	abstract void imprime();
	
	public void run(){

	}
	
	public static int pruebaMetodo(){
		return 1;
	}
}
class Examen extends Prueba{
	public Examen(){
	}
	@Override
	public void run(){
		imprime();
	}
	public void imprime(){
		for (int i = 0; i < 10; i++) {
            System.out.println("Examen " + i);
            try {Thread.sleep(100);} 
            catch (InterruptedException e) {e.printStackTrace();}
        }
	}
}
public class test{
	public static void main(String[] args){
		System.out.println(Prueba.pruebaMetodo());
	}
}