import java.util.Scanner;

class HelloWorld {
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        while (true){
            int num = myObj.nextInt();
            if (num > 0 && num <= 100) {
                if (num  % 2 == 0)                 System.out.println(num + " es par");
                else System.out.println(num + " no es par");
            } else System.out.println("Odio java");
        
            
        }
    }
}
