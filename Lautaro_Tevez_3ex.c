#include <stdio.h>
#include <stdlib.h>

void uno() {
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        if (i + (i + 1) + (i + 2) == n) printf("%d + %d + %d = %d", i, i + 1, i + 2, n);
    }
}

void dos() {
    float a, b, c;
    printf("Ingrese tres numeros de los cuales quiera sacar el promedio: ");
    scanf("%f %f %f", &a, &b, &c);

    float promedio = (a + b + c) / 3;

    printf("%f", promedio);
}

void tres() {
    int a;

    printf("Ingresa un numero > 0: ");
    scanf("%d", &a);

    if (a > 0) {
        if (a % 2 == 0) printf("%d es par", a);
        else printf("%d es impar", a);

    } else {
        printf("Ingresa uno mayor a 0 porfavor...");
        tres();
    }
}

void cuatro() {
    float nota1, nota2, nota3, nota4, notaT;

    printf("Ingrese las notas del alumno: ");
    scanf("%f %f %f %f %f", &nota1, &nota2, &nota3, &nota4, &notaT);

    float promedio = ((nota1 + nota2 + nota3 + nota4) / 4 + notaT) / 2;

    if (promedio >= 6.0) printf("El alumno aprobo con %f", promedio);
    else printf("el alumno esta desaprobado con %f", promedio);
}

void cinco() {
    int nota;
    printf("ingrese la nota del alumno: ");
    scanf("%d", &nota);
    if (nota >= 6) printf("Aprobado ");
    else if (nota >= 8) printf("Felicidades");
    else {
        printf("Desaprobado");
        if (nota == 1) printf(" Deberias esforzarte mas");
    }
}

void seis() {
    int sueldo;
    printf("Ingrese su sueldo: ");
    scanf("%d", &sueldo);
    printf("Su porcentaje de impuesto es ");

    if (sueldo <= 202) printf("%d", sueldo * 0);
    else if (sueldo > 202 && sueldo <= 607) printf("%d", sueldo * 5 / 100);
    else if (sueldo > 607 && sueldo <= 1013) printf("%d", sueldo * 10 / 100);
    else if (sueldo > 1013 && sueldo <= 1418) printf("%d", sueldo * 15 / 100);
    else if (sueldo > 1418) printf("%d", sueldo * 25 / 100);
}

void siete() {
    int h, m;
    printf("Ingrese la hora y los minutos: ");
    scanf("%d %d", &h, &m);

    if (h > 24 || m > 60 || h < 0 || m < 0) printf("Ingresa una hora valida");

    if (h > 12) {
        printf("%d:", h - 12);
        if (m < 10) printf("0");
        printf("%d pm", m);
    } else {
        printf("%d:", h);
        if (m < 10) printf("0");
        printf("%d am", m);
    }
}


void ocho() {
    float cant_guardada;
    int meses;

    printf("Ingrese la cantidad de dinero guardada y los meses: ");
    scanf("%f %d", &cant_guardada, &meses);

    for (int i = 0; i < meses; i++) {
        cant_guardada += (cant_guardada * 0.02);
    }

    printf("la cantidad de plata que va a tener en %d meses es de $%f", meses, cant_guardada);

}

void nueve() {
    int edad_p = 50;
    int edad_h = 20;
    int anos;

    while (edad_p != 2 * edad_h) {
        edad_h++;
        edad_p++;
        anos++;
    }
    printf("En %d años el padre va a tener el doble de edad que su hijo", anos);

}

void diez() {
    int h, m, s;
    printf("Ingrese hora, minutos y segundos: ");
    scanf("%d %d %d", &h, &m, &s);

    int s_total = ((h * 60 + m) * 60 + s);
    printf("Eso es %d segundos", s_total);
}


void once() {
    float f_parcial, s_parcial, t_parcial, e_final, trabajo_final;
    printf("Ingrese la nota de sus tres parciales: ");
    scanf("%f %f %f", &f_parcial, &s_parcial, &t_parcial);
    printf("Ingrese la nota de su examen final: ");
    scanf("%f", &e_final);
    printf("Ingrese la nota de su trabajo final: ");
    scanf("%f", &trabajo_final);

    float nota_final = (((f_parcial + s_parcial + t_parcial) / 3) * 0.55 + e_final * 0.3 + trabajo_final * 0.15);

    printf("La nota final es: %f", nota_final);
}

