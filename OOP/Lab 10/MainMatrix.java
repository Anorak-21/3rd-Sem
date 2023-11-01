import java.util.*;

class MainMatrix{
	public static void main(String args[]){
	Scanner sc = new Scanner(System.in);
	try {
	System.out.println("Enter dimensions of the Matrix");    	
	int m = sc.nextInt();
	int n = sc.nextInt();
	if(m!=n) throw new MyException("Size of both the matrix is not equal, it is not a Square Matrix.");
} catch (MyException e) {
    System.out.println(e);
}
}}

class MyException extends Exception {
    public MyException(String errorMessage) {
        super(errorMessage);
    }
}