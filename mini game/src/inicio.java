import java.util.HashMap;
import java.util.*;

public class inicio {
	
	static final int[] jugadas_validas = {0,1,2};
	
	public boolean is_in(int n, int[] array) {
		for (int i : array) {
			if (n == i) return true;
		}
		return false;
	}
	
	public static void main(String[] args) { 
		pantallaInicio();
	}
	
	private static void pantallaInicio() {
		Scanner input = new Scanner(System.in);
		
		while (true) {
			System.out.print("Bienvenido al juego de piedra, papel o tijera, en que dificultad quiere jugar?"
					+ "\n1-Facil(el mejor de 3)"
					+ "\n2-Medio(el mejor de 3)"
					+ "\n3-Dificil(el mejor de 5)"
					+ "\n4-Salir");
		int option = input.nextInt();
		
		if (option == 4) break;
		
		switch(option) {
		case 1:
			facil(3);
			break;
		case 2:
			medio(3);
			break;
		case 3:
			dificil(5);
			break;
		default:
			break;
		}
		
		System.out.println("Muchas gracias por jugar con nosotros :)");
		}
	}
	
	public static void facil(int partidas) {
		int i = 0;
		while (i < partidas) {
			int jugada_user = game(0);
			int jugada_cpu = game(1);
			
			int Ganador = checkWinner(jugada_user, jugada_cpu);
			i++;
		}
	}
	
	public int game(int jugador) {
		if (jugador == 0 ) {
			Scanner input = new Scanner(System.in);
			
		} else {
			
		}
	}
}
