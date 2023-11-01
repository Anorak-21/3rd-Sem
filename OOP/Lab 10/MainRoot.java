import java.util.Scanner;

public class MainRoot {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        double num = sc.nextDouble();

        try {
	if (num<0) throw new Exception();
	double result = Math.sqrt(num);
	System.out.println("Square root of " + num + " is " + result);}
	catch(Exception e) {System.out.println("Cannot get square root of negative number");}
        

    }
}