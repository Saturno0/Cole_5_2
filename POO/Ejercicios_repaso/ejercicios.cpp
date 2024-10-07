#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ejercicio1() {
    double nums[4];
    double suma = 0;
    cout << "Ingrese 4 números: ";
    for (int i = 0; i < 4; i++) {
        cin >> nums[i];
        suma += nums[i];
    }
    double media = suma / 4;
    cout << "Números introducidos: ";
    for (int i = 0; i < 4; i++) {
        cout << nums[i] << " ";
    }
    cout << "\nMedia aritmética: " << media << endl;
}

void ejercicio2() {
    int nums[5];
    cout << "Ingrese 5 números: ";
    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
    }
    cout << "Números en orden inverso: ";
    for (int i = 4; i >= 0; i--) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void ejercicio3() {
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mes;
    cout << "Ingrese un mes (1-12): ";
    cin >> mes;
    if (mes >= 1 && mes <= 12) {
        cout << "El mes " << mes << " tiene " << diasMes[mes - 1] << " días." << endl;
    } else {
        cout << "Mes inválido." << endl;
    }
}

void ejercicio4() {
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mes, dia, diaAnual = 0;
    cout << "Ingrese un mes (1-12): ";
    cin >> mes;
    cout << "Ingrese un día: ";
    cin >> dia;
    for (int i = 0; i < mes - 1; i++) {
        diaAnual += diasMes[i];
    }
    diaAnual += dia;
    cout << "El día " << dia << " del mes " << mes << " es el día " << diaAnual << " del año." << endl;
}

void ejercicio5() {
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mes, dia, diaAnual = 0, diasRestantes = 0;
    cout << "Ingrese un mes (1-12): ";
    cin >> mes;
    cout << "Ingrese un día: ";
    cin >> dia;
    for (int i = 0; i < mes - 1; i++) {
        diaAnual += diasMes[i];
    }
    diaAnual += dia;
    diasRestantes = 365 - diaAnual;
    cout << "Quedan " << diasRestantes << " días hasta el final del año." << endl;
}

void ejercicio6() {
    int nums[10];
    cout << "Ingrese 10 números: ";
    for (int i = 0; i < 10; i++) {
        cin >> nums[i];
    }
    cout << "Números en orden inverso: ";
    for (int i = 9; i >= 0; i--) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void ejercicio7() {
    double nums[10];
    double suma = 0;
    cout << "Ingrese 10 números: ";
    for (int i = 0; i < 10; i++) {
        cin >> nums[i];
        suma += nums[i];
    }
    double media = suma / 10;
    cout << "Números por encima de la media (" << media << "): ";
    for (int i = 0; i < 10; i++) {
        if (nums[i] > media) {
            cout << nums[i] << " ";
        }
    }
    cout << endl;
}

void ejercicio8() {
    int nums[10];
    int mayor;
    cout << "Ingrese 10 números: ";
    for (int i = 0; i < 10; i++) {
        cin >> nums[i];
    }
    mayor = nums[0];
    for (int i = 1; i < 10; i++) {
        if (nums[i] > mayor) {
            mayor = nums[i];
        }
    }
    cout << "El mayor número es: " << mayor << endl;
}

void ejercicio9() {
    double v1[2], v2[2], diferencia[2];
    cout << "Ingrese las componentes del primer vector (2 coordenadas): ";
    cin >> v1[0] >> v1[1];
    cout << "Ingrese las componentes del segundo vector (2 coordenadas): ";
    cin >> v2[0] >> v2[1];
    diferencia[0] = v1[0] - v2[0];
    diferencia[1] = v1[1] - v2[1];
    cout << "La diferencia de los vectores es: (" << diferencia[0] << ", " << diferencia[1] << ")" << endl;
}

void ejercicio10() {
    double v1[3], v2[3], productoEscalar = 0;
    cout << "Ingrese las componentes del primer vector (3 coordenadas): ";
    cin >> v1[0] >> v1[1] >> v1[2];
    cout << "Ingrese las componentes del segundo vector (3 coordenadas): ";
    cin >> v2[0] >> v2[1] >> v2[2];
    for (int i = 0; i < 3; i++) {
        productoEscalar += v1[i] * v2[i];
    }
    cout << "El producto escalar es: " << productoEscalar << endl;
}

void ejercicio11() {
    double v1[3], v2[3], productoVectorial[3];
    cout << "Ingrese las componentes del primer vector (3 coordenadas): ";
    cin >> v1[0] >> v1[1] >> v1[2];
    cout << "Ingrese las componentes del segundo vector (3 coordenadas): ";
    cin >> v2[0] >> v2[1] >> v2[2];
    productoVectorial[0] = v1[1] * v2[2] - v1[2] * v2[1];
    productoVectorial[1] = v1[2] * v2[0] - v1[0] * v2[2];
    productoVectorial[2] = v1[0] * v2[1] - v1[1] * v2[0];
    cout << "El producto vectorial es: (" << productoVectorial[0] << ", " << productoVectorial[1] << ", " << productoVectorial[2] << ")" << endl;
}

void ejercicio12() {
    double v1[2], v2[2];
    cout << "Ingrese las componentes del primer vector (2 coordenadas): ";
    cin >> v1[0] >> v1[1];
    cout << "Ingrese las componentes del segundo vector (2 coordenadas): ";
    cin >> v2[0] >> v2[1];
    if (v1[0] * v2[1] == v1[1] * v2[0]) {
        cout << "Los vectores son linealmente dependientes." << endl;
    } else {
        cout << "Los vectores no son linealmente dependientes." << endl;
    }
}

void ejercicio13() {
    double matriz[2][2], traspuesta[2][2];
    cout << "Ingrese los datos de la matriz 2x2: ";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> matriz[i][j];
            traspuesta[j][i] = matriz[i][j];
        }
    }
    cout << "La traspuesta es: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << traspuesta[i][j] << " ";
        }
        cout << endl;
    }
}

