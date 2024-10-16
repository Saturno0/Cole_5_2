#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <algorithm>
#include <random>
#include <numeric>
#include <stdlib.h>

using namespace std;

class sudoku {
private:
    string f_verde = "\033[0;42m";
    string f_rojo = "\033[0;41m";
    string amarillo = "\033[33m";
    string rojo = "\033[1;31m";
    string verde = "\033[1;32m";
    string azul = "\033[1;34m";
    vector<vector<int>> tablero;

    // funcion para hacer que el programa se detenga durante n segundos
    void delay(int secs) {
        for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
    }

    // para la posicion del jugador sobre el tablero
    vector<int> jugador{0, 0};

    // genero una array para los numeros validos
    vector<int> nums_validos{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamano = 9;

    // Establece el color del texto
    void set_color(const string &color) {
        cout << color;
    }

    // Restaura el color del texto al predeterminado
    void reset_color() {
        cout << "\033[0m";
    }

    // comprueba que el numero no se repita en la columna en la que se encuentra
    bool check_column(int columna, int num) {
        for (int i = 0; i < tablero.size(); ++i) {
            if (tablero[i][columna] == num) {
                return false;
            }
        }
        return true;
    }

    // comprueba que el numero no se repita en la fila en la que se encuentra
    bool check_fila(int fila, int num) {
        for (int i = 0; i < tablero[fila].size(); ++i) {
            if (tablero[fila][i] == num) {
                return false;
            }
        }
        return true;
    }

    // compruebo que el numero no se encuentre en el recuadro ni en la fila y columna
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
        if (check_fila(fila, num) && check_column(columna, num)) return true;
        else return false;
    }


