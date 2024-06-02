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

    bool check_cuadro(int fila, int columna, int num) {
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

    void iniciar_tablero(int dificultad) {
        tablero.clear();
        tablero.resize(dificultad, vector<int>(dificultad, 0));

        // genero una array para los numeros validos
        vector <int> nums_validos(9); 
        iota(nums_validos.begin(), nums_validos.end(), 1);


        for (int fila = 0; fila < dificultad; fila++) {
            for (int columna = 0; columna < dificultad; columna++) {
                random_shuffle(nums_validos.begin(), nums_validos.end());

                for (int num : nums_validos) {
                    if (check_cuadro(fila, columna, num)) {
                        tablero[fila][columna] = num;
                        break;
                    }
                }
            }
        }
    }

    int pedir_dificultad() {
        int opcion, dificultad;
        cout << "Bienvenido al sudoku, espero se entretenga" << endl <<"[*] Elija una dificultad para jugar:\n 1- Facil\n 2- Intermedio\n 3- Dificil" << endl;
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
        int dificultad = pedir_dificultad();
        iniciar_tablero(dificultad);
        cout << "Tablero generado con dificultad " << dificultad << ":" << endl;
        dibujar_tablero();
    }

    void dibujar_tablero() {
        // system("cls"); // limpia la terminal en Windows
        // system("clear"); // limpia la terminal en Unix-like
        cout << "-------------------------------" << endl;
        for (const auto& fila : tablero) {
            cout << "|";
            for (int num : fila) {
                if (num != 0) {
                    cout << " " << num << " |";
                } else {
                    cout << "   |";
                }
            }
            cout << endl << "-------------------------------" << endl;
        }
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
