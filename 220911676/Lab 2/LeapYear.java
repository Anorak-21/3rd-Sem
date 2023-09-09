class LeapYear{

public static void main(String args[]){

int i,ck,lpyr=1;

ck=Integer.parseInt(args[0]);

if (ck%4 != 0) {lpyr=0;}
else if(ck%100== 0) {lpyr=0;}

if (lpyr==0 && ck%400==0) {lpyr=1;}




if (lpyr==0) {System.out.println("It is Not a leap year");}
else  {System.out.println("It is a leap year");}

}}