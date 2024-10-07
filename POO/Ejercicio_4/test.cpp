#include <cstdio>
#include <cstdlib>
#include <time>

using namespace std;

void dibujar_tablero(int movimiento, int turno, vector <int> posicion_jugador, vector <vector <int>> pozos, vector <vector<int>> comodines) {
    for (int i = 0; i < 15; i++) {

        for (int j = 0; j < 15; j++) {
            if (posicion_jugador[0] == i && posicion_jugador[1] == j) cout << "| " << movimiento == 1? 'T' : 'L' << ' ';
            else if (pozos[0][0] == i && pozos[0][1] == j || pozos[1][0] == i && pozos[1][1] == j) cout << "| O ";
            else if (comodines[0][0] == i && comodines[0][1] == j || comodines[1][0] == i && comodines[1][1] == j) cout << "| C ";
            else                                                      cout << "|  ";
        }
        cout << '|' << endl;
    }
}



int main(int argc, char const *argv[])
{
    juego();
    return 0;
}+
