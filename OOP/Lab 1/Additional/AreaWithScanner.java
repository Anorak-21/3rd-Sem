import java.util.*;
class AreaWithScanner{
	public static void main(String args[]){

	
	float length1,breadth1;
	System.out.println("Enter Length");
	Scanner length= new Scanner(System.in);
	System.out.println("Enter Breadth");
	
	length1=length.nextFloat();
	breadth1=length.nextFloat();	


	float area=length1*breadth1;
	float cir=(length1+breadth1)*2;


	System.out.println("Length of Rectangle = "+ length1);	
	System.out.println("breadth of Rectangle = "+ breadth1);
	System.out.println("Area of Rectangle ="+ area);
	System.out.println("Circumference of Rectangle ="+ cir);

}}