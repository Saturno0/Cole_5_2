#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <map>

using namespace std;

// i columna, j fila
void dibujar_tablero(int tamano, vector <int> posicion, vector <int> tesoro) {
    for (int i = 0; i < tamano; i++) {
        cout << "|";
        for (int j = 0; j < tamano; j++) {
            if (i==0 && j+1 == tamano || i+1 == tamano && j==0) cout << " # |";
			else if (posicion[0] == i && posicion[1] == j) cout << " 1 |";
			else if (tesoro[0] == i && tesoro[1] == j) cout << " X |";
            else cout << "   |";
        }
        cout << endl;
        for (int j = 0; j < tamano; j++) cout << "----";
        cout << "-" <<endl;
    }
	
}

vector <int> generar_posicion(int nivel) {
	// a = fila, b = columna;
	int a = rand() % (nivel-2) + 1, b = rand() % (nivel-2) + 1;
	vector <int> posicion;
	
	posicion.push_back(a); posicion.push_back(b);	
    return posicion;
}

vector <int> mover_jugador(vector<int> jugador, char tecla, map <char,int> vertical, map <char,int> horizontal) {
	for (const auto& par : vertical) {
		if(par.firs == tecla) jugador[1] = par.second;
	}
	for (const auto& par : horizontal) {
		if(par.firs == tecla) jugador[0] = par.second;
	}
	return jugador;
}


vector <int> juego(int nivel,vector<int> jugador, vector<int> tesoro){
	char tecla;
	int w=jugador[0]-1, a=jugador[1]-1, s=jugador[0]+1, d=jugador[1]+1;
	map<char,int> vertical{{'w',w},{'s',s}};
	map<char, int> horizontal{{'a',a},{'d',d}};
	
	while(jugador != tesoro){
		tecla = _getch();
		jugador = mover_jugador(jugador, tecla,vertical,horizontal);
		system("cls");
		dibujar_tablero(nivel,jugador,tesoro);
	}
}

int main(int argc, char** argv) {
	srand(time(0));
	
	int nivel=10;
	
	vector <int> jugador = generar_posicion(nivel);
	vector <int> tesoro = generar_posicion(nivel);
	
    while (true) {
        if (tesoro == jugador) tesoro = generar_posicion(nivel);
        else break;
    }
	dibujar_tablero(nivel, jugador, tesoro);
	juego(nivel,jugador, tesoro);
	return 0;
}
