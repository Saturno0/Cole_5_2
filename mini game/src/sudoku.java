import java.util.*;

public class Sudoku {
    public static void main(String[] args) {
        juego_sudoku juego = new juego_sudoku();
        juego.inicio();
    }
}

class juego_sudoku {
    final int t_size = 9;
    int[][] tablero = new int[9][9];
    final int[] nums_valid = {1,2,3,4,5,6,7,8,9};
    Scanner input = new Scanner(System.in);
    int[] posicion_u = new int[] {0,0};
    char dir;
    int num, vidas = 3;
    Paint paint = new Paint();


    public void inicio (){
        Dibujar Dbj = new Dibujar();
        int dificultad = Dbj.pedirDificultad();
        int[][] c_tablero = iniciarTablero(dificultad);

        while(!gameOver(c_tablero)) {
            Paint.paint_t(tablero, t_size, vidas);
            Jugada(c_tablero);
        }
    }

    public boolean chekWin(int[][] c_tablero) {
        if (vidas == 0) {
            System.out.println("Que lastima has perdido :(");
            return true;
        }else if(Arrays.deepEquals(tablero, c_tablero)) {
            System.out.println("Felicidades has ganado!!");
            return true;
        }
        return false;
    }

    public boolean gameOver(int[][] c_tablero) {
        if(chekWin(c_tablero)) return true;
        return false;
    }

    public boolean is_in(char c, char[] arr) {

        for(char a : arr) {
            if(c == a) return true;
        }
        return false;
    }

    public void chek_place(int[][] c_tablero) { // chequeo la posicion en la que se encuentra el jugador y si es una casilla valida para ingresar el num
        if(tablero[posicion_u[0]][posicion_u[1]] == 0){
            if(c_tablero[posicion_u[0]][posicion_u[1]] == num ) tablero[posicion_u[0]][posicion_u[1]] = num; // compruebo que el numero ingresado sea el correcto
            else                                                Paint.err(2);

        } else Paint.err(1);
    }

    public void Move() {
        if (dir == 'w' && posicion_u[0] > 0) posicion_u[0]--;
        else if (dir == 's' && posicion_u[0] < t_size - 1) posicion_u[0]++;
        else if (dir == 'a' && posicion_u[1] > 0) posicion_u[1]--;
        else if (dir == 'd' && posicion_u[1] < t_size - 1) posicion_u[1]++;
    }

    public void Jugada(int[][] c_tablero) {
        char[] movs_valid = {'w','a','s','d'};
        char[] num_valid = {'1','2','3','4','5','6','7','8','9'};
        char c = input.next().toLowerCase().charAt(0);
        if(is_in(c, movs_valid)) {
            dir = c;
            Move();
        } else if (is_in(c, num_valid)) {
            String n = String. valueOf(c);
            num = Integer.parseInt(n);
            chek_place(c_tablero);
        } else if(!is_in(c, num_valid)) {
            vidas--;
        } else Paint.err(0);
    }

    public boolean check_column(int columna, int num) {
        for (int[] fila : tablero) {
            if (fila[columna] == num) {
                return false;
            }
        }
        return true;
    }

    // comprueba que el numero no se repita en la fila en la que se encuentra
    public boolean check_fila(int fila, int num) {
        for (int i = 0; i < tablero[fila].length; ++i) {
            if (tablero[fila][i] == num) {
                return false;
            }
        }
        return true;
    }

