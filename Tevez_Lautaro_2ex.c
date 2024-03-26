#include <stdio.h>
#include <stdlib.h>

void first_ex() {
    int alumnos;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &alumnos);
    if (alumnos > 0) {
        int precio_bus;
        if (alumnos <= 100) {
            precio_bus= alumnos * 500;
            printf("El precio del bus es de %d\nLos alumnos pagan: $500\n", precio_bus);
        }else if (alumnos <= 50 && alumnos >= 99) {
            precio_bus= alumnos * 400;
            printf("El precio del bus es de %d\nLos alumnos pagan: $400\n", precio_bus);
        }else if (alumnos <= 30 && alumnos >= 49) {
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
    int cantidad_ventas;
    float sueldo_base,ventas[cantidad_ventas];

    printf("Ingrese su sueldo base: "); scanf("%2f", &sueldo_base);
    printf("\nIngrese la cantidad de ventas que realizo: "); scanf("%d", &cantidad_ventas);
    printf("\nIngrese de cuanto fue cada venta: "); scanf("%2f %2f %2f", ventas[0], ventas[1], ventas[2]);

    int subtotal_sueldo = 0;

    for(int i = 0; i < cantidad_ventas; i++) subtotal_sueldo += (ventas[i] * 0.1);

    int sueldo_total = sueldo_base + subtotal_sueldo;
    printf("tu sueldo va a ser de %f\n", sueldo_total);

}


void third_ex () {
    float f_parcial, s_parcial, t_parcial, e_final, trabajo_final;
    printf("Ingrese la nota de sus tres parciales: "); scanf("%1f %1f %1f", &f_parcial, &s_parcial, &t_parcial);
    printf("Ingrese la nota de su examen final: "); scanf("%1f", &e_final);
    printf("Ingrese la nota de su trabajo final: "); scanf("%1f", &t_final);
    
    float nota_final = (((f_parcial + s_parcial + t_parcial) / 3) * 0.55 + e_final * 0.3 + t_final * 0.15);

    printf("La nota final es: %2f", nota_final);
}

void fourth_ex() {
    int a,b;
    printf("Ingrese dos numeros: "); scanf("%d %d", &a, &b);

    for(int i = a; i <= b; i++) {
        if(i%2 == 0) printf("-%d\n", i);
    }
}

void  fifth_ex() {
    
}



int main(int argc, char *argv[]) {
    menu();
    
	return 0;
}
