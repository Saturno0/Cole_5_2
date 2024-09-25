package project;


import java.util.*;
import java.math.*;


class project {
 
	public static void main(String[] args) {
        boolean bool = true;
        
        try {
        	Scanner leer = new Scanner(System.in);
        	do {
        		System.out.print("Ingrese qué ejercicio quiere ver (1,2,3,4,5,6,7,8,9) o 0 para salir: ");
                
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
                        case 9:
                        	f_cuadratica();
                        	break;
                        case 0:
                            bool = false;
                            break;
                        default:
                            System.out.println("Opción no válida.");
                            break;
                    }
            
        	} while (bool);
        	leer.close();
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
 
 public static boolean checkprimo(int i) {
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
 }
 
 private static void iva() {
	 double precio;
	 Scanner leer = new Scanner(System.in);
	 print("Ingrese un precio: ");
	 precio = leer.nextDouble();
	 final double iva = (precio * 0.21);
	 double precio_final= precio + iva;
	 System.out.println("El precio final seria de: " + precio_final);
 }
 
 public static void cuadratica(double a, double b, double c) {
	 double n1 = ((-b) + Math.sqrt(Math.pow(b, 2) - (4 * a * c))) / (2 * a);
	 double n2 = ((-b) - Math.sqrt(Math.pow(b, 2) - (4 * a * c))) / (2 * a);
	 
	 System.out.println("Estos son los dos resultados: " + n1 + " y " + n2);
 }
 
 private static void f_cuadratica() {
	 double a = 0,b = 0,c = 0;
	 double nums[] = {a,b,c};
	 Scanner abc = new Scanner(System.in);
	 
	 System.out.println("Ingrese los valores de a,b y c en ese orden: ");
	 
	 for(int i = 0; i < nums.length; i++) {
		 nums[i] = abc.nextDouble();
	 }
	 
	 cuadratica(nums[0],nums[1],nums[2]);
	 
 }
 
 private static void _26 () {
	 Scanner leer = new Scanner(System.in);
	 int n,i = 1;
	 System.out.print("Ingrese un numero mayor a 1 y que sea entero: ");
	 while (true) {
		 n=leer.nextInt();
		 if (n >= 1) {
			 for(int j = 1; j <= n; j++) {
				 i += j;
			 }
			 System.out.println("La suma es: " + i);
			 break;
		 } else {
			 System.out.println("Ingresa un numero mayor a 1 papito dale, yo se que no sos tan boludo: ");
		 }
	 }
	 
 }
 
 private static void introducidos() {
	 Stack<Integer> nums = new Stack<>();
	 Scanner leer = new Scanner(System.in);
	 int n = 0;
	 System.out.println("Ingrese -1 si quiere terminar el programa");
	 while (n != -1) {
		 n = leer.nextInt();
		 nums.push(n);
	 }
	 
	 System.out.println(nums.size());
 }
 
 private static void remplazar() {
	 Scanner leer = new Scanner(System.in);
	 System.out.println("Ingrese una oracion o palabra");
	 String word = leer.nextLine();
	 System.out.println("Que ejercicio quiere seguir? (23 o 28)");
	 String word2 = "";
	 char chara;
	 for (int i = 0; i < word.length(); i++) {
		 chara = word.charAt(i);
		 if(chara != ' ') {
			 word2 += String.valueOf(chara);
		 }
	 }
	 System.out.println("Tu primera frase fue: " + word + "\nSu frase final es: " + word2);
 }
 
 private static void _30() {
	 Scanner leer = new Scanner(System.in);
	 String linea = leer.nextLine();
	 
	 System.out.print("Quiere pasarlo todo a mayusculas o a minusculas?(M = mayusculas/ m = minusculas) ");
	 String linea2 = "";
	 
	 while (true) {
		 char option = leer.next().charAt(0);
		 switch(option) {
		 	case 'M':
		 		linea2 = linea.toUpperCase();
		 		break;
		 	case 'm':
		 		linea2 = linea.toLowerCase();
		 		break;
		 	default:
		 		System.out.print("Ingrese una opcion correcta: ");
		 		continue;
		 }
		 
		 break;
	 }
	 System.out.println("Primera linea: " + linea +  "\nSegunda linea: " + linea2);
	 
 }
 
 
 private static void _31() {
	 Scanner leer = new Scanner(System.in);
	 String linea = leer.nextLine();
	 System.out.println(linea.length());
 }
 
 
 private static void _32() {
	 Scanner leer = new Scanner(System.in);
	 String linea1 = leer.next();
	 System.out.print("Ingrese otra palabra (puede ser la misma): ");
	 String linea2 = leer.next();
	 
	 if(linea1.equals(linea2)) System.out.println("Son iguales");
	 else					   System.out.println("No son iguales");
 }
 
 private static void _33() {
	 Scanner leer = new Scanner(System.in);
	 String linea1 = leer.next();
	 
	 System.out.println(linea1.substring(4, 6));
 }
 
 private static void _34() {
	 Scanner leer = new Scanner(System.in);
	 String linea1 = leer.next();
	 String palabras[] = linea1.split(" ");
	 
	 for (String s : palabras) {
		 System.out.println(s);
	 }
 }
 
 public enum Dias {
	 LUNES,
	 MARTES,
	 MIERCOLES,
	 JUEVES,
	 VIERNES,
	 SABADO,
	 DOMINGO;
}
 
 private static void _35() {
	 Scanner leer = new Scanner(System.in);
	 
	 String day = leer.next();
	 Dias diaS = Dias.valueOf(day.toUpperCase());
	 
	 
	 switch(diaS){
     	case LUNES:
     	case MARTES:
     	case MIERCOLES:
     	case JUEVES:
     	case VIERNES:
     		System.out.println("El dia "+ diaS.name().toLowerCase() + " es laborable");
     		break;
     	case SABADO:
     	case DOMINGO:
     		System.out.println("El dia " + diaS + " no es laborable");
     		break;
     
	 }
 }
 
 public enum DiasSemana {
	 LUNES(true),
	 MARTES(true),
	 MIERCOLES(true),
	 JUEVES(true),
	 VIERNES(true),
	 SABADO(false),
	 DOMINGO(false);
	 
	 private boolean laburable;
	 
	 private DiasSemana (boolean laburable) {
		 this.laburable = laburable;
	 }
	 
	 @Override
	 public String toString() {
		 if(laburable) {
			 return "Es un dia laburable";
		 } else {
			 return "No es un dia laburable";
		 }
	 }
}
 
 
 
 private static void _36() {
	 
 }
 
}
