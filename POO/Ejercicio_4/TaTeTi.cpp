#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Tateti {
    private:
        map<int, int> puntos = {{0, 0}, {1, 0}};
        int tablero[3][3];
        int turno;
        vector<int> posicion;


        // Establece el color del texto
        void set_color(const string &color) {
            cout << color;
        }

        // Restaura el color del texto al predeterminado
        void reset_color() {
            cout << "\033[0m";
        }

        // Inicializa el tablero con -1
        void iniciar_tablero() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) tablero[i][j] = -1;
            }
        }

        // Marca la jugada en el tablero
        void pasar_jugada() {
            if (turno % 2 == 0) tablero[posicion[0]][posicion[1]] = 1;
            else tablero[posicion[0]][posicion[1]] = 0;
            
        }

        // Valida que la jugada sea en una casilla valida
        bool validar_jugada () {
            if (tablero[posicion[0]][posicion[1]] == -1) return true;
            else {
                set_color("\033[38;5;196m");
                cout << "[!] Ingrese una posicion valida" << endl;
                reset_color();
                return false;
            }
        }

        // Dibuja el tablero en la consola
        void dibujar_tablero() {
            set_color("\033[0;35m");
            cout << "  | 0 | 1 | 2 |" << endl << "---------------" << endl;
            reset_color();
            for (int i = 0; i < 3; i++) {
                set_color("\033[0;35m");
                cout << i << " |";
                reset_color();
                for (int j = 0; j < 3; j++) {
                    if (tablero[i][j] == -1) cout << "   ";
                    else {
                        if (tablero[i][j] == 0) cout << " \033[0;34mO\033[0m ";
                        else cout << " \033[1;32mX\033[0m "; // escribo en rojo la X
                        reset_color();
                    }
                    cout << "\033[0;35m|\033[0m";
                }
                cout << "\n\033[0;35m---------------\033[0m" << endl;
            }
        }

        // Obtiene la jugada del jugador
        vector<int> get_jugada() {
            posicion.clear();
            posicion.resize(2);
                cout << "\n[i] Ingrese su posicion en el mapa (El primer numero es la columna y el segundo es la fila): ";
                cin >> posicion[0]; cin >> posicion[1];
            return posicion;
        }

        // Comprueba si hay un ganador
        int comprobar_ganador() {
            // Comprueba filas y columnas
            for (int i = 0; i < 3; i++) {
                if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != -1)
                    return tablero[i][0];
                if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != -1)
                    return tablero[0][i];
            }
            // Comprueba diagonales
            if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != -1)
                return tablero[0][0];
            if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != -1)
                return tablero[0][2];
            
            // Comprueba si hay empate
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (tablero[i][j] == -1) return -1; // No hay ganador aún
                }
            }
            return 2; // Empate
        }

        // Función para continuar o finalizar el juego
        void check(char opcion) {
            if (opcion == 's') {
                turno = 0;
                iniciar_tablero(); // Reinicia el tablero para una nueva partida
                juego(); // Inicia una nueva partida
            } else if (opcion == 'n') {
                exit(0); // Finaliza el programa
            }
        }

        // Lógica principal del juego
        void juego() {
            if (turno == 0) iniciar_tablero();
            dibujar_tablero();

            while (true) {
                posicion = get_jugada();
                if (!validar_jugada()) continue;
                pasar_jugada();
                dibujar_tablero();
                
                int ganador = comprobar_ganador();
                char opcion;
                if (ganador != -1) {
                    if (ganador == 2) {
                        set_color("\033[0;33m");
                        cout << "[+] Empate!" << endl;
                    } else {
                        set_color("\033[0;33m");
                        cout << "[+] Tenemos un ganador! Jugador " << (ganador == 1 ? "X" : "O") << endl << endl;
                        reset_color();
                        puntos[ganador]++;
                    }
                    cout << "[?] ¿Quieren volver a jugar? (s/n): "; 
                    cin >> opcion;
                    check(opcion);
                    break;
                }
                turno++;
            }
        }

    public:
        // Constructor que solo recibe el turno inicial
        Tateti(int turno) : turno(turno) {
            iniciar_tablero();
        }

        // Inicia el juego
        void inicializar() {
            juego();
        }
};

// Función principal
int main(int argc, char** argv) {
    Tateti juego(0); // Inicializa el juego con el turno 0
    juego.inicializar();
    return 0;
}
