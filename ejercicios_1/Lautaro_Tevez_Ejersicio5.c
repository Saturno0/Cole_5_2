// hay que usar -std=c99 antes de compliar

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int a,b,c;
    
    for(a = 1; a <= 500; a++) {
        for ( b = 1; b <= 500; b++) {
            c = sqrt(a*a + b*b);
            if (c <= 500 && c*c == a*a + b*b) printf("[+] %d %d %d\n", a,b,c);
        }
        
    }
}   
