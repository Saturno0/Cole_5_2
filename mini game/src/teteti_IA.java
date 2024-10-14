// import java.util.*;

// class IA_tateti { //clase que es el juego en sí
//     public static void main(String[] args) { 
//         Scanner input = new Scanner(System.in);
//         juego.inicio(input);
//     }
// }

// class IA {
//     String jugada_Cpu, jugada_User;

//     public String Iniciar_Jugadas(int n) {

//         if (n % 2 != 0) {
//             this.jugada_Cpu = "X";
//             this.jugada_User = "O";
//         } else {
//             this.jugada_Cpu = "O";
//             this.jugada_User = "X";
//         }

//         return this.jugada_Cpu;
//     }

//     public static String[][] jugar(String[][] tablero, String jugada_Cpu, String jugada_User) {
//         // Chequear filas
//         for (int i = 0; i < 3; i++) {
//             if (tablero[i][0].equals(tablero[i][1]) && !tablero[i][2].equals(jugada_User) && tablero[i][2].equals(" ")) {
//                 tablero[i][2] = jugada_Cpu;
//                 return tablero;
//             }
//             if (tablero[i][1].equals(tablero[i][2]) && !tablero[i][0].equals(jugada_User) && tablero[i][0].equals(" ")) {
//                 tablero[i][0] = jugada_Cpu;
//                 return tablero;
//             }
//             if (tablero[i][0].equals(tablero[i][2]) && !tablero[i][1].equals(jugada_User) && tablero[i][1].equals(" ")) {
//                 tablero[i][1] = jugada_Cpu;
//                 return tablero;
//             }
//         }

//         // Chequear columnas
//         for (int i = 0; i < 3; i++) {
//             if (tablero[0][i].equals(tablero[1][i]) && !tablero[2][i].equals(jugada_User) && tablero[2][i].equals(" ")) {
//                 tablero[2][i] = jugada_Cpu;
//                 return tablero;
//             }
//             if (tablero[1][i].equals(tablero[2][i]) && !tablero[0][i].equals(jugada_User) && tablero[0][i].equals(" ")) {
//                 tablero[0][i] = jugada_Cpu;
//                 return tablero;
//             }
//             if (tablero[0][i].equals(tablero[2][i]) && !tablero[1][i].equals(jugada_User) && tablero[1][i].equals(" ")) {
//                 tablero[1][i] = jugada_Cpu;
//                 return tablero;
//             }
//         }

//         // Chequear diagonal principal
//         if (tablero[0][0].equals(tablero[1][1]) && !tablero[2][2].equals(jugada_User) && tablero[2][2].equals(" ")) {
//             tablero[2][2] = jugada_Cpu;
//             return tablero;
//         }
//         if (tablero[1][1].equals(tablero[2][2]) && !tablero[0][0].equals(jugada_User) && tablero[0][0].equals(" ")) {
//             tablero[0][0] = jugada_Cpu;
//             return tablero;
//         }

//         // Chequear diagonal secundaria
//         if (tablero[0][2].equals(tablero[1][1]) && !tablero[2][0].equals(jugada_User) && tablero[2][0].equals(" ")) {
//             tablero[2][0] = jugada_Cpu;
//             return tablero;
//         }
//         if (tablero[1][1].equals(tablero[2][0]) && !tablero[0][2].equals(jugada_User) && tablero[0][2].equals(" ")) {
//             tablero[0][2] = jugada_Cpu;
//             return tablero;
//         }

//         // Si no hay jugada ganadora, juega en el centro o la primera casilla disponible
//         if (tablero[1][1].equals(" ")) tablero[1][1] = jugada_Cpu;
//         else                          tablero[0][0] = jugada_Cpu;

//         return tablero;
//     }
// }

// class juego {

//     String[][] tablero = new String[3][3];
//     String jugada_Cpu, jugada_User;

//     public static void inicio(Scanner input) {
//         juego iniciar = new juego();

//         while (true) {
//             System.out.print("\033[H\033[2J");
//             int option = paint.pantalla_i(input);
//             if (option == 3) break;
//             switch (option) {
//                 case 1:
//                     iniciar.iniciarTablero();
//                     iniciar.game(input);
//                     break;
//                 case 2:
//                     paint.Reglas();
//                     delay();
//                     break;
//                 default:
//                     break;
//             }
//         }
//     }

//     public static void delay() {
//         try {
//             System.in.read();
//         } catch (Exception e) {
//             e.printStackTrace();
//         }
//     }

//     public void iniciarTablero() {
//         for (int i = 0; i < 3; i++) {
//             for (int j = 0; j < 3; j++) {
//                 tablero[i][j] = " "; // Inicializar con un espacio para casillas vacías
//             }
//         }
//     }

//     public void game(Scanner input) {
//         Random rand = new Random();
//         IA IA = new IA();
//         int r = rand.nextInt(2);
//         jugada_Cpu = IA.Iniciar_Jugadas(r);
//         jugada_User = (jugada_Cpu.equals("X")) ? "O" : "X";
//         int ganador, turno = 1;

//         do {
//             ganador = checkWinner();

