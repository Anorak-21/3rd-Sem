import java.util.*;

class Convert{

public static void main(String args[]){ 

Scanner sc= new Scanner(System.in);

System.out.println("Enter a Integer");
int a=sc.nextInt();
System.out.println("Enter a Double");
double b=sc.nextDouble();
System.out.println("Enter a Character");
char c=sc.next().charAt(0);

byte x=(byte)a;
int y=(int)c;
byte z=(byte)b;
int w=(int)b;
System.out.println("Int to byte "+x);
System.out.println("Char to Int "+y);
System.out.println("Double to byte "+z);
System.out.println("DOuble to Int "+w);
}}
