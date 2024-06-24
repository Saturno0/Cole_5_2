#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

// Letras:
const string L_Rojo= "\033[1;31m";
const string L_Verde= "\033[1;32m";
const string L_Azul= "\033[1;34m";

// Fondo:
const string F_Rojo= "\033[1;41m";
const string F_Verde= "\033[1;42m";
const string F_Azul= "\033[1;44m";



void reset_color() {
	cout << "\033[0m";
}

void set_color(const string &color) {
	cout << color;
}

vector <int> cant_alf() { // pide la cantidad de alfajores producida por cada operario
    vector <int> operario;
    int produccion;
    for (int i = 1; i <= 6; i++) {
        cout << "[i] Ingrese la produccion del operario numero " << i << ": ";
        cin >> produccion;
        operario.push_back(produccion);
        system("cls");
    }

    return operario;
}

void informar_error( vector <int> restos) {
    set_color(L_Rojo);
    for (int i = 0; i < 6; i++) {
        cout << "[!] El error del operario " << i+1 << " es de " << restos[i] << "%." << endl;
    }
    reset_color();
}

vector <int> Ganancia( vector <int> operario) {
    vector <int> ganancia = operario
    vector <int> restos;
    for (int i = 0; i < 6; i++) { // calculo los restos de todos los operarios
        if (operario % 6 != 0) restos.push_back(operario % 6);
        else                       restor.push_back(0);
    }

    informar_error(restos);
}

void Chocolate(){
    vector <int> cant = cant_alf();
    vector <int> ganancia = Ganancia(cant);
}


void DDL(){
    vector <int> cant = cant_alf();
    vector <int> ganancia = Ganancia(cant);
}


void Fruta(){
    vector <int> cant = cant_alf();
    vector <int> ganancia = Ganancia(cant);
}


void Mixto(){
    vector <int> cant = cant_alf();
    vector <int> ganancia = Ganancia(cant);
}


void opciones( vector <int> precios) {
    int opcion = 0;
    while (opcion != 5) { // para que el programa se ejecute mientras el usuario desee
        set_color(L_Verde);
        cout << "[*] Seleccione de que clase de alfajor se desea informar:" << endl
            << "\t[+] 1. Chocolate." << endl
            << "\t[+] 2. Dulce de leche." << endl
            << "\t[+] 3. Fruta." << endl
            << "\t[+] 4. Mixtos (chocolate, dulce de leche y fruta)" << endl
            << "\t[+] 5. Salir del programa." << endl
        ;
        reset_color();
        cin >> opcion;
        int precio = precios[opcion - 1];
        switch (opcion) {
            case 1:
                system("cls");
                Chocolate(precio);
                break;
            case 2:
                system("cls");
                DDL(precio);
                break;
            case 3:
                system("cls");
                Fruta(precio);
                break;
            
            case 4:
                system("cls");
                Mixto(precio);
                break;


            default:
                system("cls");
                set_color(L_Rojo);
                cout << "[!] Error: opcion no valida";
                reset_color();
                cout << endl;
                break;
        }
    }

}

void inicio() {
    vector <int> precios;
    vector <string> cajas {"Chocolate", "Dulce de leche", "Fruta", "Mixto"};
    int precio;

    for (int i = 0; i < 4; i++) {
        system("cls");
        cout << "[i] Ingrese el valor de la caja de " << cajas[i] << ": ";
        cin >> precio;
        precios.push_back(precio);
    }

    opciones(precios);

}


int main(int argc, char const *argv[]) {
    inicio();
    return 0;
}
