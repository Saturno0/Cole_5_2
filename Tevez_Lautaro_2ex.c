#include <stdio.h>
#include <stdlib.h>

void first_ex() {
    int alumnos;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &alumnos);
    if (alumnos > 0) {
        int precio_bus;
        if (alumnos >= 100) {
            precio_bus= alumnos * 500;
            printf("El precio del bus es de %d\nLos alumnos pagan: $500\n", precio_bus);
        }else if (alumnos >= 50 && alumnos <= 99) {
            precio_bus= alumnos * 400;
            printf("El precio del bus es de %d\nLos alumnos pagan: $400\n", precio_bus);
        }else if (alumnos >= 30 && alumnos <= 49) {
            precio_bus= alumnos * 300;
            printf("El precio del bus es de %d\nLos alumnos pagan: $300\n", precio_bus);
        }else {
            precio_bus= 6000;
            float precio_alumno = precio_bus/alumnos;
            printf("El precio del bus es de %d\nLos alumnos pagan: $%2f\n", precio_bus, precio_alumno);
        }
    } else {
        printf("Ingresa una cantidad valida de alumnos\n");
        first_ex();
    }
}

void second_ex() {
    int sueldo_base;

    printf("Ingrese su sueldo base: "); scanf("%d", &sueldo_base);
    
    int venta1, venta2, venta3;
    
    printf("Ingrese de cuanto fue cada venta: "); scanf("%d %d %d", &venta1, &venta2, &venta3);

    int subtotal_sueldo = (venta1 + venta2 + venta3) * 0.1;

    int sueldo_total = sueldo_base + subtotal_sueldo;
    printf("tu sueldo va a ser de %d\n", sueldo_total);

}


void third_ex () {
    float f_parcial, s_parcial, t_parcial, e_final, trabajo_final;
    printf("Ingrese la nota de sus tres parciales: "); scanf("%f %f %f", &f_parcial, &s_parcial, &t_parcial);
    printf("Ingrese la nota de su examen final: "); scanf("%f", &e_final);
    printf("Ingrese la nota de su trabajo final: "); scanf("%f", &trabajo_final);
    
    float nota_final = (((f_parcial + s_parcial + t_parcial) / 3) * 0.55 + e_final * 0.3 + trabajo_final * 0.15);

    printf("La nota final es: %2f", nota_final);
}

void fourth_ex() {
    int a,b;
    printf("Ingrese dos numeros: "); scanf("%d %d", &a, &b);

    for(int i = a; i <= b; i++) {
        if(i%2 == 0) printf("_%d\n", i);
    }
}

void  fifth_ex() {
    int km1 = 70;
    int km2 = 150;

    int resto = km2-km1;
    printf("se van a encontrar en el km%d", km1+resto); 
}


void menu() {
    int option;

    printf("Seleccione que accion quiere realizar:\n");
	printf("Opcion 1: Ejersicio 1\nOpcion 2: Ejersicio 2\n");
	printf("Opcion 3: Ejersicio 3\nOpcion 4: Ejersicio 4\nOpcion 5: ejersicio 5\n");
	scanf("%d", &option);

    switch(option) {
		case 1:
			first_ex();
            break;
		case 2:
			second_ex();
            break;
		case 3:
			third_ex();
            break;
		case 4:
			fourth_ex();
            break;
        case 5:
            fifth_ex();
            break;
		default:
			printf("seleccione una opcion valida\n");
            menu();
	}
}



int main(int argc, char *argv[]) {
    menu();
	return 0;
}
