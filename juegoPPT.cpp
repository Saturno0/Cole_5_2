#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;


const vector <string> jugadas = {"Piedra","Papel","Tijera"};


//Con esta funcion calculo la probabilidad de que va a jugar el usuario
string probabilidad(int pr, int pl, int tj) {
		float probPr = static_cast <float> (pr)/(pr+pl+tj);
		float probPl = static_cast <float> (pl)/(pr+pl+tj);
		float probTj = static_cast <float> (tj)/(pr+pl+tj);
		
		if (probPr > probPl && probPr > probTj) 	return jugadas[1];
		else if (probPl > probPr && probPl > probTj)return jugadas[2];
		else 										return jugadas[0];
}


void juego(int pr, int pl, int tj, int partidas) {
	string jugada_u, jugada_c;
	
	//El juego comprueba cuantas partidas se han jugado ya
	if(partidas > 5) jugada_c = probabilidad(pr,pl,tj); //El programa basado en la cuenta de probabilidades decide cual puede ser la opcion mas optima para usar
	
	else {	
		//El prograna elije su jugada
		int r = std::rand() % 3;
		jugada_c = jugadas[r];
	}
	
	
	cout << "[+]Sepa que la maquina ya decidio su movimiento" << endl;
	cout << "[+]Ingrese que jugada quiere hacer(Piedra, Papel o Tijera): "; cin >> jugada_u;
	
	
	//Comprobamos que la jugada ingresada sea valida y en caso de serla informamos quien es el ganador
	if(jugada_u == "Piedra") {
        if(jugada_c == "Tijera")    cout << "Felicidades, sos el ganador!!" << endl;
        else if(jugada_c == "Papel")    cout << "Lo lamento, El ganador es la maquina" << endl;
        else    cout << "Empate!!" << endl;
        pr += 1;
    } else if (jugada_u == "Papel"){
        if(jugada_c == "Tijera")    cout << "Lo lamento, El ganador es la maquina" << endl;
        else if(jugada_c == "Papel")    cout << "Empate!!" << endl;
        else    cout << "Felicidades, sos el ganador!!" << endl;
        pl += 1;
    } else if (jugada_u == "Tijera"){
        if(jugada_c == "Tijera")    cout << "Empate!!" << endl;
        else if(jugada_c == "Papel")    cout << "Felicidades, sos el ganador!!" << endl;
        else    cout << "Lo lamento, El ganador es la maquina" << endl;
        tj += 1;
    } else {
        cout << "Elija una opcion correcta (Piedra, Papel o Tijera)\n\n\n" << endl;
        juego(pr, pl, tj, partidas);
    }
	
	
	partidas += 1;


	//Le pregunto al usuario si quiere volver a jugar
	char option;
	do {
		cout << "Quiere volver a jugar? (s/n) "; cin >> option;
	
		switch(option) {
			case 's':
				juego(pr,pl,tj,partidas);
				break;
			case 'n':
				cout << "Que lastima!";
				break;
			default:
				cout << "Ingresa una opcion valida porfavor" << endl;
				break;
		}
	} while (option != 's' && option != 'n');
}



int main(int argc, char** argv) {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	juego(0,0,0,0);
	return 0;
}

