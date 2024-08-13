import java.util.Scanner;


class Test {
    Scanner myObj = new Scanner(System.in);
    
    public static void main(String[] args) {
        //ejersicio1();
        ejercicio2();
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
                    System.out.println(i + " no es un numero primo\nSus divisores son:");
                    for (int k = 1; k <=i; k++){
                        if (i%k==0) System.out.println(k);
                    }
                    return false;
                }
                
        }
        return true;
        
    }
    
    private static void ejercicio2() {
        for (int i = 50; i <= 100; i++) {
            if (checkprimo(i)) System.out.println(i + " es un numero primo\n");
        }
    }
}
