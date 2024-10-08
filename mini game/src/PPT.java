import java.util.*;



public class PPT { // clase del juego
	 // variables que vamos a usar a lo largo del juego
	static final int[] jugadas_validas = {0,1,2};
	static final int[][] comparacion = {{0,1,2}, {1,2,0}};
	
	Scanner input = new Scanner(System.in);

	public int usuario = 0, cpu = 0;
	
	private static boolean is_in(int n, int[] array) { // esta funcion nos facilita para saber si un numero se encuentra en una array
		for (int i : array) {
			if (n == i) return true;
		}
		return false;
	}
	
	public static void main(String[] args) throws InterruptedException{ 
		PPT juego = new PPT();
		
		juego.pantallaInicio();// llamo a la funcion de pantalla inicio la cual da comienzo a todo el juego
	}
	

	
	private void pantallaInicio() throws InterruptedException{
		
		while (true) {
			System.out.print("\033[H\033[2J");
			System.out.println("Bienvenido al juego de piedra, papel o tijera, en que dificultad quiere jugar?"
					+ "\n1-Facil(el mejor de 3)"
					+ "\n2-Medio(el mejor de 5)"
					+ "\n3-Dificil(el mejor de 10)"
					+ "\n4-Salir");
			int option = input.nextInt();
		
			if (option == 4) break;
		
			switch(option) {
			case 1:
				facil(3);
				break;
			case 2:
				medio(5);
				break;
			case 3:
				dificil(10);
				break;
			default:
				break;
			}

			if (cpu > usuario) System.out.println("El ganador final es la computadora");
			else 			   System.out.println("El ganador final es el jugador");
			System.out.println("Muchas gracias por jugar con nosotros :)");

			Thread.sleep(3500);
		}
	}
	
	public void facil(int partidas) { // la dificultad en la que la cpu va a elegir su jugada
		PPT juego = new PPT();
		int i = 0;
		while (i < partidas) {
			int jugada_user = game(0);
			int jugada_cpu = game(1);
			
			if (juego.checkWinner(jugada_user, jugada_cpu) == 1) continue;
			i++;
		}
	}

	public void medio(int partidas) { // la dificultad en la que la cpu va a elegir su jugada
		PPT juego = new PPT();
		ArrayList <Integer> jugadas_user = new ArrayList<Integer>();
		jugadas_user.add(0); jugadas_user.add(1); jugadas_user.add(2);
		int i = 0;
		while(i < partidas) {
			int jugada_user = game(0);
			int jugada_cpu = calcular_JM(jugadas_user);
			jugadas_user.add(jugada_user);

			if (juego.checkWinner(jugada_user, jugada_cpu) == 1) continue;
			i++;
		}
	}

	public void dificil(int partidas) { 
		PPT juego = new PPT();
		ArrayList <Integer> jugadas_user = new ArrayList<Integer>();
		jugadas_user.add(0); jugadas_user.add(1); jugadas_user.add(2);
		int i = 0;
		while(i < partidas) {
			int jugada_user = game(0);
			int jugada_cpu = calcular_JD(jugadas_user);
			jugadas_user.add(jugada_user);

			if (juego.checkWinner(jugada_user, jugada_cpu) == 1) continue;
			i++;
		}
	}
	
	public int game(int jugador) {
		if (jugador == 0 ) {
			System.out.println("Ingrese cual va a ser su jugada:\n1-Piedra\n2-Papel\n3-Tijera");

			while (true) {
				int option = input.nextInt();
				if (!is_in(option - 1, jugadas_validas)) {
					System.out.print("Ingrese una opcion valida (\n" +
												"1-Piedra\n" +
												"2-Papel\n" +
												"3-Tijera): ");
					continue;
				} else return option - 1;
			}

		} else {
			Random rand = new Random();
			int r = rand.nextInt(3);
			return jugadas_validas[r];
		}
	}
	
	public static int calcular_JM(ArrayList<Integer> jugadas_user) {
		int f_pd = 0, f_pp = 0, f_t = 0;
		Random rand = new Random();
		for (int n : jugadas_user) {
			if (n == 0) {
				f_pd++;
			} else if (n == 1) {
				f_pp++;
			} else {
				f_t++;
			}
		}

		// Determinar la jugada más probable del usuario y qué jugada debe hacer la CPU
		if (f_pd > f_pp && f_pd > f_t) {
		    // Piedra es la jugada más común, la CPU juega Papel
		    return 1;  // Papel vence a Piedra
		} else if (f_pp > f_pd && f_pp > f_t) {
		    // Papel es la jugada más común, la CPU juega Tijera
		    return 2;  // Tijera vence a Papel
		} else if (f_t > f_pd && f_t > f_pp) {
		    // Tijera es la jugada más común, la CPU juega Piedra
		    return 0;  // Piedra vence a Tijera
		} else if (f_pd == f_pp && f_pp == f_t) {
		    // Si las tres jugadas tienen la misma frecuencia, la CPU elige al azar
		    return rand.nextInt(3);  // 0 = Piedra, 1 = Papel, 2 = Tijera
		} else if (f_pd == f_pp) {
		    // Si Piedra y Papel tienen la misma frecuencia, la CPU elige entre Tijera o una jugada al azar
		    if (rand.nextInt(2) == 0) {
		        return 2;  // Tijera vence a ambos
		    } else {
		        return rand.nextInt(2);  // Al azar entre Piedra (0) o Papel (1)
		    }
		} else if (f_pp == f_t) {
		    // Si Papel y Tijera tienen la misma frecuencia, la CPU elige entre Piedra o Tijera
		    if (rand.nextInt(2) == 0) {
		        return 0;  // Piedra vence a Tijera
		    } else {
		        return 2;  // Tijera vence a Papel
		    }
		} else {
		    // Si Piedra y Tijera tienen la misma frecuencia, la CPU elige entre Papel o Tijera
		    if (rand.nextInt(2) == 0) {
		        return 1;  // Papel vence a Piedra
		    } else {
		        return 2;  // Tijera
		    }
		}
	}

	private static int calcular_JD(ArrayList<Integer> jugadas_user) {
		Random rand = new Random();
		int n = jugadas_user.get(rand.nextInt(jugadas_user.size()));
		return n;
	}


	private int checkWinner(int jugada_user, int jugada_cpu) {
		if (jugada_user == comparacion[1][jugada_cpu]) {
			System.out.println("Has ganado!! :)");
			usuario++;
			return 0;
		} else if (jugada_user == jugada_cpu) {
			System.out.println("Uff empate");
			return 1;
		} else {
			System.out.println("Uhhh, que lastima. Has perdido :(");
			cpu++;
			return 0;
		}
	}
}
