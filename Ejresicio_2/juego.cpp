#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;



/*if(jugada_u == "Piedra") {
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
    }*/

// const vector <string> jugadas = {"Piedra","Papel","Tijera"};


// //Con esta funcion calculo la probabilidad de que va a jugar el usuario
// string probabilidad(int pr, int pl, int tj) {
// 	//Genero un random para elejir que tirar
// 	int r = rand() % 2;
	
// 	//Creo una copia de jugadas
// 	vector <string> copy_jugadas = jugadas;

// 	//calculo la posibilidad de que el usuario elija Piedra, Papel o Tijera
// 	float probPr = static_cast <float> (pr)/(pr+pl+tj);
// 	float probPl = static_cast <float> (pl)/(pr+pl+tj);
// 	float probTj = static_cast <float> (tj)/(pr+pl+tj);
	
// 	if (probPl > probPr && probPl > probTj){
// 		//elimino la posibilidad de que saque Piedra para que solo pueda elejir Papel o Tijera
// 		copy_jugadas.erase(copy_jugadas.begin());	
// 	} else if(probTj > probPr && probTj > probPl) {
// 		copy_jugadas.erase(copy_jugadas.begin() + 1);
// 	}

// 	return copy_jugadas[r];
// }

// void comprobacion(string jugada_u, string jugada_c) {
// 	vector <string> finales = {"Lo lamento, El ganador es la maquina", "Felicidades, sos el ganador!!", "Empate!!"};

// 	if (jugada_c == jugadas[0] && jugada_u == jugadas[2] || jugada_c == jugadas[1] && jugada_u == jugadas[0]) {
		
// 	}
// }




// void juego(int pr, int pl, int tj, int partidas) {
// 	string jugada_u, jugada_c;
	
// 	//El juego comprueba cuantas partidas se han jugado ya
// 	if(partidas > 6) jugada_c = probabilidad(pr,pl,tj); //El programa basado en la cuenta de probabilidades decide cual puede ser la opcion mas optima para usar
	
// 	else {	
// 		//El prograna elije su jugada
// 		int r = std::rand() % 3;
// 		jugada_c = jugadas[r];
// 	}
	
// 	//Le pido al usuario que ingrese que jugada quiere realizar
// 	cout << "[+]Sepa que la maquina ya decidio su movimiento" << endl;
// 	cout << "[+]Ingrese que jugada quiere hacer(Piedra = 1, Papel = 2, Tijera = 3): "; cin >> jugada_u;
	
// 	//imprimo las jugadas del usuario y de la maquina para que el usuario conozca tanto su eleccion como la de la maquina
// 	cout << "Tu jugada es: " << jugada_u << endl;
// 	cout << "La de la maquina es: " << jugada_c << endl;


// 	//Comprobamos que la jugada ingresada sea valida y en caso de serla informamos quien es el ganador
// 	comprobacion(jugada_u,jugada_c);
	
	
// 	partidas += 1;


// 	//Le pregunto al usuario si quiere volver a jugar
// 	char option;
// 	do {
// 		cout << "Quiere volver a jugar? (s/n) "; cin >> option;
	
// 		switch(option) {
// 			case 's':
// 				juego(pr,pl,tj,partidas);
// 				break;
// 			case 'n':
// 				cout << "Que lastima!";
// 				break;
// 			default:
// 				cout << "Ingresa una opcion valida porfavor" << endl;
// 				break;
// 		}
// 	} while (option != 's' && option != 'n');
// }



int main(int argc, char** argv) {
	string c = "1";
	string d = "123";
	int a = stoi(c);
	int b = stoi(d);
	
	cout << a << " + " << b << " = " << a+b << endl;
	return 0;
}