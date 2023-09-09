class Number{
private double num;

Number(){num=0;}
Number(double num){this.num=num;}

boolean isZero() {return num==0;} 

boolean isPositive() {return num>0;} 

boolean isNegative() {return num<0;} 

boolean isOdd() {return num%2!=0;} 

boolean isEven() {return num%2==0;} 

boolean isPrime() {
int prime=1;
for(int i=2;i<num;i++){
	if(num%i==0) prime=0;}
return prime==1;} 

boolean isArmstrong() {
double x=num,arm=0,a=0;
while(x>0) {
a=x%10;
x=x/10;
arm=arm+a*a*a;}
return num==arm;}

} 

class MainNo{
public static void main(String args[]){

Number num=new Number(5);

System.out.println("isZero() "+num.isZero());
System.out.println("isPositive() "+num.isPositive());
System.out.println("isNegative()"+num.isNegative());
System.out.println("isOdd()"+num.isOdd());
System.out.println("isEven()"+num.isEven());
System.out.println("isArmstrong()"+num.isArmstrong());
System.out.println("isPrime()"+num.isPrime());






}
}

