import java.util.*;

class CkPrime{

public static void main(String args[]) {

Scanner sc= new Scanner(System.in);
System.out.println("Enter numbers n and m ");
int n=sc.nextInt();
int m=sc.nextInt();

for(int x=n;x<m;x++){
	int prime=1;
	for(int i=2;i<x;i++){
		if (x==2) {break;}
		else if(x%i==0){
			prime=0;
			break;}}
	if(prime==1) {
	System.out.println(""+x);}
	
}


}}