import java.util.*;

class PrincipalDiagonal{

public static void main(String args[]) {


Scanner sc= new Scanner(System.in);
System.out.println("Enter order number ");
int m=sc.nextInt();
int n=sc.nextInt();
int[][] arr=new int[50][50];
int sum=0;

System.out.print("Enter Elements");
for(int i=0;i<m;i++) {
	for(int j=0;j<n;j++) {
		arr[i][j]=sc.nextInt();} }


for(int i=0;i<m;i++) {
	for(int j=0;j<n;j++) {
	if(i==j) {
		sum=sum+arr[i][j];
		System.out.println(+arr[i][j]);}
		System.out.print(" ");}}

System.out.print("The summation is "+sum);
}}
	