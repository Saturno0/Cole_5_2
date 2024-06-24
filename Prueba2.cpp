#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <string>

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

void Chocolate(){
}


void DDL(){
}


void Fruta(){
}


void Mixto(){
}


void opciones() {
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
        switch (opcion) {
            case 1:
                system("cls");
                Chocolate();
                break;
            case 2:
                system("cls");
                DDL();
                break;
            case 3:
                system("cls");
                Fruta();
                break;
            
            case 4:
                system("cls");
                Mixto();
                break;

            case 5:
                break;

            default:
                set_color(L_Rojo);
                cout << "[!] Error: opcion no valida";
                reset_color();
                cout << endl;
                break;
        }
    }

}


int main(int argc, char const *argv[]) {
    opciones();
    return 0;
}

