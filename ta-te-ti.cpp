#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <map>


using namespace std;
class Tateti {
	private:
		string user_name;
		int tablero[3][3];	
		int nivel, turno;

		bool jugada_valida() {
			for (int i = 0; i<2; i++) {
				if(posicion[i] > 2 || posicion[i] < 0) {
					cout << "[-] Ingrese una posicion valida" << endl;
					return false;
				}
			}
			return true;
		}

		void iniciar_tablero() {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; i<3; j++) tablero[i][j] = -1;
			}
		}


		int pasar_jugada() { // dependiendo de la posicion que haya ingresado el jugador se le da un valor a la matriz del tablero
			if (turno % 2 == 0) tablero[posicion[0]][posicion[1]] = 1;
			else				tablero[posicion[0]][posicion[1]] = 0;
		}


		void dibujar_tablero() {

			pasar_jugada();

			cout << "    0 | 1 | 2 |" << endl;
			for (int i = 0; i < 3; i++) {
				cout << i << " |";
				for (int j = 0; j<3; j++) {
					if (turno = 0 || tablero[i][j] == -1) cuot << "   |";
					else { // dependiendo del valor de la matriz de tablero se dibuja X o O
						if (tablero[i][j] == 0) cout << " X |";
						else 					cout << " O |";
					}
				}
				cout << "-----------------------" << endl;
			}
		}


		vector <int> get_jugada() {
			for (int i = 0; i < 2; i++) {
				cout << "\n[i] Ingrese su posicion en el mapa (El primer numero es la columna y el segundo es la fila)"; cin >> posicion[i];
			}
			return posicion;
		}


		void juego() {
			vector <int> posicion;
			map <int, int> puntos {{0,0}, {1,0}};
			int partidas = 0;
			
			if(turno == 0) iniciar_tablero();
			dibujar_tablero();

			while (true) {
				posicion = get_jugada();
				if (!jugada_valida()) continue;
				dibujar_tablero();
				if(comprobar_ganador() == 0) {
					map
				}

				turno ++;
			}
		}

	public:
		Tateti(string user_name) : user_name(user_name) {
			
		}

		void inicializar() {
			juego();
		}
}

int main(int argc, char** argv) {
	return 0;
}

