#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <map>

using namespace std;


// Variables globales - Piedra 0, Papel 1, Tijera 2

vector<string> juegos = {"Piedra", "Papel", "Tijera"}; // Vector que incluye los juegos y su respectivo ID

int comparacion[2][3] = {{0, 1, 2}, {1, 2, 0}}; // Matriz la cual almacena, por ID (posicion de memoria del juego en el vector), un juego y su respectiva contra

int usuario=0, compu=0;



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



int calcular_juego(int partidas, map<int, int> contador){

	int Jmas_usada;

	int juego_compu = rand() % 3; 

	

	if (partidas >= 6){

		Jmas_usada = mas_usada(contador);

		while(juego_compu != Jmas_usada && juego_compu != comparacion[1][Jmas_usada]){

			juego_compu = rand() % 3;

		}

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

        	

	}while (juego != 0 && juego !=1 && juego != 2 && juego != 3); //se puede simplificar con juego < 0 && juego > 3

		

	return juego;

}



void informe_puntos(int partidas, map<int, int> contador){

    // Muestro la tabla informativa

    int Jmas_usada = mas_usada(contador);

    

    cout << endl << "---- Puntajes ----" << endl << "- Usuario: " << usuario << endl << "- Compu: " << compu << endl << "- Partidas: " << partidas;

    cout << endl << "- Jugada mas utilizada: " << juegos[Jmas_usada];

}



void juego(){

    map<int, int> contador {{0,0}, {1,0}, {2,0}}; // Diccionario que para almacenar la cantidad de veces que se utilizo una jugada

    int partidas=0, juego_compu;

	

	while (true) {

		int juego = juego_usuario();

		if (juego == 3) break; // Termino el programa

		

		cout << endl << "[+] Partida: " << partidas;

		

		cout << endl << "[+] Juego del usuario: " << juegos[juego];

		contador[juego] += 1; // Sumo al contador la cantidad de veces que el usuario eligio dicha opcion

        

        juego_compu = calcular_juego(partidas, contador);

        cout << endl << "[+] Juego de la compu: " << juegos[juego_compu] << endl; 

        

        comparaciones(juego, juego_compu);

        

		partidas++; // Incremento el contador de partidas jugadas	

    }

	// Informe final

	informe_puntos(partidas, contador);

}



int main() {

	// Inicializo la semilla del generador de n�meros aleatorios

    srand(time(0));

    // Llamo a la funcion de juego()

	juego();

}
