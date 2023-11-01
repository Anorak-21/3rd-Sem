import java.util.*;

class Account{

String name;
int Accno;
String type;
int balance;

void deposit(int amount){
balance+=amount;
System.out.println("The amount "+amount+" has been succesfully deposited");}

void display(){
System.out.println("The balance amount is: "+balance);}

}

class Savings extends Account{

Savings(String name,int Accno,String type,int balance){

this.name=name;
this.Accno=Accno;
this.type=type;
this.balance=balance;}

void interest(int time){
balance=(balance*6*time)/100+balance;
System.out.println("Interest applied");}

void withdraw(int withdraw){
balance=balance-withdraw;
System.out.println("Sucessfully withdrawn");}
}

class Current extends Account{
int min=1000;

Current(String name,int Accno,String type,int balance){

this.name=name;
this.Accno=Accno;
this.type=type;
this.balance=balance;}

void ckmin(){
if(balance<min){
	System.out.print("The balance is below minimum amount, 100Rs service tax will charged");
	balance=balance-100;}
else {System.out.println("The balance is above minimum balance");}}
}


class MainAccount{
public static void main(String args[]){

Scanner sc= new Scanner(System.in);
System.out.println("Enter Name, Account type (current/savings),Account Number and Balance");
String name=sc.nextLine();
String type=sc.nextLine();
int Accno=sc.nextInt();
int balance=sc.nextInt();


if(type.equals("current")){
	Current cur= new Current(name,Accno,type,balance);
	cur.ckmin();
	cur.deposit(400);
	cur.display();}
else if(type.equals("savings")){
	Savings sav= new Savings(name,Accno,type,balance);
	sav.withdraw(60);
	sav.interest(2);
	sav.display();}






}
}