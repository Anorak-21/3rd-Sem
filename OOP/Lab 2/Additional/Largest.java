import java.util.*;

class Largest{

public static void main(String args[]){ 

Scanner sc = new Scanner(System.in);

System.out.println("Enter value for a");
int a=sc.nextInt();
System.out.println("Enter value for b");
int b=sc.nextInt();
System.out.println("Enter value for c");
int c=sc.nextInt();

int max=(a>b)?((a>c)?a:c):((b>c)?b:c);
int min=(a<b)?((a<c)?a:c):((b<c)?b:c);
System.out.println("The Largest No is "+max);
System.out.println("The Smallest No is "+min);
	


}}
