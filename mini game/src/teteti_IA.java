import java.util.*;

/*
 Jugada cpu es una variable que dependiendo de quien es el primero en jugar va a variar entre "X" o "O"
 */

class tateti { //clase que es el juego en si
    public static void main(String[] args) { 
        Scanner input = new Scanner(System.in);
        juego.inicio(input);
    }
}

class IA {
    String jugada_Cpu, jugada_User;

    public static String Iniciar_Jugadas(int n) {
        IA ia = new IA();

        if (n % 2 != 0) {
            ia.jugada_Cpu = "X";
            ia.jugada_User = "O";
        } else {
            ia.jugada_Cpu = "O";
            ia.jugada_User = "X";
        }

        return ia.jugada_Cpu;
    }

    public static String[][] jugar(String[][] tablero) {
        IA ia = new IA();

        // Chequear filas
        for (int i = 0; i < 3; i++) {
            if (tablero[i][0].equals(tablero[i][1]) && !tablero[i][2].equals(ia.jugada_User) && !tablero[i][2].equals(ia.jugada_Cpu)) {
                tablero[i][2] = ia.jugada_Cpu;
                return tablero;
            }
            if (tablero[i][1].equals(tablero[i][2]) && !tablero[i][0].equals(ia.jugada_User) && !tablero[i][0].equals(ia.jugada_Cpu)) {
                tablero[i][0] = ia.jugada_Cpu;
                return tablero;
            }
            if (tablero[i][0].equals(tablero[i][2]) && !tablero[i][1].equals(ia.jugada_User) && !tablero[i][1].equals(ia.jugada_Cpu)) {
                tablero[i][1] = ia.jugada_Cpu;
                return tablero;
            }
        }

        // Chequear columnas
        for (int i = 0; i < 3; i++) {
            if (tablero[0][i].equals(tablero[1][i]) && !tablero[2][i].equals(ia.jugada_User) && !tablero[2][i].equals(ia.jugada_Cpu)) {
                tablero[2][i] = ia.jugada_Cpu;
                return tablero;
            }
            if (tablero[1][i].equals(tablero[2][i]) && !tablero[0][i].equals(ia.jugada_User) && !tablero[0][i].equals(ia.jugada_Cpu)) {
                tablero[0][i] = ia.jugada_Cpu;
                return tablero;
            }
            if (tablero[0][i].equals(tablero[2][i]) && !tablero[1][i].equals(ia.jugada_User) && !tablero[1][i].equals(ia.jugada_Cpu)) {
                tablero[1][i] = ia.jugada_Cpu;
                return tablero;
            }
        }

        // Chequear diagonal principal
        if (tablero[0][0].equals(tablero[1][1]) && !tablero[2][2].equals(ia.jugada_User) && !tablero[2][2].equals(ia.jugada_Cpu)) {
            tablero[2][2] = ia.jugada_Cpu;
            return tablero;
        }
        if (tablero[1][1].equals(tablero[2][2]) && !tablero[0][0].equals(ia.jugada_User) && !tablero[0][0].equals(ia.jugada_Cpu)) {
            tablero[0][0] = ia.jugada_Cpu;
            return tablero;
        }

        // Chequear diagonal secundaria
        if (tablero[0][2].equals(tablero[1][1]) && !tablero[2][0].equals(ia.jugada_User) && !tablero[2][0].equals(ia.jugada_Cpu)) {
            tablero[2][0] = ia.jugada_Cpu;
            return tablero;
        }
        if (tablero[1][1].equals(tablero[2][0]) && !tablero[0][2].equals(ia.jugada_User) && !tablero[0][2].equals(ia.jugada_Cpu)) {
            tablero[0][2] = ia.jugada_Cpu;
            return tablero;
        }

        if (tablero[1][1].isEmpty()) tablero[1][1] = ia.jugada_Cpu;
        else                         tablero[0][0] = ia.jugada_Cpu;
        return tablero;
    }
}

class juego { // subclase que conforma a tateti