void ejercicio14() {
    double matriz[3][3];
    double determinante;
    cout << "Ingrese los datos de la matriz 3x3: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matriz[i][j];
        }
    }
    determinante = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
                - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
                + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
    cout << "El determinante es: " << determinante << endl;
}

void ejercicio15() {
    double matriz[3][3], adjunta[3][3];
    cout << "Ingrese los datos de la matriz 3x3: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matriz[i][j];
        }
    }
    adjunta[0][0] = matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1];
    adjunta[0][1] = -(matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]);
    adjunta[0][2] = matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0];
    adjunta[1][0] = -(matriz[0][1] * matriz[2][2] - matriz[0][2] * matriz[2][1]);
    adjunta[1][1] = matriz[0][0] * matriz[2][2] - matriz[0][2] * matriz[2][0];
    adjunta[1][2] = -(matriz[0][0] * matriz[2][1] - matriz[0][1] * matriz[2][0]);
    adjunta[2][0] = matriz[0][1] * matriz[1][2] - matriz[0][2] * matriz[1][1];
    adjunta[2][1] = -(matriz[0][0] * matriz[1][2] - matriz[0][2] * matriz[1][0]);
    adjunta[2][2] = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    cout << "La matriz adjunta es: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << adjunta[i][j] << " ";
        }
        cout << endl;
    }
}

void ejercicio16() {
    double matriz[3][3], inversa[3][3], determinante;
    cout << "Ingrese los datos de la matriz 3x3: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matriz[i][j];
        }
    }
    determinante = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
                - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
                + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
    if (determinante != 0) {
        inversa[0][0] = (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) / determinante;
        inversa[0][1] = -(matriz[0][1] * matriz[2][2] - matriz[0][2] * matriz[2][1]) / determinante;
        inversa[0][2] = (matriz[0][1] * matriz[1][2] - matriz[0][2] * matriz[1][1]) / determinante;
        inversa[1][0] = -(matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) / determinante;
        inversa[1][1] = (matriz[0][0] * matriz[2][2] - matriz[0][2] * matriz[2][0]) / determinante;
        inversa[1][2] = -(matriz[0][0] * matriz[1][2] - matriz[0][2] * matriz[1][0]) / determinante;
        inversa[2][0] = (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]) / determinante;
        inversa[2][1] = -(matriz[0][0] * matriz[2][1] - matriz[0][1] * matriz[2][0]) / determinante;
        inversa[2][2] = (matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0]) / determinante;
        cout << "La matriz inversa es: " << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << inversa[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "La matriz no tiene inversa." << endl;
    }
}

