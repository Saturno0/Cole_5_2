#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <map>
#include <string>
#include <fstream>
#include <cstdio>
#include <algorithm>

using namespace std;

class JuegoPirata {
private:
    string arch_usuarios = "Usuarios_Pirata.txt";
    string user_name;
    int nivel;
    int turno;
    int limite = 25;
    vector<int> jugador;
    vector<int> tesoro;
    vector<int> bot;
    
    string lower_case(string str) {
        transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); });
        return str;
    }

    bool borrar_archivo(string archivo) {
        if (remove(archivo.c_str()) == 0) return true;
        else {
            cout << "[!] Ha habido un error" << endl;
            return false;
        }
    }

    bool exists(string filename) {
        FILE* file = fopen(filename.c_str(), "r");
        if (file) {
            fclose(file);
            return true;
        }
        return false;
    }

    string crear_archivo(string nombre_archivo) {
        ofstream archivo(nombre_archivo);
        archivo.close();
        return nombre_archivo;
    }

    void insertar_nivel(string nombre_archivo, int nivel) {
        ofstream archivo(nombre_archivo, ios::app);
        if (archivo.is_open()) {
            archivo << nivel << endl;
            archivo.close();
        } else {
            cout << "[!] Ha habido un error al abrir el archivo para escribir." << endl;
        }
    }

    void insertar_usuario(string nombre_archivo, string usuario) {
        if (exists(nombre_archivo)) {
            ifstream archivo(nombre_archivo);
            string linea;
            while (getline(archivo, linea)) {
                if (linea == usuario) {
                    cout << "[!] El usuario ya existe." << endl;
                    return;
                }
            }
        }

        ofstream archivo(nombre_archivo, ios::app);
        archivo << usuario << endl;
        archivo.close();
    }

    int leer_nivel(string file) {
        ifstream archivo(file);
        int nivel = 0;
        string linea;

        if (archivo.is_open()) {
            while (getline(archivo, linea)) {
                nivel = stoi(linea);
            }
        } else {
            crear_archivo(file);
        }
        archivo.close();
        return nivel;
    }

    void set_color(const string &color) {
        cout << color;
    }

    void reset_color() {
        cout << "\033[0m";
    }

