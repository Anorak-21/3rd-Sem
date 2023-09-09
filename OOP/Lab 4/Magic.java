import java.util.*;

class Magic{

public static void main(String args[]) {


Scanner sc= new Scanner(System.in);
System.out.println("Enter order number ");
int m=sc.nextInt();
int n=sc.nextInt();
int[][] arr=new int[50][50];
int Magic[]=new int[50];
int magic=1,sum=0,top=0;

System.out.print("Enter Elements");
for(int i=0;i<m;i++) {
	for(int j=0;j<n;j++) {
		arr[i][j]=sc.nextInt();} }

for(int i=0;i<m;i++) { // Row Sum
	sum=0;
	for(int j=0;j<n;j++) {
		sum=sum+arr[i][j];}
	Magic[top++]=sum;}
for(int j=0;j<n;j++) { // Column Sum 
	sum=0;
	for(int i=0;i<n;i++) {
		sum=sum+arr[i][j];}
	Magic[top++]=sum;}
sum=0;
for(int i=0;i<m;i++) { // Non Prin Diagonal
	for(int j=0;j<n;j++) {
	if(i+j==m-1) {
		sum=sum+arr[i][j];}}}
Magic[top++]=sum;
sum=0;
for(int i=0;i<m;i++) { // Prin Diagonal
	for(int j=0;j<n;j++) {
	if(i==j) {
		sum=sum+arr[i][j];}}}
Magic[top++]=sum;


for(int i=1;i<top;i++){
	//System.out.println(Magic[i]+" "+top);
	if(Magic[i]!=Magic[i-1]) 
		{magic=0;}}


if(magic==1) System.out.print("The Matrix is a Magic Square");
else  System.out.print("The Matrix is not a Magic Square");

}}