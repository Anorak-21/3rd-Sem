class Palin{

public static void main(String args[]){

int i,ck,new1=0,fin=0,tock;

ck=Integer.parseInt(args[0]);
tock=ck;
while (ck>0) {
	new1=ck%10;
	ck=ck/10;
	fin=fin*10+new1;

}

if (tock==fin){
System.out.println("The given number is a Palindrome");}
else {
System.out.println("The given number is not a Palindrome");}



}


}