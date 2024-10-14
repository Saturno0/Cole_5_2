import java.util.*;
import java.math.*;

public class sudoku {
    public static void main(String[] args) {
        juego_sudoku juego = new juego_sudoku();
        juego.inicio();
    }
}

public class juego_sudoku {
    int t_size = 9;
    int[][] tablero = new int[3][3];
    int[] nums_valid = {1,2,3,4,5,6,7,8,9};

    public void inicio (){

        int dificultad = Dbj.pedirDifucultad();
        iniciarTablero(dificultad);
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
    public boolean check_box(int fila, int columna, int num) {
        int comienzo_fila = fila - fila % 3;
        int comienzo_columna = columna - columna % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i + comienzo_fila][j + comienzo_columna] == num) {
                    return false;
                }
            }
        }
        if (check_fila(fila, num) && check_column(columna, num)) return true;
        else return false;
    }

    public void fill_d(int fila, int columna, int[] nums) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int num : nums) {
                    if (check_box(fila, columna, num)) tablero[i + fila][j + columna] = num;
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


        for(int num : nums_valid) nums.add(num);
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
            int fila = new Random(9).nextInt();
            int columna = new Random(9).nextInt();

            if (tablero[fila][columna] == 0) continue;

            tablero[fila][columna] = 0;
            i++;
        }
    }

    public int[][] iniciarTablero(int difuculty) {
        iniciate_d();
        iniciate_r();

        int[][] c_tablero = tablero;

        while(!check_espacios(t_size)) {
            tablero = c_tablero;
            vaciar_espacios(dificulty);
        }
        
        return c_tablero;
    }

}