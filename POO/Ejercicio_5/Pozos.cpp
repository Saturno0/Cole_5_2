#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

const int row = 10;
const int column = 10; 

string L_azul =  "\033[1;34m";
string L_amarilla = "\033[1;33m";
string L_rojo = "\033[1;31m";
int j_column = 0, j_row = 0;



void reset() {
    cout << "\033[0m";
}

void set_color(const string &color) {
    cout << color;
}

vector<vector<int>> iniciar_tablero() {
    vector <vector<int>> tablero;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10, j++) tablero[i][j] = 0;
    }
    return tablero;
}

vector<vector<int>> colocar_pozos(vector<vector<int>> tablero) {
    srand(time(NULL));
    int i = 0;
    while (i < 10) {
        int j = rand() % 10;
        if (j != 0 && i != 0) tablero[i][j] = 1;
        else                  continue;
        i++;
    }

    return tablero;
}

vector<int> mover_jugador(char teclam, vector <int> jugador) {
        if (tecla == 'w' && jugador[0] > 0) jugador[0]--;
        else if (tecla == 's' && jugador[0] < tamano - 1) jugador[0]++;
        else if (tecla == 'a' && jugador[1] > 0) jugador[1]--;
        else if (tecla == 'd' && jugador[1] < tamano - 1) jugador[1]++;
        return jugador;
}

void APB() {

}

void dibujar() {
    APB();
}




void juego() {
    vector <vector <int>> tablero = iniciar_tablero();
    vector <int> jugador {0,0};
    int vidas = 3;

    tablero = colocar_pozos(tablero);

    while (true) {
        system("cls");
        dibujar(tablero,jugador);
        mover_jugador(jugador);
        if (!comprobar_jugador(jugador, tablero) && vidas != 0) {
            jugador = {0,0};
            continue;
        } else {
            if (jugador == {9,9} && vidas != 0) {
                system("cls");
                cout << "Felicidades has ganado!!" << endl;
                return false;
            } else  if (vidas == 0){
                system("cls");
                cout << "Lo lamento, has perdido :(" << endl;
            }
        }

    }
    
}
    

int main(int argc, char const *argv[]) {
    
    return 0;
}
