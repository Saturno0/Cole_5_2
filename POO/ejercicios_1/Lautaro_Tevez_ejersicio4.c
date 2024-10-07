#include <stdio.h>
#include <stdlib.h>

void collatz(int n) {
  if(n==1) {
    printf("%d", n);
  } else if (n%2==0) {
    printf("%d\n", n);
    collatz(n/2);
  } else if (n%2!=0) {
    printf("%d\n", n);
    collatz((n*3)+1);
  } else if(n<1) {
    printf("Opcion incorrecta");
  }
}

int main() {
  int n;
  printf("ingrese un nunero: "); scanf("%d", &n);

  collatz(n);
  return 0;
}
