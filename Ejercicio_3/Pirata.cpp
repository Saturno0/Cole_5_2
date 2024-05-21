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
    // Nombre del archivo que almacena los usuarios
    string arch_usuarios = "Usuarios_Pirata.txt"; 
    // Nombre del usuario
    string user_name;
    // Nivel actual del juego
    int nivel;
    // Turno actual
    int turno;
    // Límite de turnos
    int limite = 25;
    // Coordenadas del jugador, tesoro y bot
    vector<int> jugador;
    vector<int> tesoro;
    vector<int> bot;
    // Posiciones de los puentes
    vector<int> puente1 = {1, 1};
    vector<int> puente2 = {1, 1};

    // Convierte una cadena a minúsculas
    string lower_case(string str) {
        transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); });
        return str;
    }

    // Comprueba si un archivo existe
    bool exists(string filename) {
        FILE* file = fopen(filename.c_str(), "r");
        if (file) {
            fclose(file);
            return true;
        }
        return false;
    }

    // Crea un archivo
    string crear_archivo(string nombre_archivo) {
        ofstream archivo(nombre_archivo);
        archivo.close();
        return nombre_archivo;
    }

    // Inserta el nivel en el archivo del usuario
    void insertar_nivel(string nombre_archivo, int nivel) {
        ofstream archivo(nombre_archivo, ios::app);
        if (archivo.is_open()) {
            archivo << nivel << endl;
            archivo.close();
        } else {
            set_color("\033[38;5;196m"); // Rojo para errores
            cout << "[!] Ha habido un error al abrir el archivo para escribir." << endl;
            reset_color();
        }
    }

    // Inserta un usuario en el archivo de usuarios
    void insertar_usuario(string nombre_archivo, string usuario) {
        if (exists(nombre_archivo)) {
            ifstream archivo(nombre_archivo);
            string linea;
            while (getline(archivo, linea)) {
                if (linea == usuario) {
                    set_color("\033[38;5;196m"); // Rojo para errores
                    cout << "[!] El usuario ya existe." << endl;
                    reset_color();
                    return;
                }
            }
        }

        ofstream archivo(nombre_archivo, ios::app);
        archivo << usuario << endl;
        archivo.close();
    }

    // Lee el nivel desde el archivo del usuario
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

    // Establece el color del texto
    void set_color(const string &color) {
        cout << color;
    }

    // Restaura el color del texto al predeterminado
    void reset_color() {
        cout << "\033[0m";
    }

    // Dibuja el tablero del juego
    void dibujar_tablero() {
        system("cls");
        set_color("\033[38;5;46m"); // Verde para "APB"
        cout << "------------------------------------------------------------" << endl;
        cout << "| APB |" << " w: arriba - a: izquierda - s: abajo - d: derecha   |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "| APB |" << " El bot (B) te mata | Los puentes (P) son teleports |" << endl;
        cout << "------------------------------------------------------------" << endl << endl;
        reset_color();
        set_color("\033[38;5;226m"); // Amarillo para el texto
        cout << "[+] Turno numero: " << turno << "/" << limite << endl;
        cout << "[+] Nivel: " << nivel - 4 << endl << endl;
        reset_color();

        // Dibuja cada celda del tablero
        for (int i = 0; i < nivel; i++) {
            for (int j = 0; j < nivel; j++) {
                bool esBorde = (i == 0 || i == nivel - 1 || j == 0 || j == nivel - 1);
                bool esPuenteInterno = (i == 1 && j == nivel - 2) || (i == nivel - 2 && j == 1);

                if (esBorde) {
                    set_color("\033[48;5;14m"); // Fondo celeste para bordes
                } else if (esPuenteInterno) {
                    set_color("\033[48;5;94m\033[38;5;0m"); // Fondo marron para los puentes internos
                } else {
                    set_color("\033[48;5;180m\033[38;5;0m"); // Fondo color arena para espacios vacios
                }

                if (jugador[0] == i && jugador[1] == j) {
                    set_color("\033[48;5;0m\033[38;5;226m"); // Fondo negro para el jugador
                    cout << " J ";
                } else if (bot[0] == i && bot[1] == j && nivel > 8) {
                    set_color("\033[48;5;5m\033[38;5;0m"); // Fondo violeta para el bot
                    cout << " B ";
                } else if (tesoro[0] == i && tesoro[1] == j) {
                    // Si el nivel es mayor que 8
                    if (nivel > 8) {
                        // Establecer color de fondo y texto para el tesoro
                        set_color("\033[48;5;180m\033[38;5;0m"); // Fondo color arena
                        set_color("\033[38;5;196m"); // Texto color naranja para 'X'
                        cout << " X "; // Imprimir 'X'
                    } else {
                        cout << "   "; 
                    }
                } else if (esPuenteInterno) {
                    cout << " P ";
                } else {
                    cout << "   ";
                }
                reset_color();
            }
            cout << endl;
        }
    }

    // Genera una posición aleatoria en el tablero, evitando posiciones de los puentes internos
    vector<int> generar_posicion(int nivel) {
        int a, b;
        do {
            a = rand() % (nivel - 2) + 1;
            b = rand() % (nivel - 2) + 1;
        } while ((a == 1 && b == nivel - 2) || (a == nivel - 2 && b == 1)); // Evita posiciones de puentes internos
        return {a, b};
    }

    // Mueve el bot hacia el jugador
    vector<int> mover_bot(vector<int> jugador, vector<int>& bot) {
        if (bot[0] > jugador[0]) bot[0] -= 1;
        else if (bot[0] < jugador[0]) bot[0] += 1;
        else if (bot[1] > jugador[1]) bot[1] -= 1;
        else if (bot[1] < jugador[1]) bot[1] += 1;
        return bot;
    }

    // Comprueba si el jugador ha ganado, perdido o empatado
    int comprobar() {
        if (jugador[0] == 0 || jugador[1] == 0 || jugador[0] == nivel - 1 || jugador[1] == nivel - 1) return 0;
        else if (jugador == bot && jugador == tesoro) return 3;
        else if (jugador == bot) return 0;
        else if (turno == limite) return 0;
        else if (jugador == tesoro) return 1;
        else return 2;
    }

    // Mueve al jugador en el mapa, y en caso de estar en uno de los puentes lo teletransporta
    vector<int> mover_jugador(char tecla) {
        if (tecla == 'w' && jugador[0] > 0) jugador[0]--;
        else if (tecla == 's' && jugador[0] < nivel - 1) jugador[0]++;
        else if (tecla == 'a' && jugador[1] > 0) jugador[1]--;
        else if (tecla == 'd' && jugador[1] < nivel - 1) jugador[1]++;

        // Teletransporte del jugador
        if (jugador == vector<int>{1, nivel - 2}) {
            jugador = vector<int>{nivel - 2, 1};
        } else if (jugador == vector<int>{nivel - 2, 1}) {
            jugador = vector<int>{1, nivel - 2};
        }

        return jugador;
    }

    // Genera las posiciones del jugador, tesoro y bot
    void generar_posiciones() {
        int r;
        do {
            tesoro = generar_posicion(nivel);
            if (nivel > 8) bot = generar_posicion(nivel);
            jugador = generar_posicion(nivel);
            r = comprobar();
        } while (r == 0 || jugador == tesoro || jugador == vector<int>{1, nivel - 2} || jugador == vector<int>{nivel - 2, 1} || tesoro == vector<int>{1, nivel - 2} || tesoro == vector<int>{nivel - 2, 1} || bot == vector<int>{1, nivel - 2} || bot == vector<int>{nivel - 2, 1});
    }

    // Guarda los datos del usuario
    void guardar_datos() {
        insertar_nivel(user_name, nivel);
    }

    // Comprueba la opción del usuario después de finalizar una partida
    void check(char opcion, int result) {
        if (opcion == 's' && result == 1) {
            nivel += 1;
            if (nivel % 10 == 0) limite += 15;
            juego();
        } else if (opcion == 's' && result == 0) {
            set_color("\033[38;5;226m"); // Amarillo para "[+]"
            cout << "[+] Volviendo al nivel inicial..." << endl;
            reset_color();
            nivel = 5;
            juego();
        } else if (opcion == 's' && result == 3) {
            set_color("\033[38;5;226m"); // Amarillo para "[+]"
            cout << "[+] Reiniciando nivel..." << endl;
            reset_color();
            juego();
        } else if (opcion == 'n') {
            set_color("\033[38;5;226m"); // Amarillo para "[+]"
            cout << "\n[+] Guardando los datos..." << endl;
            reset_color();
            guardar_datos();
            exit(0);
        }
    }

    // Comprueba si una tecla es válida para mover al jugador
    bool comprobar_tecla(char tecla) {
        vector <char> jugadas = {'w', 'a', 's', 'd'};
        for (int i = 0; i < jugadas.size(); i++) {
            if (tecla == jugadas[i]) return true;
        }
        return false;
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
            else if (comprobar_tecla(tecla)) turno += 1;
            else continue;
            dibujar_tablero();
            result = comprobar();

            if (result != 2) {
                if (result == 0) {
                    set_color("\033[38;5;226m"); // Amarillo para el texto
                    cout << "[+] Que lastima! has muerto" << endl;
                    reset_color();
                    nivel = 5;
                    turno = 0;
                    limite = 25;
                } else if (result == 1) {
                    set_color("\033[38;5;226m"); // Amarillo para el texto
                    cout << "[+] Felicidades has ganado!" << endl;
                    reset_color();
                    turno = 0;
                    if (nivel == 5) {
                        set_color("\033[38;5;226m"); // Amarillo para el texto
                        cout << "[+] Has superado el primer nivel!" << endl;
                        reset_color();
                    } else {
                        set_color("\033[38;5;226m"); // Amarillo para el texto
                        cout << "[+] Felicidades, has llegado hasta el nivel " << nivel - 4 << "!" << endl;
                        reset_color();
                    }
                } else {
                    set_color("\033[38;5;226m"); // Amarillo para el texto
                    cout << "[+] Casi! Pero empataste" << endl;
                    reset_color();
                    turno = 0;
                }

                set_color("\033[38;5;45m"); // Cyan para el texto
                cout << "[i] Continuar? (s/n): ";
                reset_color();
                cin >> opcion;
                opcion = tolower(opcion);
                check(opcion, result);
            }
        }
    }

public:
    // Constructor de clase
    JuegoPirata(string user_name) : user_name(user_name) {
        nivel = 5;
        bot = {0, 0};
    }

    // Muestra la lista de usuarios
    void mostrar_usuarios() {
        if (exists(arch_usuarios)) {
            cout << "-- Usuarios --" << endl;
            ifstream archivo(arch_usuarios);
            string linea;
            while (getline(archivo, linea)) {
                string nombre_usuario = linea.substr(0, linea.find(".txt")); // mostramos todo lo que no sea .txt
                cout << "    " << nombre_usuario << endl;
            }
            cout << endl;
        }
    }

    // Inicia el juego para un usuario
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
    srand(time(0)); // Inicializa la semilla para la generación de números aleatorios
    string usuario;

    JuegoPirata juego(usuario); // Crea una instancia del juego
    juego.mostrar_usuarios(); // Muestra la lista de usuarios

    cout << "[i] Ingrese su nombre de usuario: ";
    cin >> usuario;
    juego.iniciar(usuario); // Inicia el juego para el usuario ingresado

    return 0;
}
