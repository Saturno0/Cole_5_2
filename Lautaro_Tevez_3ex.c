#include <stdio.h>
#include <stdlib.h>

void first_ex() {
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    for (int i = 0; i <= n) {
        if ( i + (i + 1) + (i + 2) == n) printf("%d + %d + %d = %d", i, i+1, i+2, n);
    }
}

void second_ex() {
    float a,b,c;
    printf("Ingrese tres numeros de los cuales quiera sacar el promedio: ");
    scanf("%f %f %f", &a, &b, &c);

    float promedio = (a + b + c) / 3;

    printf("%d", promedio);
}

void third_ex() {
    int a;
    
    printf("Ingresa un numero > 0: ");
    scanf("%d", a);

    if (a > 0) {
        if (a % 2 == 0) pritn("%d es par", a);
        else            pritn("%d es impar", a);

    } else {
        printf("Ingresa uno mayor a 0 porfavor...");
        third_ex();
    }
    
}

void fourth_ex() {
    float nota1, nota2, nota3, nota4, notaT;

    printf("ingrese las notas del alumno: "); scanf("%d %d %d %d %d", &nota1, &nota2, &nota3, &nota4, &notaT);

    float promedio = ((nota1 + nota2 + nota3 + nota4) / 4 + notaT) / 2;

    if(promedio >= 6.0) printf("El alumno aprobo con %2f", promedio);
    else              printf("el alumno esta desaporbado con %2f", promedio);
}

void fifth_ex() {
    int nota;
    printf("ingrese la nota del alumno: "); scanf("%d", nota);
    if (nota >= 6) printf("Aprobado ");
    else if (nota >= 8) printf("Felicidades");
    else {
        printf("Desaprobado");
        if (nota == 1) printf("Deberias esforzarte mas");
    }
}

void sixth_ex() {
    int sueldo;
    pritnf("Ingrese su sueldo: "); scanf("%d", &sueldo);
    printf("Su porcentaje de impuesto es ");

    if (sueldo <= 202) printf("%d", sueldo * 0);
    else if (202 < sueldo <= 607) printf("%d", sueldo * 0.05);
    else if (607 < sueldo <= 1013) printf("%d", sueldo * 0.1);
    else if (1013 < sueldo <= 1418) printf("%d", sueldo * 0.15);
    if (1418 < sueldo) printf("%d", sueldo * 0.25); 
}

void seventh() {
    int h,m;
    printf("Ingrese la hora y los minutos"); scanf("%d %d", &h,&m);

    if(h > 24 || m > 60 || h < 0 || m < 0 ) printf("Ingresa una hora valida");

    if (h > 12) {
        printf("%d:", h-12);
        if (m < 10) printf("0");
        printf("%d pm", m);
    } else {
        printf("%d:", h);
        if (m < 10) printf("0");
        printf("%d am", m);
    }
}


void eight_ex() {
    float cant_guardada;
    int meses;

    printf("Ingrese la cantidad de dinero guardada y los meses: "); scanf("%f %d", &cant_guardada, &meses);
    
    for (int i = 0; i < meses; i++) {
        cant_guardada += (cant_guardada * 0.02);
    }
    
    printf("la cantidad de plata que va a tener en %d meses es de $%2f", meses, cant_guardada);
    
}

void nineth() {
    int edad_p = 50;
    int edad_h = 20;
    int anos;

    for (int i = 0; edad_p / 2 == edad_h; i++) {
        edad_h++;
        edad_p++;
        anos = i;
    }
    printf("En %d años el padre va a tener el doble de edad que su hijo", anos);
  
}

void ten_ex() {
    int h,m,s;
    printf("Ingrese hora, minutos y segundos: "); scanf("%d %d %d",&h,&m,&s);

    int s_total = ((h/60)/60) + m/60 + s;
    printf("Eso es %d segundos", s_total);
}


void eleven_ex() {
    float f_parcial, s_parcial, t_parcial, e_final, trabajo_final;
    printf("Ingrese la nota de sus tres parciales: "); scanf("%f %f %f", &f_parcial, &s_parcial, &t_parcial);
    printf("Ingrese la nota de su examen final: "); scanf("%f", &e_final);
    printf("Ingrese la nota de su trabajo final: "); scanf("%f", &trabajo_final);
    
    float nota_final = (((f_parcial + s_parcial + t_parcial) / 3) * 0.55 + e_final * 0.3 + trabajo_final * 0.15);

    printf("La nota final es: %2f", nota_final);
}

void twelfth_ex() {
    int sueldo_base;

    printf("Ingrese su sueldo base: "); scanf("%d", &sueldo_base);
    
    int venta1, venta2, venta3;
    
    printf("Ingrese de cuanto fue cada venta: "); scanf("%d %d %d", &venta1, &venta2, &venta3);

    int subtotal_sueldo = (venta1 + venta2 + venta3) * 0.1;

    int sueldo_total = sueldo_base + subtotal_sueldo;
    printf("tu sueldo va a ser de %d\n", sueldo_total);

}


int main(int argc, char *argv[]) {
    
}