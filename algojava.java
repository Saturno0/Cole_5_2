import java.util.Scanner;


class Test {
    
    public static void main(String[] args) {
        //ejersicio1();
        //ejercicio2();
        ejercicio3();
    }
    
    private static void ejercicio1() {
        for (int i = 1; i <= 100; i++){
            // int num = myObj.nextInt();
            if (i % 2 == 0)                 System.out.println(i + " es par");
            else System.out.println(i + " no es par");
        
        }
    }
    
    private static boolean checkprimo(int i) {
        for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    return true;
                }
        }
        return false;
        
    }
    
    private static void ejercicio2() {
        for (int i = 50; i <= 100; i++) {
            if (checkprimo(i)) {
                System.out.println(i + " no es un numero primo\nSus divisores son:");
                    for (int k = 1; k <=i; k++){
                        if (i%k==0) System.out.println(k);
                    }
                    System.out.println("\n");
                
            } else {
                System.out.println(i + " es un numero primo\n");
            }
        }
    }
    
    private static void ejecicio3() {
        Scanner myObj = new Scanner(System.in);
        while (true) {
            int num = myObj.nextInt();
            if (num < 100 && !checkprimo(num)) {
                System.out.println("No es un numero mayor a 100 ni/o primo");
            } else {
                System.out.println("Es mayor a 100 y primo");
                break;
            }
        }
    }
}