void dibujar_tablero() {
    system("cls");
    cout << "----------------------------------------------------------" << endl;
    cout << "| APB |" << " w: arriba - a: izquierda - s: abajo - d: derecha |" << endl;
    cout << "----------------------------------------------------------" << endl << endl;
    cout << "[+] Turno numero: " << turno << "/" << limite << endl;
    cout << "[+] Nivel: " << nivel - 4 << endl << endl;

    for (int i = 0; i < nivel; i++) {
        for (int j = 0; j < nivel; j++) {
            bool esBorde = (i == 0 || i == nivel - 1 || j == 0 || j == nivel - 1);
            bool esPuenteInterno = (i == 1 && j == nivel - 2) || (i == nivel - 2 && j == 1);

            if (esBorde) {
                set_color("\033[48;5;14m"); // Fondo celeste para bordes
            } else if (esPuenteInterno) {
                set_color("\033[48;5;94m\033[38;5;0m"); // Fondo marrón para los puentes internos
            } else {
                if (jugador[0] == i && jugador[1] == j) {
                    set_color("\033[48;5;0m\033[38;5;226m"); // Fondo negro
                } else if (tesoro[0] == i && tesoro[1] == j) {
                    set_color("\033[48;5;15m\033[38;5;0m"); // Fondo blanco para el tesoro
                } else if (bot[0] == i && bot[1] == j && nivel > 8) {
                    set_color("\033[48;5;5m\033[38;5;0m"); // Fondo violeta para el bot
                } else {
                    set_color("\033[48;5;15m\033[38;5;0m"); // Fondo blanco para espacios vacíos
                }
            }

            if (jugador[0] == i && jugador[1] == j) {
                cout << " J ";   
            } else if (tesoro[0] == i && tesoro[1] == j) {
                set_color("\033[38;5;196m"); // Naranja para 'X'
                cout << " X ";
            } else if (bot[0] == i && bot[1] == j && nivel > 8) {
                set_color("\033[38;5;0m"); // Rojo para 'B'
                cout << " B ";
            } else {
                cout << "   ";
            }
            reset_color();
        }
        cout << endl;
    }
}




    vector<int> generar_posicion(int nivel) {
        int a = rand() % (nivel - 2) + 1, b = rand() % (nivel - 2) + 1;
        return {a, b};
    }

    vector<int> mover_bot(vector<int> jugador, vector<int>& bot) {
        if (bot[0] > jugador[0]) bot[0] -= 1;
        else if (bot[0] < jugador[0]) bot[0] += 1;
        else if (bot[1] > jugador[1]) bot[1] -= 1;
        else if (bot[1] < jugador[1]) bot[1] += 1;
        return bot;
    }

    int comprobar() {
        if (jugador[0] == 0 || jugador[1] == 0 || jugador[0] == nivel - 1 || jugador[1] == nivel - 1) return 0;
        else if (jugador == bot) return 0;
        else if (turno == limite) return 0;
        else if (jugador == tesoro) return 1;
        else return 2;
    }

    vector<int> mover_jugador(char tecla) {
        if (tecla == 'w' && jugador[0] > 0) jugador[0]--;
        else if (tecla == 's' && jugador[0] < nivel - 1) jugador[0]++;
        else if (tecla == 'a' && jugador[1] > 0) jugador[1]--;
        else if (tecla == 'd' && jugador[1] < nivel - 1) jugador[1]++;
        return jugador;
    }

    void generar_posiciones() {
        int r;
        do {
            tesoro = generar_posicion(nivel);
            if (nivel > 8) bot = generar_posicion(nivel);
            jugador = generar_posicion(nivel);
            r = comprobar();
        } while (r == 0 || jugador == tesoro);
    }

    void guardar_datos() {
        insertar_nivel(user_name, nivel);
    }

    void check(char opcion, bool result) {
        if (opcion == 's' && result) {
            nivel += 1;
            if (nivel % 10 == 0) limite +=10; 
            juego();
        } else if (opcion == 's' && !result) {
            cout << "[+] Volviendo al nivel inicial..." << endl;
            nivel = 5;
            juego();
        } else if (opcion == 'n') {
            cout << "\n[+] Guardando los datos..." << endl;
            guardar_datos();
            exit(0);
        }
    }

    void juego() {
        char opcion;
        int result;

        generar_posiciones();
        dibujar_tablero();

        while (true) {
            char tecla = _getch();
            jugador = mover_jugador(tecla);
            if (nivel > 8) bot = mover_bot(jugador, bot);
			turno += 1;
            dibujar_tablero();
            result = comprobar();

            if (result != 2) {
                if (result == 0) {
                    cout << "[+] Que lastima! has muerto" << endl;
                    nivel = 5;
                    turno = 0;
                    limite = 25;
                } else if (result == 1) {
                    cout << "[+] Felicidades has ganado!" << endl;
                    turno = 0;
                    if (nivel == 5) cout << "[+] Has superado el primer nivel!" << endl;
                    else cout << "[+] Felicidades, has llegado hasta el nivel " << nivel - 4 << "!" << endl;
                }

                cout << "[i] Continuar? (s/n): "; cin >> opcion;
                opcion = tolower(opcion);
                check(opcion, result);
            }
        }
    }

public:
    JuegoPirata(string user_name) : user_name(user_name) {
        nivel = 5;
        bot = {0, 0};
    }

    void mostrar_usuarios() {
        if (exists(arch_usuarios)) {
            cout << "-- Usuarios --" << endl;
            ifstream archivo(arch_usuarios);
            string linea;
            while (getline(archivo, linea)) {
                string nombre_usuario = linea.substr(0, linea.find(".txt"));
                cout << "    " << nombre_usuario << endl;
            }
            cout << endl;
        }
    }

    void iniciar(string usuario) {
        user_name = usuario + ".txt"; // Nombre correcto del archivo de usuario
        user_name = lower_case(user_name);
        insertar_usuario(arch_usuarios, user_name);

        nivel = leer_nivel(user_name);
        if (nivel == 0) {
            nivel = 5; // Nivel predeterminado si no hay datos almacenados
        }

        juego();
    }
};

int main() {
    srand(time(0));
    string usuario;

    JuegoPirata juego(usuario);
    juego.mostrar_usuarios();

    cout << "[i] Ingrese su nombre de usuario: ";
    cin >> usuario;
    juego.iniciar(usuario);

    return 0;
}