void ejercicio17() {
    double matriz1[2][2], matriz2[2][2], producto[2][2] = {0};
    cout << "Ingrese los datos de la primera matriz 2x2: ";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> matriz1[i][j];
        }
    }
    cout << "Ingrese los datos de la segunda matriz 2x2: ";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> matriz2[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                producto[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    cout << "El producto de las matrices es: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << producto[i][j] << " ";
        }
        cout << endl;
    }
}

void ejercicio18() {
    double matriz[3][4], temp;
    cout << "Ingrese los datos de la matriz 3x4 (aumentada): ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> matriz[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        temp = matriz[i][i];
        for (int j = 0; j < 4; j++) {
            matriz[i][j] /= temp;
        }
        for (int k = i + 1; k < 3; k++) {
            temp = matriz[k][i];
            for (int j = 0; j < 4; j++) {
                matriz[k][j] -= matriz[i][j] * temp;
            }
        }
    }
    for (int i = 2; i >= 0; i--) {
        for (int k = i - 1; k >= 0; k--) {
            temp = matriz[k][i];
            for (int j = 0; j < 4; j++) {
                matriz[k][j] -= matriz[i][j] * temp;
            }
        }
    }
    cout << "La solución del sistema es: ";
    for (int i = 0; i < 3; i++) {
        cout << matriz[i][3] << " ";
    }
    cout << endl;
}

void ejercicio19() {
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cout << "Los meses con 30 días son: ";
    for (int i = 0; i < 12; i++) {
        if (diasMes[i] == 30) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int opcion;
    do {
        cout << "Seleccione un ejercicio (1-19) o 0 para salir: ";
        cin >> opcion;
        switch (opcion) {
            case 0: break;
            case 1:
                cout << "Ejercicio 1: Calcular la media aritmética de 4 números.\n";
                ejercicio1();
                break;
            case 2:
                cout << "Ejercicio 2: Mostrar 5 números en orden inverso.\n";
                ejercicio2();
                break;
            case 3:
                cout << "Ejercicio 3: Mostrar los días de un mes dado.\n";
                ejercicio3();
                break;
            case 4:
                cout << "Ejercicio 4: Mostrar el número de día del año.\n";
                ejercicio4();
                break;
            case 5:
                cout << "Ejercicio 5: Calcular días restantes del año.\n";
                ejercicio5();
                break;
            case 6:
                cout << "Ejercicio 6: Mostrar 10 números en orden inverso.\n";
                ejercicio6();
                break;
            case 7:
                cout << "Ejercicio 7: Mostrar números por encima de la media.\n";
                ejercicio7();
                break;
            case 8:
                cout << "Ejercicio 8: Encontrar el mayor de 10 números.\n";
                ejercicio8();
                break;
            case 9:
                cout << "Ejercicio 9: Calcular diferencia de dos vectores en el plano.\n";
                ejercicio9();
                break;
            case 10:
                cout << "Ejercicio 10: Calcular producto escalar de dos vectores en el espacio.\n";
                ejercicio10();
                break;
            case 11:
                cout << "Ejercicio 11: Calcular producto vectorial de dos vectores en el espacio.\n";
                ejercicio11();
                break;
            case 12:
                cout << "Ejercicio 12: Verificar dependencia lineal de dos vectores en el plano.\n";
                ejercicio12();
                break;
            case 13:
                cout << "Ejercicio 13: Calcular la traspuesta de una matriz 2x2.\n";
                ejercicio13();
                break;
            case 14:
                cout << "Ejercicio 14: Calcular el determinante de una matriz 3x3.\n";
                ejercicio14();
                break;
            case 15:
                cout << "Ejercicio 15: Calcular la matriz adjunta de una matriz 3x3.\n";
                ejercicio15();
                break;
            case 16:
                cout << "Ejercicio 16: Calcular la matriz inversa de una matriz 3x3.\n";
                ejercicio16();
                break;
            case 17:
                cout << "Ejercicio 17: Calcular el producto de dos matrices 2x2.\n";
                ejercicio17();
                break;
            case 18:
                cout << "Ejercicio 18: Resolver un sistema de 3 ecuaciones con 3 incógnitas usando el método de Gauss.\n";
                ejercicio18();
                break;
            case 19:
                cout << "Ejercicio 19: Mostrar los meses con 30 días.\n";
                ejercicio19();
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 0);
    return 0;
}
