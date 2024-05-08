#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <map>

using namespace std;

// i columna, j fila
void dibujar_tablero(int tamano, vector<int> posicion, vector<int> tesoro, vector<int> bot) {
    for (int i = 0; i < tamano; i++) {
        cout << "|";
        for (int j = 0; j < tamano; j++) {
            if (i == 0 && j + 1 == tamano || i + 1 == tamano && j == 0) cout << " # |";
            else if (posicion[0] == i && posicion[1] == j) cout << " 1 |";
            else if (tesoro[0] == i && tesoro[1] == j) cout << " X |";
            else if (bot[0] == i && bot[1] == j) cout << " B |";
            else cout << "   |";
        }
        cout << endl;
        for (int j = 0; j < tamano; j++) cout << "----";
        cout << "-" << endl;
    }

}

vector<int> generar_posicion(int nivel) {
    // a = fila, b = columna;
    int a = rand() % (nivel - 2) + 1, b = rand() % (nivel - 2) + 1;
    vector<int> posicion;

    posicion.push_back(a); posicion.push_back(b);
    return posicion;
}

vector<int> mover_bot(vector<int> jugador, vector<int>& bot) {
    if (bot[0] > jugador[0]) bot[0] -= 1;
    else if (bot[0] < jugador[0]) bot[0] += 1;
    else if (bot[1] > jugador[1]) bot[1] -= 1;
    else if (bot[1] < jugador[1]) bot[1] += 1;

    return bot;
}

vector<int> juego(int nivel, vector<int>jugador, vector<int> tesoro) {
    vector<int> bot = generar_posicion(nivel);
    char tecla;

    while (jugador != tesoro) {
        tecla = _getch();
        if (tecla == 'w' && jugador[0] > 0) jugador[0]--;  // Arriba
        else if (tecla == 's' && jugador[0] < nivel - 1) jugador[0]++;  // Abajo
        else if (tecla == 'a' && jugador[1] > 0) jugador[1]--;  // Izquierda
        else if (tecla == 'd' && jugador[1] < nivel - 1) jugador[1]++;  // Derecha

        bot = mover_bot(jugador, bot); // Movimiento del bot
        system("cls");
        dibujar_tablero(nivel, jugador, tesoro, bot);
    }

    return jugador;
}

int main(int argc, char** argv) {
    srand(time(0));

    int nivel = 10;

    vector<int> jugador = generar_posicion(nivel);
    vector<int> tesoro = generar_posicion(nivel);
    vector<int> bot = generar_posicion(nivel);
    while (true) {
        if (tesoro == jugador) tesoro = generar_posicion(nivel);
        else break;
    }

    dibujar_tablero(nivel, jugador, tesoro, bot); // Dibujar bot inicialmente fuera del tablero
    juego(nivel, jugador, tesoro);
    return 0;
}