void doce() {
    int sueldo_base;

    printf("Ingrese su sueldo base: ");
    scanf("%d", &sueldo_base);

    int venta1, venta2, venta3;

    printf("Ingrese de cuanto fue cada venta: ");
    scanf("%d %d %d", &venta1, &venta2, &venta3);

    int subtotal_sueldo = (venta1 + venta2 + venta3) * 0.1;

    int sueldo_total = sueldo_base + subtotal_sueldo;
    printf("tu sueldo va a ser de %d\n", sueldo_total);

}

void trece() {
    printf("Ingrese cuanto es el costo de la compra: ");
    float compra;
    scanf("%f", &compra);

    compra = compra - (compra * 0.15);

    printf("Con el descuento del 15%% quedaria %f", compra);

}

void catorce() {
    int a, valor_absoluto;
    printf("Ingrese el numero del cual desea saber su valor absoluto: ");
    scanf("%d", &a);

    if (a >= 0) valor_absoluto = a;
    else valor_absoluto = a * (-1);

    printf("El valor absoluto es: %d", valor_absoluto);
}


void quince() {
    int est, h, m, p_mujeres, p_hombres;
    printf("Ingrese la cantidad de estudiantes:");
    scanf("%d", &est);
    printf("Ingrese cuantos son mujeres y cuantos hombres: ");
    scanf("%d %d", &m, &h);

    if (m + h != est) {
        printf("La cantidad de hombres y mujeres que ingreso no concuerda con la cantidad de estudiantes\n");
        quince();
    } else {
        p_mujeres = (m * 100) / est;
        p_hombres = 100 - p_mujeres;

        printf("El porcentaje de mujeres en el curso es de: %d\nEl porcentaje de hombres en el curso es de: %d", p_mujeres, p_hombres);
    }
}


void dieciseis() {
    int pesos, dolares;
    printf("Ingrese el valor del cambio a dolares y despues cuantos pesos tiene: ");
    scanf("%d %d", &dolares, &pesos);

    int cambio = pesos / dolares;
    printf("Tiene $%d dolares", cambio);
}


void diecisiete() {
    char genero;
    int edad;
    float peso, FMC;

    printf("Ingrese su genero, edad y peso para saber su FCM: ");
    scanf(" %c %d %f", &genero, &edad, &peso);

    switch (genero) {
    case 'h':
        FMC = ((210 - (0.5 * edad)) - (peso * 0.01)) + 4;
        break;
    case 'm':
        FMC = ((210 - (0.5 * edad)) - (peso * 0.01));
        break;
    default:
        printf("Ingresa una opcion valida\n");
        diecisiete();
    }

    printf("Su FMC es de: %f", FMC);
}

void Switch(int option) {
    switch (option) {
    case 1:
        uno();
        break;

    case 2:
        dos();
        break;

    case 3:
        tres();
        break;

    case 4:
        cuatro();
        break;

    case 5:
        cinco();
        break;

    case 6:
        seis();
        break;

    case 7:
        siete();
        break;

    case 8:
        ocho();
        break;

    case 9:
        nueve();
        break;

    case 10:
        diez();
        break;

    case 11:
        once();
        break;

    case 12:
        doce();
        break;

    case 13:
        trece();
        break;

    case 14:
        catorce();
        break;

    case 15:
        quince();
        break;

    case 16:
        dieciseis();
        break;

    case 17:
        diecisiete();
        break;

    default:
        break;
    }
}


int main(int argc, char *argv[]) {
    int opcion;
    printf("1. Ejercicio uno\n");
    printf("2. Ejercicio dos\n");
    printf("3. Ejercicio tres\n");
    printf("4. Ejercicio cuatro\n");
    printf("5. Ejercicio cinco\n");
    printf("6. Ejercicio seis\n");
    printf("7. Ejercicio siete\n");
    printf("8. Ejercicio ocho\n");
    printf("9. Ejercicio nueve\n");
    printf("10. Ejercicio diez\n");
    printf("11. Ejercicio once\n");
    printf("12. Ejercicio doce\n");
    printf("13. Ejercicio trece\n");
    printf("14. Ejercicio catorce\n");
    printf("15. Ejercicio quince\n");
    printf("16. Ejercicio dieciseis\n");
    printf("17. Ejercicio diecisiete\n");

    printf("Ingrese una opcion: ");

    scanf("%d", &opcion);
    Switch(opcion);
}
