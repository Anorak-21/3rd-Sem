import java.util.*;

class Bank{
void getRateofInterest(int principle){
System.out.println("This is the function of base Bank");
}
}

class SBI extends Bank{
void getRateofInterest(int principle){
System.out.println("This is the function of SBI Bank with Interest 8% and amount "+principle*8/100);}
}

class ICICI extends Bank{
void getRateofInterest(int principle){
System.out.println("This is the function of ICICI Bank with Interest 7% and amount "+principle*7/100);}
}

class AXIS extends Bank{
void getRateofInterest(int principle){
System.out.println("This is the function of AXIS Bank with Interest 9% and amount "+principle*9/100);}
}

class MainBank{
	public static void main(String args[]){

Scanner sc = new Scanner(System.in);
int prin=sc.nextInt();

SBI sbi = new SBI();
sbi.getRateofInterest(prin);

ICICI icici = new ICICI();
icici.getRateofInterest(prin);

AXIS axis = new AXIS();
axis.getRateofInterest(prin);




}
}