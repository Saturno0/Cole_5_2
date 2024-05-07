#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


void dibujar_tablero(int tamano, vector <int> posicion, vector <int> t) {
    for (int i = 0; i < tamano; i++) {
        cout << "|";
        for (int j = 0; j < tamano; j++) {
            if (i==0 && j+1 == tamano || i+1 == tamano && j==0) cout << " # |";
			else if (posicion[0] == i && posicion[1] == j) cout << " 1 |";
			else if (t[0] == i && t[1] == j)				   cout << " X |";
            else                                      cout << "   |";
        }
        cout << endl;
        for (int j = 0; j < tamano; j++) cout << "----";
        cout << "-" <<endl;
    }
	
}

vector <int> generar_posicion(int nivel) {
	int a = rand() % nivel + 1,b = rand() % nivel + 1;
	vector <int> posicion;
	if (a == 1 || b == nivel || b == 1 || a == nivel) posicion = generar_posicion(nivel); // a = colum || b = fila
	
	posicion.push_back(a); posicion.push_back(b);	

    return posicion;
}



int main(int argc, char** argv) {
	srand(time(0));
	vector <int> a = generar_posicion(5);
	vector <int> tesoro = generar_posicion(5);
    while (true) {
        if (tesoro == a) tesoro = generar_posicion(5);
        else             break;
    }
	dibujar_tablero(5, a, tesoro);
	return 0;
}
