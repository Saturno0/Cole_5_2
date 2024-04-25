#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <map>


using namespace std;

bool exists(string filename) {
    ifstream file(filename);
    return true;
}


// Variables globales - Piedra 0, Papel 1, Tijera 2
vector<string> juegos = {"Piedra", "Papel", "Tijera"}; // Vector que incluye los juegos y su respectivo ID
int comparacion[2][3] = {{0, 1, 2}, {1, 2, 0}}; // Matriz la cual almacena, por ID (posicion de memoria del juego en el vector), un juego y su respectiva contra
int usuario=0, compu=0;

// Esta funcion contiene la creacion del archivo en caso de que no exista
string crear_archivo (string user_name, string nombre_archivo){

    // Abre el archivo y le escribe en la primera linea el nombre del usuario
    ofstream archivo(nombre_archivo);
    archivo << user_name << endl;
    archivo.close();
    
    return nombre_archivo;
}



// Esta funcion contiene lo que serviria para guardar las jugadas
void insertar_archivo (string nombre_archivo, vector <int> jugadas_u){
    // Abro el archivo y le escribo todas las jugadas
    ofstream archivo(nombre_archivo);
    for (int jugada : jugadas_u) {
        archivo << jugada << " ";
    }
    archivo << endl;
    archivo.close();
}


// Esta funcion lee las jugadas en caso de que el usuario ya exista
vector <int> leer_jugadas(string jugador_nombre) {
    ifstream archivo(jugador_nombre.append(".txt"));
    vector <int> jugadas;
    string linea;

    for (int contador = 0; getline(archivo, linea); contador++) {
        if (contador == 1) {
            int i = 0;
            while (linea[i] != '\n') {
                if (linea[i] != ' ') {
                    string num(1, linea[i]);
                    int n = stoi(num);
                    jugadas.push_back(n);
                }
                i++;
            }
        }
    }
    archivo.close();
    return jugadas;
}

int mas_usada(map<int, int> contador){
	
	// Obtengo la jugada mas usada - Itero por cada par valor-clave en el diccionario contador
    int valorMax = 0, claveMax;
    for (const auto& par : contador) {
        // par.second referencia al valor, mientras que par.first a la clave
        if (par.second > valorMax) {
            valorMax = par.second;
            claveMax = par.first; 
        }
    }
    return claveMax;
}

int calcular_juego(int partidas, vector<int> jugadas){
	int juego_compu;
	if(partidas >= 3){
		int cant_jugadas = jugadas.size(); // Almacena la cantidad de jugadas del usuario
		int posicion_jugada = rand() % cant_jugadas; // Almacena una posicion de memoria aleatoria de una jugada de las que realizo el usuario 
		int Jmas_probable = jugadas[posicion_jugada]; // Almacena la jugada correspondiente a la posicion de memoria random (las mas jugadas tienen mas chances de tocar)
		juego_compu = comparacion[1][Jmas_probable]; // Elige la jugada contraria a la mas usada por el usuario
	}
	else{
		juego_compu = rand() % 3;
	}
	
	return juego_compu;
}

void comparaciones(int juego, int juego_compu){
	// Realizo las comparaciones utilizando la matriz comparaciones y luego el diccionario juegos para mostrar los resultados
    if(juego == comparacion[1][juego_compu]){
    	cout << endl << "[+] El usuario gana!" << endl; 
		usuario+=1;
	} 
    else if(juego == juego_compu) {
        cout << endl << "[-] Empate!" << endl;
	} 
    else {
        cout << endl << "[!] El usuario pierde!" << endl; 
		compu+=1;
	}
}

int juego_usuario(){
	float juego;
	
    // El usuario tiene que ingresar una opcion hasta que esta sea correcta
    do{
    	// El usuario elige un juego por su ID y muestro en pantalla su respectivo juego
        cout << endl << "[0] Piedra\n[1] Papel\n[2] Tijera\n[3] Salir" << endl << "[i] Elige: "; cin >> juego;
        // Compruebo que el juego ingresado no sea float, de serlo, se convierte a entero
        if (juego != static_cast<int>(juego)) juego=static_cast<int>(juego);
        	
	}while(juego != 0 && juego !=1 && juego != 2 && juego != 3);
		
	return juego;
}

void informe_puntos(int partidas, map<int, int> contador){
    // Muestro la tabla informativa
    int Jmas_usada = mas_usada(contador);
    
    cout << endl << "---- Puntajes ----" << endl << "- Usuario: " << usuario << endl << "- Compu: " << compu << endl << "- Partidas: " << partidas;
    cout << endl << "- Jugada mas utilizada: " << juegos[Jmas_usada];
}

void juego(string archivo, vector<int> jugadas){
    map<int, int> contador {{0,0}, {1,0}, {2,0}}; // Diccionario que para almacenar la cantidad de veces que se utilizo una jugada
    int partidas=0, juego_compu;
	
	while (true) {
		int juego = juego_usuario();
		if (juego == 3) break; // Termino el programa
		
		cout << endl << "[+] Partida: " << partidas;
		
		cout << endl << "[+] Juego del usuario: " << juegos[juego];
		contador[juego] += 1; // Sumo al contador la cantidad de veces que el usuario eligio dicha opcion
        
        juego_compu = calcular_juego(partidas, jugadas); // Generamos y almacenamos la jugada de la compu
        cout << endl << "[+] Juego de la compu: " << juegos[juego_compu] << endl; 
        
        comparaciones(juego, juego_compu); // Llamamos a la funcion comparaciones para definir un ganador
        
		partidas++; // Incremento el contador de partidas jugadas
		jugadas.push_back(juego); // Se agrega la jugada al vector jugadas
    }
	// Informe final
	informe_puntos(partidas, contador);
    insertar_archivo(archivo, jugadas);
}

int main() {
	// Inicializo la semilla del generador de n?meros aleatorios
    srand(time(0));
    string user_name, archivo; // variables que almacenan el nombre del usuario y el nombre del archivo .txt
    vector<int> jugadas; // Almacena todas las jugadas del usuario de manera no ordenada

    cout << "[+]Ingrese su nombre de usuario: "; cin >> user_name;
    cout << "\n\n";
    archivo = user_name.append(".txt");

    if(exists(archivo)) jugadas = leer_jugadas(user_name);
    else                crear_archivo(user_name, archivo);
	
	for(int i = 0; i < jugadas.size(); i++) cout << jugadas[i] << " ";
	cout << endl;
	
    // Llamo a la funcion de juego()

    juego(archivo, jugadas);
    
}

