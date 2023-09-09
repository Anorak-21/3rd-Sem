import java.util.*;

class Armstrong{

public static void main(String args[]) {

Scanner sc= new Scanner(System.in);
System.out.println("Enter a number ");
int n=sc.nextInt();

int x=n,arm=0,a;
while(x>0) {

a=x%10;
x=x/10;
arm=arm+a*a*a;}


if(n==arm){
System.out.println("The resultant number is an Armstrong Number");}
else{
System.out.println("The resultant number is not an Armstrong Number");}


}}