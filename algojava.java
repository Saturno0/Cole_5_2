
package project;

import java.util.Scanner;


class project {
 
	public static void main(String[] args) {
        boolean bool = true;
        
        try {
        	Scanner leer = new Scanner(System.in);
        	do {
        		System.out.print("Ingrese qué ejercicio quiere ver (1,2,3,4,5,6,7,8) o 0 para salir: ");
                
                int option = leer.nextInt();
                    switch(option) {
                        case 1:
                            ejercicio1();
                            break;
                        case 2:
                            ejercicio2();
                            break;
                        case 3:
                            ejercicio3();
                            break;
                        case 4:
                            ejercicio4();
                            break;
                        case 5:
                            ejercicio5();
                            break;
                        case 6:
                            Fernando();
                            break;
                        case 7:
                            pares();
                            break;
                        case 8:
                            iva();
                            break;
                        case 0:
                            bool = false;
                            break;
                        default:
                            System.out.println("Opción no válida.");
                            break;
                    }
            
        	} while (bool);
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
        }
        
            
    }
 
 private static void ejercicio1() {
     for (int i = 1; i <= 100; i++){
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
 
 private static void ejercicio3() {
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
     myObj.close();
 }
 
 public static void suma() {
     Scanner myObj = new Scanner(System.in);
     int a,b;
     System.out.println("Ingrese el primer numero: ");
     a = myObj.nextInt();
     System.out.println("Ingrese el segundo numero: ");
     b = myObj.nextInt();
     System.out.println(a + " " + "+ " + b + " = " + (a+b));
     myObj.close();
 }
 public static void resta() {
     Scanner myObj = new Scanner(System.in);
     int a,b;
     System.out.println("Ingrese el primer numero: ");
     a = myObj.nextInt();
     System.out.println("Ingrese el segundo numero: ");
     b = myObj.nextInt();
     System.out.println(a + " " + "- " + b + " = " + (a-b));
     myObj.close();
 }
 public static void multiplicacion() {
     Scanner myObj = new Scanner(System.in);
     int a,b;
     System.out.println("Ingrese el primer numero: ");
     a = myObj.nextInt();
     System.out.println("Ingrese el segundo numero: ");
     b = myObj.nextInt();
     System.out.println(a + " " + "* " + b + " = " + (a*b));
     myObj.close();
 }
 public static void division() {
     Scanner myObj = new Scanner(System.in);
     int a,b;
     System.out.println("Ingrese el primer numero: ");
     a = myObj.nextInt();
     System.out.println("Ingrese el segundo numero: ");
     b = myObj.nextInt();
     System.out.println(a + " " + "/ " + b + " = " + (a/b));
     myObj.close();
 }
 
 private static void ejercicio4() {
     
     while (true) {
    	 Scanner myObj = new Scanner(System.in);
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
         myObj.close();
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
     myObj.close();
 }
 
 public static void print(String texto) {
	 System.out.println(texto);
 }
 
 private static void Fernando() {
	 Scanner leer = new Scanner(System.in);
	 print("Ingrese su nombre: ");
	 String name = leer.nextLine();
	 System.out.println("\nHola " + name);
	 leer.close();
 }
 
 private static void pares() {
	 int n;
	 Scanner leer = new Scanner(System.in);
	 print("Ingrese un numero: ");
	 n = leer.nextInt();
	 if (n % 2 == 0) System.out.print(n + " es par");
	 else			 System.out.print(n + " es impar");
	 leer.close();
 }
 
 private static void iva() {
	 double precio;
	 Scanner leer = new Scanner(System.in);
	 print("Ingrese un precio: ");
	 precio = leer.nextDouble();
	 final double iva = (precio * 0.21);
	 double precio_final= precio + iva;
	 System.out.println("El precio final seria de: " + precio_final);
	 leer.close();
 }
}
