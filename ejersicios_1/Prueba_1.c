#include <stdio.h>
#include <stdlib.h>

void primero() { // primer ejercicio
    char tipo; // tipo
    int precio, tamano; // precio y tamano
    printf("Ingrese el tipo y el tamano: "); // solicitud de entrada
    scanf(" %c %d", &tipo, &tamano); // escaneo de entrada

    // comprobación del tipo y tamano
    if (tipo == 'a' || tipo == 'A') {
        if (tamano == 1) precio = 200;
        else if (tamano == 2) precio = 300;
        else {
            printf("Ingrese un tamano valido\n");
            primero(); // llamada recursiva si no es un tamano válido
            return; // retorno
        }
    } else if (tipo == 'b' || tipo == 'B') {
        if (tamano == 1) precio = 300;
        else if (tamano == 2) precio = 500;
        else {
            printf("Ingrese un tamano valido\n");
            primero(); // llamada recursiva si no es un tamano válido
            return; // retorno
        }
    } else {
        printf("Ingrese un tipo valido\n");
        primero(); // llamada recursiva si no es un tipo válido
        return; // retorno
    }

    printf("El precio por kilo es de %d\n", precio); // salida del precio
}

void segundo() { // segundo ejercicio
    float base, potencia; // base y potencia
    printf("Ingrese la base y la potencia: "); // solicitud de entrada
    scanf("%f %f", &base, &potencia); // escaneo de entrada

    int r = 1; // resultado

    // comprobación si base y potencia son enteros
    if (base == (int)base && potencia == (int)potencia) {
        base = (int)base;
        potencia = (int)potencia;
        
        // cálculo de la potencia
        for(int i = 1; i <= potencia; i++) {
            r*=base; // potencia
        }

        printf("= %d", r); // salida de resultado
    } else printf("Ingrese una base o una potencia sin coma\n"); // mensaje de error
}


#define PI 3.14 // Define PI

void tercero() { // tercer ejercicio
    float r, longitud, area, volumen; // radio, longitud, area, y volumen
    printf("Ingrese el radio: "); // solicitud de entrada
    scanf("%f", &r); // escaneo de entrada

    // cálculo de longitud, area y volumen
    longitud = 2 * PI * r;
    area = PI * (r*r);
    volumen = (4.0/3.0) * PI * (r*r*r);

    // salida de resultados
    printf("Longitud = %.2f\nArea = %.2f\nVolumen = %.2f\n", longitud, area, volumen);
}



void cuarto() { // cuarto ejercicio
    char genero; // género
    int edad, aportes; // edad y anos de aporte

    printf("Ingrese su genero (h/m), su edad y sus anos de aporte: "); // solicitud de entrada
    scanf(" %c %d %d", &genero, &edad, &aportes); // escaneo de entrada

    // comprobación de género, edad y anos de aporte
    if ((genero == 'h' || genero == 'H') && edad >= 65 && aportes > 20) {
        printf("Puede jubilarse.\n");
    } else if ((genero == 'm' || genero == 'M') && edad >= 60 && aportes > 20) {
        printf("Puede jubilarse.\n");
    } else {
        printf("No puede jubilarse.\n");
    }
}


void quinto() { // quinto ejercicio
    int cant_hijos, hijos_escolares, subsidio; // cantidad de hijos, hijos escolares y subsidio
    printf("Ingrese la cantidad de hijos que tiene: "); // solicitud de entrada
    scanf("%d", &cant_hijos); // escaneo de entrada

    int edad_hijos[cant_hijos]; // arreglo para almacenar edades

    hijos_escolares = 0; // inicialización de hijos escolares
    for (int i = 0; i < cant_hijos; i++) { // bucle para cada hijo
        printf("Ingrese la edad de su %d° hijo: ", i + 1); // solicitud de entrada
        scanf("%d", &edad_hijos[i]); // escaneo de entrada

        // comprobación de edad de hijos escolares
        if (edad_hijos[i] >= 6 && edad_hijos[i] <= 18) hijos_escolares+=1;
    }

    // cálculo del subsidio
    if (hijos_escolares <= 2) subsidio = 700 * hijos_escolares;
    else if (hijos_escolares <= 5 && hijos_escolares > 2) subsidio = 800 * hijos_escolares;
    else if (hijos_escolares > 5) subsidio = 1200 * hijos_escolares;

    // salida del subsidio
    printf("Su subsidio total es de $%d\nLo que equivale a $%d por hijo\n", subsidio, subsidio / hijos_escolares);
}


void Switch() { // función para manejar el menú de opciones
    int opcion; // opción seleccionada

    printf("[+]Ejersicio 1\n[+]Ejersicio 2\n[+]Ejersicio 3\n[+]Ejersicio 4\n[+]Ejersicio 5\n[+]Salir\n"); // menú de opciones
    ("[+]Ingrese una opcion: "); // solicitud de entrada
    scanf("%d", &opcion); // escaneo de entrada
    
    // selección de opción
    switch (opcion) {
        case 1:
            primero();
            break;

        case 2:
            segundo();
            break;

        case 3:
            tercero();
            break;

        case 4:
            cuarto();
            break;

        case 5:
            quinto();
            break;
        
        case 6:
            break;

        default:
            printf("Ingrese una opcion valida\n"); // mensaje de error
            Switch(); // llamada recursiva para ingresar una opción válida
            break;
    }
}

int main(int argc, char *argv[]) {
    Switch(); // inicio del programa
    return 0; // retorno
}
