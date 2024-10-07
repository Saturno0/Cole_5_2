#include <stdio.h>

main () {
    int A [3][3];
    int i, j;
    printf ("Este programa te pide una matriz de 3x3 \n \n");
    // ciclo for para pedir datos de la matriz
	  for (i=0; i<3; i++) {
		  for (j=0; j<3; j++) {
			  printf ("Ingresa el valor A[%d][%d]: ", i, j); scanf ("%d", &A[i][j]);
		  }
	  }
    
    // ciclo for para pedir imprimir en pantalla la matriz
	  for (i=0; i<3; i++) {
		  for (j=0; j<3; j++) {
			/* printf ("%d ", A[i][j]);
			puedo agregar un espacio, pero lo que necesito es que baje cada vez
			que termine la fila y eso lo controla el ciclo for con variable i */
			
			// caracter de control \t tabulador horizontal
			  printf ("%d\t", A[i][j]);
		  }
		  printf ("\n");
	  }  
  }
