// Online Java Compiler
import java.util.Scanner;
import java.util.ArrayList;

class Test {
    
    public static void main(String[] args) {
        //ejersicio1();
        //ejercicio2();
        //ejercicio3();
        //ejercicio4();
        ejercicio5();
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
    
    public static void suma() {
        Scanner myObj = new Scanner(System.in);
        int a,b;
        System.out.println("Ingrese el primer numero: ");
        a = myObj.nextInt();
        System.out.println("Ingrese el segundo numero: ");
        b = myObj.nextInt();
        System.out.println(a + " " + "+ " + b + " = " + (a+b));
    }
    public static void resta() {
        Scanner myObj = new Scanner(System.in);
        int a,b;
        System.out.println("Ingrese el primer numero: ");
        a = myObj.nextInt();
        System.out.println("Ingrese el segundo numero: ");
        b = myObj.nextInt();
        System.out.println(a + " " + "- " + b + " = " + (a-b));
    }
    public static void multiplicacion() {
        Scanner myObj = new Scanner(System.in);
        int a,b;
        System.out.println("Ingrese el primer numero: ");
        a = myObj.nextInt();
        System.out.println("Ingrese el segundo numero: ");
        b = myObj.nextInt();
        System.out.println(a + " " + "* " + b + " = " + (a*b));
    }
    public static void division() {
        Scanner myObj = new Scanner(System.in);
        int a,b;
        System.out.println("Ingrese el primer numero: ");
        a = myObj.nextInt();
        System.out.println("Ingrese el segundo numero: ");
        b = myObj.nextInt();
        System.out.println(a + " " + "/ " + b + " = " + (a/b));
    }
    
    private static void ejercicio4() {
        Scanner myObj = new Scanner(System.in);
        while (true) {
            System.out.println("Ingrese que tipo de operacion arigmetica quiere realizar: + (suma), - (resta), * (multiplicacion), / (division): ");
            char oper = myObj.next().charAt(0);
            switch(oper) {
                case '+':
                    suma();
                    break;
                case '-':
                    resta();
                    break;
                case '*':
                    multiplicacion();
                    break;
                case '/':
                    division();
                    break;
                default:
                    System.out.println("Ingrese un valor valido");
                    break;
            }
        }
    }
    
    private static void ejercicio5() {
        Scanner myObj = new Scanner(System.in);
        int nums[];
        nums = new int[10];
        System.out.println("Ingrese 10 numeros enteros: ");
        for (int i = 0; i < nums.length; i++) {
            int n = myObj.nextInt();
            nums[i] = n;
        }
        System.out.println("Los siguientes numeros que ingreso son primos: ");
        for(int n : nums) {
            if(!checkprimo(n)) {
                System.out.println(n + " es primo");
            }
        }        
        
    }
}