//             if(jugada_User.equals("X")) {
//                 if (turno % 2 != 0) {
//                     System.out.println("Turno del usuario. Ingrese la casilla:");
//                     paint.dibujar_t(tablero);
//                     String option = input.next();
//                     if (!buscarIndice(option)) {
//                         System.out.println("La jugada no se encontró.");
//                         continue;
//                     }
//                 } else {
//                     tablero = IA.jugar(tablero, jugada_Cpu, jugada_User);
//                 }
//             } else {
//                 if (turno % 2 == 0) {
//                     System.out.println("Turno del usuario. Ingrese la casilla:");
//                     paint.dibujar_t(tablero);
//                     String option = input.next();
//                     if (!buscarIndice(option)) {
//                         System.out.println("La jugada no se encontró.");
//                         continue;
//                     }
//                 } else {
//                     tablero = IA.jugar(tablero, jugada_Cpu, jugada_User);
//                 }
//             }

//             ganador = checkWinner();
//             turno++;
//         } while (ganador == -1);

//         // Resultado del juego
//         if (ganador == 1) System.out.println("El jugador 2 es el ganador!!!");
//         else if (ganador == 0) System.out.println("El jugador 1 es el ganador!!!");
//         else System.out.println("Ha sido un empate!!!");

//         delay();
//     }

//     private int checkWinner() {
//         // Comprueba filas y columnas
//         for (int i = 0; i < 3; i++) {
//             if (tablero[i][0].equals(tablero[i][1]) && tablero[i][1].equals(tablero[i][2]) && !tablero[i][0].equals(" "))
//                 return (tablero[i][0].equals("X") ? 0 : 1);
//             if (tablero[0][i].equals(tablero[1][i]) && tablero[1][i].equals(tablero[2][i]) && !tablero[0][i].equals(" "))
//                 return (tablero[0][i].equals("X") ? 0 : 1);
//         }
//         // Comprueba diagonales
//         if (tablero[0][0].equals(tablero[1][1]) && tablero[1][1].equals(tablero[2][2]) && !tablero[0][0].equals(" "))
//             return (tablero[0][0].equals("X") ? 0 : 1);
//         if (tablero[0][2].equals(tablero[1][1]) && tablero[1][1].equals(tablero[2][0]) && !tablero[0][2].equals(" "))
//             return (tablero[0][2].equals("X") ? 0 : 1);

//         // Comprueba si hay empate
//         for (int i = 0; i < 3; i++) {
//             for (int j = 0; j < 3; j++) {
//                 if (tablero[i][j].equals(" ")) return -1; // No hay ganador aún
//             }
//         }
//         return 2; // Empate
//     }

//     public boolean buscarIndice(String objetivo) {
//         int index = Integer.parseInt(objetivo) - 1;
//         int row = index / 3;
//         int col = index % 3;
//         if (tablero[row][col].equals(" ")) {
//             tablero[row][col] = jugada_User;
//             return true;
//         }
//         return false;
//     }
// }

// class paint { // subclase que conforma a juego

//     public static void Reglas() { // imprime todas las reglas del juego
//         System.out.println("=== Reglas del Juego Tateti (Tres en línea) ===");
//         System.out.println("1. El juego se juega en un tablero de 3x3.");
//         System.out.println("2. El objetivo es ser el primero en conseguir tres de tus símbolos (X o O) en una fila, columna o diagonal.");
//         System.out.println("3. El juego comienza con el Jugador 1 usando 'X' y el Jugador 2 usando 'O'.");
//         System.out.println("4. Los jugadores se turnan para colocar su símbolo en una casilla vacía del tablero.");
//         System.out.println("5. Para realizar una jugada, cada jugador debe ingresar la posición deseada en el tablero.");
//         System.out.println("   - El tablero está numerado del 1 al 9 de la siguiente manera:");
//         System.out.println("      1 | 2 | 3");
//         System.out.println("     -----------");
//         System.out.println("      4 | 5 | 6");
//         System.out.println("     -----------");
//         System.out.println("      7 | 8 | 9");
//         System.out.println("6. Un jugador gana si logra alinear tres símbolos en una fila, columna o diagonal.");
//         System.out.println("7. Si todas las casillas están llenas y ningún jugador ha ganado, el juego termina en empate.");
//         System.out.println("8. El juego se reinicia si hay un ganador o empate.");
//         System.out.println("===============================================");
//     }

//     public static int pantalla_i(Scanner input) { // imprime la pantalla de inicio
//         System.out.println("\tBienvenido al Ta Te Ti con una semi IA!!" 
//                         + "\nEste es un juego de a dos personas, o puedes jugarlo solo ;) "
//                         + "\nElija que quiere hacer:"
//                         + "\n\t1- Jugar"
//                         + "\n\t2- Reglas"
//                         + "\n\t3- Salir :(");
//         return input.nextInt();
//     }

//     public static void dibujar_t(String[][] tablero) { // dibuja el tablero
//         for (int i = 0; i < 3; i++) {
//             System.out.println("-------------");
//             System.out.print("|");
//             for (int j = 0; j < 3; j++) {
//                 System.out.print(" " + (tablero[i][j].equals(" ") ? (i * 3 + j + 1) : tablero[i][j]) + " |");
//             }
//             System.out.println();
//         }
//         System.out.println("-------------");
//     }
// }