    String[][] tablero = new String[3][3];
    String jugada_Cpu, jugada_User;

    public static void inicio(Scanner input) {
        juego iniciar = new juego();

        while (true) {
            System.out.print("\033[H\033[2J");
            int option = paint.pantalla_i(input);
            if (option == 3) break;
            switch (option) {
                case 1:
                    System.out.print("\033[H\033[2J");
                    iniciar.iniciarTablero();
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

    public void iniciarTablero() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tablero[i][j] = null;
            }
        }
    }

    public void game (Scanner input) {
        Random rand = new Random();

        int r = rand.nextInt(2) + 1;

        int ganador, turno = 1;

        do {
            ganador = checkWinner();
            jugada_Cpu = IA.Iniciar_Jugadas(r);
            if (jugada_Cpu == "X") {
                jugada_User = "O";
                if (turno % 2 == 0) {
                    System.out.println("Ingrese en que casilla quiere jugar (ingrese el numero que aparece en la casilla):");
                    paint.dibujar_t(tablero);
                    String option = input.next();
                    if (!buscarIndice(option)){ 
                        System.out.println("La jugada no se encontró.");
                        continue;
                    }
                } else {
                    tablero = IA.jugar(tablero);
                }
            } else {
                jugada_User = "X";
                if (turno % 2 != 0) {
                    System.out.println("Ingrese en que casilla quiere jugar (ingrese el numero que aparece en la casilla):");
                    paint.dibujar_t(tablero);
                    String option = input.next();
                    if (!buscarIndice(option)){ 
                        System.out.println("La jugada no se encontró.");
                        continue;
                    }
                } else {
                    tablero = IA.jugar(tablero);
                }
            }
            
            ganador = checkWinner();
            turno++;
        } while (ganador == -1);

        // comprueba quien es el ganador dependiendo del resultado de la funcion checkWinner
        if (ganador == 1) System.out.println("El jugador 2 es el ganador!!!");
        else if (ganador == 0) System.out.println("El jugador 1 es el ganador!!!");
        else                   System.out.println("Ha sido un empate!!!");

        
    }
        

    private int checkWinner() {
        // Comprueba filas y columnas
        for (int i = 0; i < 3; i++) {
            if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] == "X" || tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] == "O")
                return (tablero[i][0] == "X"? 0 : 1);
            if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] == "X" || tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] == "O")
                return (tablero[0][i] == "X"? 0 : 1);
        }
        // Comprueba diagonales
        if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] == "X" || tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] == "O")
            return (tablero[0][0] == "X"? 0 : 1);
        if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] == "X" || tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] == "O")
            return (tablero[0][2] == "X"? 0 : 1);
        
        // Comprueba si hay empate
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] != "X" || tablero[i][j] != "O") return -1; // No hay ganador aún
            }
        }
        return 2; // Empate
    }

    public boolean buscarIndice(String objetivo) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j].isEmpty()) { // Comparación ignorando mayúsculas
                    tablero[i][j] = jugada_User;
                    return true; // En caso de que este vacio retorna verdadero e inserta la jugada del usuario en el espacio
                }
            }
        }
        return false; // Retorna falso
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
        System.out.println("\tBienvenido al Ta Te Ti con una semi IA!!" 
                        + "\nEste es un juego de a dos persona, o podes juarlo solo como todo buen esquizofrenico ;)"
                        + "\nElija que quiere hacer:"
                        + "\n\t1- Jugar"
                        + "\n\t2- Reglas"
                        + "\n\t3- Salir :()");
        int option = input.nextInt();

        return option;
    }

    public static void dibujar_t(String[][] tablero) { // dibuja el tablero
        for (int i = 1; i <= 3; i++) {
            System.out.print("|");
            for (int j = 0; j < 3; j++) {
                System.out.print(" " + (tablero[i][j].isEmpty()? (i*j) : tablero[i][j]) + " |");
            }
            System.out.println("\n-------------");
        }
    }
    
}