    // completo todos los cuadrados que no sean las diagonales
    bool fill_resto(int fila, int columna, vector<int> nums) {
        if (columna >= tamano && fila < tamano - 1) {
            fila = fila + 1;
            columna = 0;
        }

        if (fila % 3 == 0 && columna % 3 == 0) {
            random_shuffle(nums.begin(), nums.end());
        }

        if (fila >= tamano && columna >= tamano)
            return true; // ya termino

        if (fila < 3) {
            // omite el primer cuadro, lo hace saltar a la fila 3
            if (columna < 3)
                columna = 3;
        } else if (fila < tamano - 3) {
            // si la fila es menor a 7 busca la coordenada del columna
            if (columna == int((fila / 3) * 3)) {
                columna = columna + 3; // i=columna, columna=> columna+3
            }
        } else {
            if (columna == tamano - 3) // si columna == 7
            {
                fila = fila + 1;
                columna = 0;
                if (fila >= tamano) // sale si columna > 9
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

    // completo las diagonales del tablero
    void fill_diagonales(int fila, int columna, vector<int> nums) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int num : nums) {
                    if (check_box(fila, columna, num)) tablero[i + fila][j + columna] = num;
                }
            }
        }
    }

    void iniciar_diagonales() {
        vector<int> nums = nums_validos;

        for (int i = 0; i < tamano; i += 3) {
            random_shuffle(nums.begin(), nums.end());
            fill_diagonales(i, i, nums);
        }

    }

    void iniciar_resto() {
        vector<int> nums = nums_validos;
        fill_resto(0, 3, nums);
    }


    // funcion en la que creo el tablero y genero los espacios vacios
    vector<vector<int>> iniciar_tablero(int dificultad) {
        tablero.clear();
        tablero.resize(tamano, vector<int>(tamano, 0));
        vector<vector<int>> copy_tablero;

        iniciar_diagonales();
        iniciar_resto();

        copy_tablero = tablero;

        while (!check_espacios(dificultad)) {
            tablero = copy_tablero;
            vaciar_espacios(dificultad);
        }

        return copy_tablero;
    }

    bool check_espacios(int espacios) {
        int contador = 0;

        for (int fila = 0; fila < tamano; fila += 3) {
            for (int columna = 0; columna < tamano; columna += 3) {
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


    // funcion para vaciar espacios random del tablero
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
        system("cls");

        cout << "Bienvenido al sudoku, espero se entretenga" << endl
             << "[*] Elija una dificultad para jugar:\n 1- Facil(25 espacios blancos)\n 2- Intermedio(30 espacios blancos)\n 3- Dificil(40 espacios blancos)" << endl;
        while (true) {
            cin >> opcion;
            switch (opcion) {
                case 1:
                    dificultad = 25;
                    break;
                case 2:
                    dificultad = 30;
                    break;
                case 3:
                    dificultad = 40;
                    break;
                default:
                    set_color(rojo);
                    cout << "[!] Opcion incorrecta. Por favor ingrese una opcion correcta" << endl;
                    reset_color();
                    continue; // Continúa el bucle hasta que se reciba una opción válida
            }
            break; // Sal del bucle si se recibe una opción válida
        }
        return dificultad;
    }


    vector<int> mover_jugador(char tecla) {
        if (tecla == 'w' && jugador[0] > 0) jugador[0]--;
        else if (tecla == 's' && jugador[0] < tamano - 1) jugador[0]++;
        else if (tecla == 'a' && jugador[1] > 0) jugador[1]--;
        else if (tecla == 'd' && jugador[1] < tamano - 1) jugador[1]++;
        return jugador;
    }


    bool comprobar_tecla_char(char tecla) {
        vector<char> jugadas = {'w', 'a', 's', 'd'};
        
        for (char jugada : jugadas) {
            if (tecla == jugada) return true;
        }

        return false;
    }


    bool comprobar_tecla_int(char tecla) {
        vector<char> char_num{'1','2','3','4','5','6','7','8','9'};

        for (char num : char_num) {
            if (tecla == num) return true;
        }

        return false;
    }


    // compruebo que el num sea el correcto
    bool comprobar_num(vector <vector <int>> copy_tablero, int num) {
        if (copy_tablero[jugador[0]][jugador[1]] == num) return true;
        else                                             return false;
    }


    // compruebo si gano
    bool check_partida(int vidas, vector <vector <int>> copy_tablero) {
        if (copy_tablero == tablero) return true;
        return false;
    }

    void juego() {
        int dificultad = pedir_dificultad();
        int vidas = 3; // vidas que tiene el jugador hasta perder
        vector<vector<int>> copy_tablero = iniciar_tablero(dificultad);
        
        dibujar_tablero(dificultad, vidas);

        while (true) {
            char tecla = _getch();
            int n;

            // compruebo si la tecla presionada es un numero y lo convierto en caso de serlo
            if (comprobar_tecla_int(tecla)) n = tecla - '0';


            // en caso de que tampoco sea una jugada valida se le indica al usuario
            if (!comprobar_tecla_char(tecla)) {
                if (tecla == ' ') continue;
                set_color(rojo);
                cout << "[!] Tecla incorrecta. Ingrese una opcion correcta" << endl;
                reset_color();
                APB(vidas);
            }
            

            if (comprobar_tecla_char(tecla)) jugador = mover_jugador(tecla);
            
            else {
                if (tablero[jugador[0]][jugador[1]] == 0) {
                    if (comprobar_num(copy_tablero,n)) tablero[jugador[0]][jugador[1]] = n; // en caso de que el numero ingresado este en la posicion correcta se pasa el valor
                    else {
                        set_color(f_rojo);
                        cout << "[-] Uhhh, casi, pero le erraste" << endl;
                        reset_color();
                        vidas--;
                        delay(2);
                    }

                } else {
                    set_color(rojo);
                    cout << "[!] Tecla incorrecta. Ingrese una opcion correcta" << endl;
                    reset_color();
                    APB(vidas);
                    continue;
                }
            }

            dibujar_tablero(dificultad, vidas);

            
            if (check_partida(vidas,copy_tablero)) { // compruebo si el jugador gano
                set_color(amarillo);
                cout << "[!] FELICIDADES HAS GANADO!!";
                reset_color();
                break;
            } else {
                if (vidas == 0) {
                    set_color(rojo);
                    cout << "[!] Uhhh, has perdido todas tus vidas\n[+] Sera la proxima" << endl;
                    reset_color();
                    break;
                }
            }
        }
    }



    // funcion para el APB
    void APB(int vidas) {
        system("cls");
        set_color(verde); // Verde para "APB"
        cout << "------------------------------------------------------------ " << endl;
        cout << "| APB | w: arriba - a: izquierda - s: abajo - d: derecha   |" << endl;
        cout << "------------------------------------------------------------ " << endl;
        cout << "| APB | Parese sobre la casilla para ingresar el numero    |" << endl;
        cout << "------------------------------------------------------------ " << endl << endl;
        reset_color();
        set_color(f_verde);
        cout << "Vidas: " << vidas << endl;
        reset_color();
    }




    void dibujar_tablero(int dificultad, int vidas) {

        APB(vidas);

        cout << "Tablero generado con dificultad " << (dificultad == 25 ? 1 : dificultad == 30 ? 2 : 3) << ":" << endl;
        cout << "  --- --- ---  --- --- ---  --- --- --- " << endl << "  --- --- ---  --- --- ---  --- --- --- " << endl;
        for (int i = 0; i < tamano; ++i) {
            cout << "||";
            for (int j = 0; j < tamano; ++j) {
                if (tablero[i][j] != 0) {
                    if (jugador[0] == i && jugador[1] == j) {
                        set_color(azul);
                        cout << " " << tablero[i][j] << " ";
                        reset_color();
                    } else {
                        cout << " " << tablero[i][j] << " ";
                    }
                } else {
                    if (jugador[0] == i && jugador[1] == j) {
                        set_color("\033[44m\033[31m"); // Fondo azul y texto rojo
                        cout << "   ";
                        reset_color();
                    } else {
                        cout << "   ";
                    }
                }
                if ((j + 1) % 3 == 0) { // para cuando es el cuadrado se termina
                    cout << "||";
                } else {
                    cout << "|";
                }
            }
            cout << endl;
            if ((i + 1) % 3 == 0) { // para el final de un cuadrado
                cout << "  --- --- ---  --- --- ---  --- --- --- " << endl << "  --- --- ---  --- --- ---  --- --- --- " << endl;
            } else {
                cout << "  --- --- ---  --- --- ---  --- --- --- " << endl;
            }
        }
    }

public:
    sudoku() {// Inicializar la distribución
        srand(time(0));
    } 

    void iniciar() {
        juego();
    }
};

int main(int argc, char const *argv[]) {
    sudoku juego;
    juego.iniciar();
    return 0;
}
