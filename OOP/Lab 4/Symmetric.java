import java.util.*;

class Symmetric{

public static void main(String args[]) {


Scanner sc= new Scanner(System.in);
System.out.println("Enter order number ");
int m=sc.nextInt();
int n=sc.nextInt();
int[][] arr=new int[50][50];
int symm=1;

System.out.print("Enter Elements");
for(int i=0;i<m;i++) {
	for(int j=0;j<n;j++) {
		arr[i][j]=sc.nextInt();} }

for(int i=0;i<m;i++) {
	for(int j=0;j<n;j++) {
	if(arr[i][j]!=arr[j][i]) {
		symm=0;}}}

if(symm==1) System.out.print("The Matrix is Symmetric");
else  System.out.print("The Matrix is not Symmetric");

}}
	