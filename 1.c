#include <stdio.h>
#include <stdlib.h>

void positivo_negativo(int a) {
    if (a > 0) printf("%d es positivo\n", a);
    else if (a < 0) printf("%d es negativo\n", a);
    else printf("El numero es 0");
}

void par_impar(int a) {
    if (a % 2 == 0) printf("%d es par\n", a);
    else printf("%d es impar", a);
}

void multiplo(int a) {
    if (a % 2 == 0) printf("%d es multiplo de 2\n", a);
    else if (a % 3 == 0) printf("%d es multiplo de 3\n", a);
    else if (a % 3 == 0 && a % 2 == 0) printf("%d es multiplo de 3 y 2\n", a);
    else if (a == 0) printf("El numero es 0");
    else printf("El numero no es multiplo de 2 ni 3");
}

void mayor_menor(int a, int b, int c) {
    if (a == b) {
        if (a > c) printf("%d y %d son mayores que %d", a,b,c);
        else if (a == c) printf("todos son iguales");
        else printf("%d es el mayor", c);
    } else if (a == c) {
        if (a > b) printf("%d y %d son mayores que %d", a,c,b);
        else if (a == b) printf("todos son iguales");
        else printf("%d es el mayor", b);
    } else if (a > b) {
        if (a > c) printf("%d es el mayor", a);
        else printf("%d es el mayor", c);
    } else if (b > c) {
        printf("%d es el mayor", b);
    } else {
        printf("%d es el mayor", c);
    }
}


int main(int argc, char *argv[]) {
	int option;
    int a,b,c;
	
	printf("Seleccione que accion quiere realizar:\n");
	printf("Opcion 1: saber si un n° es positivo o negativo\nOpcion 2: saber si un n° es par o impar.\n");
	printf("Opcion 3: saber si un n° es multiplo de 2 o 3\n Opcion 4: saber cual de 3 numeros es el mayor.\n");
	scanf("%d", &option);
	
	switch(option) {
		case 1:
            scanf("%d", &a);
			positivo_negativo(a);
            break;
            ;
		case 2:
            scanf("%d", &a);
			par_impar(a);
            break;
            ;
		case 3:
            scanf("%d", &a);
			multiplo(a);
            break;
            ;
		case 4:
            scanf("%d %d %d", &a, &b, &c);
			mayor_menor(a,b,c);
            break;
            ;
		default:
			printf("seleccione una opcion valida\n");
	}
	return 0;
}
