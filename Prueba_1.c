#include <stdio.h>
#include <stdlib.h>

const pi = 3.14;


// -std = c99

void primero() {
	char tipo;
	int tamaño;
	printf("Ingrese el tipo y el tamaño: "); scanf("%c %d", &tipo, &tamaño);
	int precio;
	if (tipo == 'a' || tipo == 'A') {
		if (tamaño == 1) precio = 200;
		if (tamaño == 2) precio = 300;
	}
	if (tipo == 'b' || tipo == 'B') {
		if (tamaño == 1) precio = 300;
		if (tamaño == 2) precio = 500;
	}

	printf("El precio por kilo es de %d\n", precio);
}

void segundo() {
	float base,potencia;
	printf("Ingrese la base y la potencia: "); scanf("%f %f", &base, &potencia);

	int r = 1; // r seria el resultado

	//en este if compruebo si base y potencia son iguales a sus int
	if (base == (int)base && potencia == (int)potencia) {
		base = (int)base;
		potencia = (int)potencia;
		
		for(int i = 1; i <= potencia; i++) {
			r*=base;

		}

		printf("= %d", base, potencia,r);
	} else printf("Ingrese una base o una potencia sin coma\n");
}

void tercero() {
	float r, longitud, area, volumen; //r es de radio
	printf("Ingrese el radio: "); scanf("%f", &r);

	//calculo longitud, area y volumen

	longitud = 2 * pi * r;
	area = pi * (r*r);
	volumen = (4/3) * pi * (r*r*r);

	printf("Longitud = %.2f\nArea = %.2f\nVolumen = %.2f\n");

}

void cuarto() {
	char genero;
	int edad, aportes;

	printf("Ingrese su genero(h/m), su edad y sus años de aporte: "); scanf("%c %d %d", &g, &edad, &aportes);

	//En primera instancia compruebo que genero ingreso, luego compruebo su edad y al final de todo compruebo sus años de aporte

	if (g == 'h' || g == 'H') {
		if(edad >= 65){
			if(aportes > 20) printf("Puede jubilarse.\n");
				else			  printf("No puede jubilarse.\n");
			} else			  printf("No puede jubilarse.\n");
		} else  if(g == 'm' || g == 'M') {
			if(edad >= 60){
				if(aportes > 20) printf("Puede jubilarse.\n");
				else			  printf("No puede jubilarse.\n");
			} else			  printf("No puede jubilarse.\n");
	}
}

void quinto() {

}

int main(int argc, char *argv[]) {
	return 0;
}