    // compruebo que el numero no se encuentre en el recuadro ni en la fila y columna
    public boolean check_box(int fila, int columna, int n) {
        int comienzo_fila = fila - fila % 3;
        int comienzo_columna = columna - columna % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i + comienzo_fila][j + comienzo_columna] == n) {
                    return false;
                }
            }
        }
        if (check_fila(fila, n) && check_column(columna, n)) return true;
        else return false;
    }

    public void fill_d(int fila, int columna, int[] nums) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int n : nums) {
                    if (check_box(fila, columna, n)) tablero[i + fila][j + columna] = n;
                }
            }
        }
    }

    public boolean fill_resto(int fila, int columna, int[] nums) {
        List <Integer> c_nums = new ArrayList<>();
        for(int num:nums) c_nums.add(num);

        if (columna >= t_size && fila < t_size - 1) {
            fila = fila + 1;
            columna = 0;
        }
        

        if (fila % 3 == 0 && columna % 3 == 0) {
            Collections.shuffle(c_nums);
        }

        if (fila >= t_size && columna >= t_size)
            return true; // ya termino

        if (fila < 3) {
            // omite el primer cuadro, lo hace saltar a la fila 3
            if (columna < 3)
                columna = 3;
        } else if (fila < t_size - 3) {
            // si la fila es menor a 7 busca la coordenada del columna
            if (columna == ((fila / 3) * 3)) {
                columna = columna + 3; // i=columna, columna=> columna+3
            }
        } else {
            if (columna == t_size - 3) // si columna == 7
            {
                fila = fila + 1;
                columna = 0;
                if (fila >= t_size) // sale si columna > 9
                    return true;
            }
        }

        for (int num : nums) {
            if (check_box(fila, columna, num)) {
                tablero[fila][columna] = num;
                if (fill_resto(fila, columna + 1, nums)) return true;
                tablero[fila][columna] = 0;
            }
        }

        return false;
    }

    public void iniciate_d(){
        List<Integer> nums = new ArrayList<>();


        for(int n : nums_valid) nums.add(n);
        int[] c_nums;

        for (int i = 0; i < t_size; i++) {
            Collections.shuffle(nums);
            c_nums = nums.stream().mapToInt(Integer::intValue).toArray();
            fill_d(i,i,c_nums);
        }
    }

    public void iniciate_r(){
        int[] nums = nums_valid;
        fill_resto(0, 3, nums);
    }

    public boolean check_espacios(int espacios) {
        int contador = 0;

        for (int fila = 0; fila < t_size; fila += 3) {
            for (int columna = 0; columna < t_size; columna += 3) {
                int ceros = 0; // contador de espacios vacios

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (tablero[fila + i][columna + j] == 0) ceros++;
                    }
                }

                if (espacios > 25) {
                    if (ceros < 3) return false;
                } else {
                    if (ceros < 2) return false;
                }
                contador += ceros;
            }
        }

        return contador == espacios;
    }

    public void vaciar_espacios(int espacios) {
        int i = 0;

        while (i < espacios) {
            Random rand = new Random();
            int fila = rand.nextInt(9);
            int columna = rand.nextInt(9);

            if (tablero[fila][columna] == 0) continue;

            tablero[fila][columna] = 0;
            i++;
        }
    }

    public int[][] iniciarTablero(int difuculty) {
        iniciate_d();
        iniciate_r();

        int[][] c_tablero = tablero;

        while(!check_espacios(difuculty)) {
            tablero = c_tablero;
            vaciar_espacios(difuculty);
        }
    
        return c_tablero;
    }

}

class Dibujar {
    Scanner input = new Scanner(System.in);
    public int pedirDificultad(){
        int dificulty;
        while (true) {
            System.out.println("Ingrese que tipo de dificultad quiere jugar:\n" +
                        "\t1-Facil\n" + "\t2-Medio" + "\t3-Dificil");
        
            int option = input.nextInt();
            switch (option) {
                case 1:
                    dificulty = 25;
                    break;
                case 2:
                    dificulty = 30;
                    break;
                case 3:
                    dificulty = 40;
                    break;
            
                default:
                    System.out.println("Ingrese una opcion valida por favor");
                    continue;
            }
            break;
        }

        return dificulty;
    }

}

class Paint {
    public static void paint_t(int[][] tablero, int tamano, int vidas) {
        APB(vidas);

        System.out.println("  --- --- ---  --- --- ---  --- --- --- \n" + "  --- --- ---  --- --- ---  --- --- --- ");
        for(int[] fila : tablero) {
            System.out.print("||");
            for(int n : fila) {
                if(n == 0) System.out.print("   |");
                else       System.out.print(" " + n + " |");
            }
            System.out.println("||");
            System.out.println("  --- --- ---  --- --- ---  --- --- --- ");
        }
    }

    public static void APB(int vidas) {
        System.out.println("------------------------------------------------------------");
        System.out.println("| APB | w: arriba - a: izquierda - s: abajo - d: derecha   |");
        System.out.println("------------------------------------------------------------");
        System.out.println("| APB | Parese sobre la casilla para ingresar el numero    |");
        System.out.println("------------------------------------------------------------");
        System.out.println("Vidas: " + vidas);
    }

    public static void err(int n) {
        switch (n) {
            case 0:
                System.out.println("Jugada no valida");
                break;
            
            case 1:
                System.out.println("Espacio ya ocupado");
        
            default:
                break;
        }
    }
}