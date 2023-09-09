
class CheckNo {

public static void main(String args[]){

int i,pos=0,zero=0,neg=0,ck;

System.out.println("Enter 10 numbers");

for(i=0;i<10;i++){
	ck=Integer.parseInt(args[i]);
	if (ck<0) {
		neg++;}
	else if (ck>0) {
		pos++;}
	else zero++;
			}

System.out.println("Total Number of Positive Numbers "+pos);
System.out.println("Total Number of Negative Numbers "+neg);
System.out.println("Total Number of Numbers which are Zero "+zero);





}


}