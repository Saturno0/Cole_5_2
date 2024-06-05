#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <algorithm>
#include <random>
#include <numeric>

using namespace std;

class sudoku {
private:
    string rojo = "\033[1;31m";
    string reset = "\033[0m";
    vector<vector<int>> tablero;
    // genero una array para los numeros validos
    vector <int> nums_validos {1,2,3,4,5,6,7,8,9};

    bool check_column(int columna, int num) {
        for (int i = 0; i < tablero.size(); ++i) {
            if (tablero[i][columna] == num) {
                return false;
            }
        }
        return true;
    }

    bool check_fila(int fila, int num) {
        for (int i = 0; i < tablero[fila].size(); ++i) {
            if (tablero[fila][i] == num) {
                return false;
            }
        }
        return true;
    }

    bool check_box(int fila, int columna, int num) {
        int comienzo_fila = fila - fila % 3;
        int comienzo_columna = columna - columna % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i + comienzo_fila][j + comienzo_columna] == num) {
                    return false;
                }
            }
        }
        if(check_fila(fila, num) && check_column(columna, num)) return true;
        else                                                    return false;
    }

    bool fill_resto(int fila, int columna, vector <int> nums, int size) {
        if (columna>=size && fila<size-1) {
            fila = fila + 1;
            columna = 0;
        }
        
        if (fila % 3 == 0 && columna % 3 == 0) {
            random_shuffle(nums.begin(), nums.end());
        }

        if (fila>=size && columna>=size)
            return true; //ya termino

        if (fila < 3) {
            //omite el primer cuadro, lo hace saltar a la fila 3
            if (columna < 3)
                columna = 3;
        }
        else if (fila < size-3) {
            //si la fila es menor a 7 busca la coordenada del columna
            if (columna==int((fila/3)*3)) {                
                columna =  columna + 3; //i=columna, columna=> columna+3
            }        
        } else
        {
            if (columna == size-3) //si columna == 7
            {
                fila = fila + 1;
                columna = 0;
                if (fila>=size) //sale si columna > 9
                    return true;
            }
        }


        for (int num : nums) {
            if (check_box(fila,columna,num)) {
                tablero[fila][columna] = num;
                if (fill_resto(fila,columna + 1, nums, size)) return true;
                tablero[fila][columna] = 0;
            }
        }

        return false;
    }

    void fill_diagonales(int fila, int columna, vector <int> nums, int size) {
        int rsize = sqrt(size);

        for (int i = 0; i<rsize; i++) {
            for (int j = 0; j<rsize; j++) {
                for (int num : nums) {
                    if (check_box(fila,columna,num)) tablero[i+fila][j+columna] = num;
                }
            }
        }
    }

    void iniciar_diagonales(int size) {
        int rsize = sqrt(size);
        vector <int> nums = nums_validos;

        for (int i = 0; i < size; i+=rsize) {
            random_shuffle(nums.begin(), nums.end());
            fill_diagonales(i,i,nums,size);
        }

    }

    void iniciar_resto(int size) {
        int rsize = sqrt(size);
        
        for (int i = 0; i < size; i+=rsize){
            for (int j = 0; j < size; j+=rsize) {
                if (i == 0) j+=rsize;
                else if (i == 3 && j == 3) j+=rsize;
                else if (i == 6 && j == 6) break;

                fill_resto(i,j, nums_validos,size);
            }
        }
    }


    void iniciar_tablero(int dificultad) {
        tablero.clear();
        tablero.resize(dificultad, vector<int>(dificultad, 0));


        iniciar_diagonales(dificultad);
        iniciar_resto(dificultad);


    }



    void vaciar_espacios(int espacios) {
        int i = 0;

        while (i < espacios) {
            int fila = rand() % 9;
            int columna = rand() % 9;

            if (tablero[fila][columna] == 0) continue;

            tablero[fila][columna] = 0;
            i++;
        }
    }


    int pedir_dificultad() {
        int opcion, dificultad;
        cout << "Bienvenido al sudoku, espero se entretenga" << endl <<"[*] Elija una dificultad para jugar:\n 1- Facil(10 espacios blancos)\n 2- Intermedio(15 espacios blancos)\n 3- Dificil(25 espacios blancos)" << endl;
        while (true) {
            cin >> opcion;
            switch (opcion) {
                case 1:
                    dificultad = 3;
                    break;
                case 2:
                    dificultad = 6;
                    break;
                case 3:
                    dificultad = 9;
                    break;
                default:
                    cout << rojo << "[!] Opcion incorrecta. Por favor ingrese una opcion correcta" << reset << endl;
                    continue; // Continúa el bucle hasta que se reciba una opción válida
            }
            break; // Sal del bucle si se recibe una opción válida
        }
        return dificultad;
    }

    void juego() {
        // int dificultad = pedir_dificultad();
        iniciar_tablero(9);
        cout << "Tablero generado con dificultad " << 9 << ":" << endl;
        dibujar_tablero();
    }

    void dibujar_tablero() {
        // system("cls"); // limpia la terminal en Windows
        // system("clear"); // limpia la terminal en Unix-like
        int j = 0;
        for (const auto& fila : tablero) {
            
            if (j % 3 == 0 && j != 0) {
                if (j != 9) cout << " --- --- ---  --- --- ---  --- --- --- " << endl << " --- --- ---  --- --- ---  --- --- --- " << endl;
            } else {
                 cout << " --- --- ---  --- --- ---  --- --- --- " << endl;
            }
            
            cout << "|";
            int i = 0;
            for (int num : fila) {
                if (num != 0) {
                    cout << " " << num << " ";
                } else {
                    cout << "   ";
                }
                if ((i+1)%3 == 0 && i != 0) {
                    if (i+1 != 9) cout << "||";
                    else          cout << "|";
                }
                else          cout << "|";
                i++;
            }
            cout << endl;
            j++;
        }
       
        cout << " --- --- ---  --- --- ---  --- --- --- " << endl;
    }

public:
    sudoku(){
        srand(time(0));
    } // Inicializar la distribución

    void iniciar() {
        juego();
    }
};

int main(int argc, char const *argv[]) {
    sudoku juego;
    juego.iniciar();
    return 0;
}
