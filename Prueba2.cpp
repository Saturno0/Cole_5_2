#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

const string f_rojo = "\033[1;31m";

void reset_color() {
	cout << "\033[0m";
}

void set_color(const string &color) {
	cout << color;
}

int main () {
	set_color(f_rojo);
    cout << "Hola mundo";
    reset_color();
    return 0;
}
