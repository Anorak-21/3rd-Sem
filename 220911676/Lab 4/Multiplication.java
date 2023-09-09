import java.util.*;

class Multiplication{  
	public static void main(String args[]){  
    
int c[][]=new int[50][50]; 
int d[][]=new int[50][50];

Scanner sc= new Scanner(System.in);
System.out.println("Enter order number for 1st matrix");
int m1=sc.nextInt();
int n1=sc.nextInt();
int[][] a=new int[50][50];
System.out.println("Enter order number for 2nd matrix");
int m2=sc.nextInt();
int n2=sc.nextInt();
int[][] b=new int[50][50];
 

System.out.println("Enter Elements for 1st matrix");
for(int i=0;i<m1;i++) {
	for(int j=0;j<n1;j++) {
		a[i][j]=sc.nextInt();} }
System.out.println("Enter Elements for 2nd matrix");
for(int i=0;i<m2;i++) {
	for(int j=0;j<n2;j++) {
		b[i][j]=sc.nextInt();} }


System.out.println("Added Matrix:");
for(int i=0;i<m1;i++) {
	for(int j=0;j<n1;j++) {
		c[i][j]=a[i][j]+b[i][j];
		System.out.print(+c[i][j]+"\t");}
		System.out.print("\n");} 
System.out.println("Multiplied  Matrix:");
for(int i=0;i<m1;i++){    
	for(int j=0;j<n2;j++){    
		d[i][j]=0;      
		for(int k=0;k<n1;k++) {      
			d[i][j]+=a[i][k]*b[k][j];}  
	System.out.print(d[i][j]+" ");}  
System.out.println();}    



}}  