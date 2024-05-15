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

using namespace std;
string arch_usuarios = "Usuarios_Pirata.txt";
string user_name;

bool borrar_archivo(string archivo) {
    if (remove(archivo.c_str()) == 0) return true;
    else {
        cout << "A habido un error" << endl;
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

string crear_archivo (string nombre_archivo){
    // Abre el archivo lo cual lo crea y despues lo cierra
    nombre_archivo.append(".txt");
    ofstream archivo(nombre_archivo);
    archivo.close();
    return nombre_archivo;
}

// Esta funcion contiene lo que serviria para guardar las jugadas
void insertar_nivel (string nombre_archivo, int nivel){
    // Borramos el archivo
    borrar_archivo(nombre_archivo);
    // Abro el archivo y le escribo todas las jugadas siempre y cuando haya jugado mas de 3 veces
    ofstream archivo(nombre_archivo, ios::app);

    archivo << nivel << endl;

    archivo.close();
}

void insertar_usuario (string nombre_archivo, string usuario){
    // Abro el archivo y le escribo todas las jugadas siempre y cuando haya jugado mas de 3 veces
    ofstream archivo(nombre_archivo, ios::app);
    archivo << usuario << endl;
    archivo.close();
}

void mostrar_usuarios(string arch){
    if (exists(arch)){
        cout << "-- Usuarios --" << endl;

        ifstream archivo(arch);
        string linea;
        while (getline(archivo, linea)) {
            cout << "    " << linea << endl;
        }
        cout << "---------------" << endl << endl;
    }
}

// Esta funcion lee las jugadas en caso de que el usuario ya exista
int leer_nivel(string file) {
    ifstream archivo(file);
    int nivel = 0;
    string linea;

    if(archivo.is_open()) {
        while (getline(archivo, linea)) {
        	nivel = stoi(linea);
        }
    } else {
        //cout << "Error al abrir el archivo " << file << " porque no existe o no se puede abrir" <<endl;
        crear_archivo(file);
    }
    archivo.close();
    return nivel;
}


// Funcion que genera el mapa, va recorriendo
void dibujar_tablero(int tamano, vector<int> posicion, vector<int> tesoro, vector<int> bot) {
	// i columna, j fila
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

// Funcion generica para generar una posicion aleatoria en el mapa (fuera del agua)
vector<int> generar_posicion(int nivel) {
    // a = columna, b = file;
    int a = rand() % (nivel - 2) + 1, b = rand() % (nivel - 2) + 1;
    vector<int> posicion;

    posicion.push_back(a); posicion.push_back(b);
    return posicion;
}

// Movimiento del bot para que intente acercarse al jugador todo el tiempo
vector<int> mover_bot(vector<int> jugador, vector<int>& bot) {
    if (bot[0] > jugador[0]) bot[0] -= 1;
    else if (bot[0] < jugador[0]) bot[0] += 1;
    else if (bot[1] > jugador[1]) bot[1] -= 1;
    else if (bot[1] < jugador[1]) bot[1] += 1;

    return bot;
}

// Comprobamos si el usuario toco el agua o al bot. Retorna true si vive o false si muere
bool comprobar(vector <int> jugador, vector <int> bot, vector <int> tesoro, int nivel) {
    // Compruebo si el jugador toco el agua
    if (jugador[0] == 0 || jugador [1] == 0 || jugador[0] == nivel-1 || jugador[1] == nivel-1) return false;
    // Compruebo si el jugador toco al bot
    else if (jugador == bot) return false;
    else return true;
}

// Esta funcion capta el movimiento del jugador y lo mueve en el tablero
vector<int> mover_jugador(char tecla, vector<int> jugador, int nivel){
	    if (tecla == 'w' && jugador[0] > 0) jugador[0]--;  // Arriba
        else if (tecla == 's' && jugador[0] < nivel - 1) jugador[0]++;  // Abajo
        else if (tecla == 'a' && jugador[1] > 0) jugador[1]--;  // Izquierda
        else if (tecla == 'd' && jugador[1] < nivel - 1) jugador[1]++;  // Derecha
		return jugador;
}

void check (vector <int> bot,vector <int> jugador,vector <int> tesoro,char opcion, int nivel) {
	switch (opcion) {
    case 's':{
    	cout << "Que bueno!!" << endl;
        nivel +=1;
        jugador = generar_posicion(nivel);
        tesoro = generar_posicion(nivel);
        bot = generar_posicion(nivel);

        while (true) {
            if (tesoro == jugador) tesoro = generar_posicion(nivel);
            else if(bot == jugador) bot = generar_posicion(nivel);
            else break;
        }
        
        juego(nivel, jugador, tesoro, bot);
    	
		break;
	}
    
    case 'n':{
    	cout << "Que mal!! nt bro la proxima sera" << endl;
    	string copy = user_name.append(".txt");
    	insertar_nivel(copy, nivel);
		break;
	}

    default:
        break;
    }
}


// Esta funcion corre todo el juego
void juego(int nivel, vector<int>jugador, vector<int> tesoro, vector<int> bot) {
    char opcion;
    dibujar_tablero(nivel, jugador, tesoro, bot); // Dibujamos el mapa

    while (true) {
        char tecla = _getch(); // Capturamos las pulsaciones del teclado
		jugador = mover_jugador(tecla, jugador, nivel); // Movimiento del jugador
        bot = mover_bot(jugador, bot); // Movimiento del bot
        
        // Actualizacion de la pantalla
        system("cls");
        dibujar_tablero(nivel, jugador, tesoro, bot);
        
        // Comprobacion de ganar-perder
        if (!comprobar(jugador, bot, tesoro, nivel)) {
            cout << "[i] Que lastima!! has muerto" << endl << "Quieres volver a jugar?"; cin >> opcion;
    		opcion = tolower(opcion);
            check(bot,jugador,tesoro,opcion,nivel);
            break;
        } else if (jugador == tesoro){
            cout << "[i] Felicidades has ganado!!" << endl;
            if (nivel == 5) cout << "Has superado el primer nivel" << endl;
    		else            cout << "Felicidades has llegado hasta el nivel " << nivel - 4 << "!!" << endl;
    		cout << "\n\n\n\n" << "[i] Quieres jugar el siguiente nivel?(s/n): "; cin >> opcion;
    		opcion = tolower(opcion);
    		check(bot,jugador,tesoro,opcion,nivel);
            break;
        }
    }
    
    
}

int main(int argc, char** argv) {
    srand(time(0));
    system("cls");

    int nivel = 0;
	
	// Generamos las posiciones iniciales
    vector<int> jugador = generar_posicion(nivel);
    vector<int> tesoro = generar_posicion(nivel);
    vector<int> bot = generar_posicion(nivel);
    string copy_user, archivo;

    if (exists(arch_usuarios)) mostrar_usuarios(arch_usuarios); // Mostramos todos los usuarios, si hay

    cout << "[+]Ingrese su nombre de usuario: "; cin >> user_name;
    cout << "\n\n";

    // Convertir cada caracter a minuscula
    for (char &c : user_name) {
        c = tolower(c);
        copy_user.push_back(c);
    }
    user_name = copy_user;
    
    archivo = copy_user;

    if(exists(archivo)) nivel = leer_nivel(archivo);
    else {
        nivel = 5;
        crear_archivo(archivo);
        insertar_usuario(arch_usuarios,user_name);
    }



    // Comprobamos que el jugador no aparezca en el mismo lugar que el tesoro/bot
    while (true) {
        if (tesoro == jugador) tesoro = generar_posicion(nivel);
        else if(bot == jugador) bot = generar_posicion(nivel);
        else break;
    }

    juego(nivel, jugador, tesoro, bot); // Llamamos a la funcion core del juego

    return 0;
}
