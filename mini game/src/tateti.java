import java.util.*;

class tateti { //clase que es el juego en si
    public static void main(String[] args) { 
        Scanner input = new Scanner(System.in);
        juego.inicio(input);
    }
}

class juego { // subclase que conforma a tateti

    String[][] jugadas = new String[3][3];

    public static void inicio(Scanner input) {
        juego iniciar = new juego();

        while (true) {
            System.out.print("\033[H\033[2J");
            int option = paint.pantalla_i(input);
            if (option == 3) break;
            switch (option) {
                case 1:
                    System.out.print("\033[H\033[2J");
                    iniciar.iniciarJugadas();
                    iniciar.game(input);
                    break;

                case 2:
                    System.out.print("\033[H\033[2J");
                    paint.Reglas();
                    delay(input);
                    break;

                default:
                    break;
            }
        }
    }

    public static void delay(Scanner input) {
        try {
            System.in.read();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void iniciarJugadas() {
        int num = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                jugadas[i][j] = String.valueOf(num);
                num++;
            }
        }
    }

    public void game (Scanner input) {
        int turno = 1;
        int ganador;
        do {
            ganador = checkWinner();
            System.out.println("Ingrese en que casilla quiere jugar (ingrese el numero que aparece en la casilla):");
            paint.dibujar_t(jugadas);
            String option = input.next();
            if (!buscarIndice(option, turno)){ 
                System.out.println("La jugada no se encontró.");
                continue;
            }
            turno +=1;
            ganador = checkWinner();
        } while (ganador == -1);

        // comprueba quien es el ganador dependiendo del resultado de la funcion checkWinner
        if (ganador == 1) System.out.println("El jugador 2 es el ganador!!!");
        else if (ganador == 0) System.out.println("El jugador 1 es el ganador!!!");
        else                   System.out.println("Ha sido un empate!!!");

        
    }
        

    private int checkWinner() {
        // Comprueba filas y columnas
        for (int i = 0; i < 3; i++) {
            if (jugadas[i][0] == jugadas[i][1] && jugadas[i][1] == jugadas[i][2] && jugadas[i][0] == "X" || jugadas[i][0] == jugadas[i][1] && jugadas[i][1] == jugadas[i][2] && jugadas[i][0] == "O")
                return (jugadas[i][0] == "X"? 0 : 1);
            if (jugadas[0][i] == jugadas[1][i] && jugadas[1][i] == jugadas[2][i] && jugadas[0][i] == "X" || jugadas[0][i] == jugadas[1][i] && jugadas[1][i] == jugadas[2][i] && jugadas[0][i] == "O")
                return (jugadas[0][i] == "X"? 0 : 1);
        }
        // Comprueba diagonales
        if (jugadas[0][0] == jugadas[1][1] && jugadas[1][1] == jugadas[2][2] && jugadas[0][0] == "X" || jugadas[0][0] == jugadas[1][1] && jugadas[1][1] == jugadas[2][2] && jugadas[0][0] == "O")
            return (jugadas[0][0] == "X"? 0 : 1);
        if (jugadas[0][2] == jugadas[1][1] && jugadas[1][1] == jugadas[2][0] && jugadas[0][2] == "X" || jugadas[0][2] == jugadas[1][1] && jugadas[1][1] == jugadas[2][0] && jugadas[0][2] == "O")
            return (jugadas[0][2] == "X"? 0 : 1);
        
        // Comprueba si hay empate
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (jugadas[i][j] != "X" || jugadas[i][j] != "O") return -1; // No hay ganador aún
            }
        }
        return 2; // Empate
    }

    public boolean buscarIndice(String objetivo, int turno) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (jugadas[i][j].equalsIgnoreCase(objetivo)) { // Comparación ignorando mayúsculas
                    if (turno % 2 != 0) {jugadas[i][j] = "X";}
                    else                {jugadas[i][j] = "O";}
                    return true; // Retorna el índice si coincide
                }
            }
        }
        return false; // Retorna -1 si no se encuentra
    }

}

class paint { // subclase que conforma a juego

    public static void Reglas() { // imprime todas las reglas del juego
        System.out.println("=== Reglas del Juego Tateti (Tres en línea) ===");
        System.out.println("1. El juego se juega en un tablero de 3x3.");
        System.out.println("2. El objetivo es ser el primero en conseguir tres de tus símbolos (X o O) en una fila, columna o diagonal.");
        System.out.println("3. El juego comienza con el Jugador 1 usando 'X' y el Jugador 2 usando 'O'.");
        System.out.println("4. Los jugadores se turnan para colocar su símbolo en una casilla vacía del tablero.");
        System.out.println("5. Para realizar una jugada, cada jugador debe ingresar la posición deseada en el tablero.");
        System.out.println("   - El tablero está numerado del 1 al 9 de la siguiente manera:");
        System.out.println("      1 | 2 | 3");
        System.out.println("     -----------");
        System.out.println("      4 | 5 | 6");
        System.out.println("     -----------");
        System.out.println("      7 | 8 | 9");
        System.out.println("6. Un jugador gana si logra alinear tres símbolos en una fila, columna o diagonal.");
        System.out.println("7. Si todas las casillas están llenas y ningún jugador ha ganado, el juego termina en empate.");
        System.out.println("8. El juego se reinicia si hay un ganador o empate.");
        System.out.println("===============================================");

    }
    
    
    public static int pantalla_i(Scanner input) { // imprime la pantalla de inicio
        System.out.println("\tBienvenido al Ta Te Ti!!" 
                        + "\nEste es un juego de a dos persona, o podes juarlo solo como todo buen esquizofrenico ;)"
                        + "\nElija que quiere hacer:"
                        + "\n\t1- Jugar"
                        + "\n\t2- Reglas"
                        + "\n\t3- Salir :()");
        int option = input.nextInt();

        return option;
    }

    public static void dibujar_t(String[][] jugadas) { // dibuja el tablero
        for (int i = 0; i < 3; i++) {
            System.out.print("|");
            for (int j = 0; j < 3; j++) {
                System.out.print(" " + jugadas[i][j] + " |");
            }
            System.out.println("\n-------------");
        }
    }
    
}