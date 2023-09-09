import java.util.*;

class Calci{

public static void main(String args[]){ 
char run='y';

do {

Scanner sc = new Scanner(System.in);
System.out.println("Enter a Number");
float x=sc.nextFloat();
System.out.println("Enter a Operation");
char a=sc.next().charAt(0);
System.out.println("Enter a Number");
float y=sc.nextFloat();

switch(a){

case '+':
	float sum=x+y;
	System.out.println(+sum);
	break;

case '-':
	float diff=x-y;
	System.out.println(+diff);
	break;

case '*':
	float mul=x*y;
	System.out.println(+mul);
	break;

case '/':
	float div=x/y;
	System.out.println(+div);
	break;
}

System.out.println("Enter y for continue and n for exit");
run=sc.next().charAt(0);
}while(run=='y');
}}
