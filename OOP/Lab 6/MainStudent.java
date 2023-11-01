import java.util.*;

class Student{
String name;
int regno;
int age;}

class UG extends Student{
static int UGno=0;
int semester;
int fees;

UG(String name, int regno, int age,int semester,int fees){
this.name=name;
this.regno=regno;
this.age=age;
this.semester=semester;
this.fees=fees;}

}

class PG extends Student{
static int PGno=0;
int semester ;
int fees;

PG(String name, int regno, int age,int semester,int fees){
this.name=name;
this.regno=regno;
this.age=age;
this.semester=semester;
this.fees=fees;}

}

class MainStudent{

	public static void main(String args[]){
Scanner sc= new Scanner(System.in);

UG ug[]=new UG[100];
PG pg[]=new PG[100];

int c=0;

do{
System.out.println("Enter 1 to Add UG\nEnter 2 to Add PG\nEnter 3 to display all UG and PG students\nEnter 0 to exit");
c=sc.nextInt();

switch(c){

case 1:
	System.out.println("Enter regno, age, semester, fees, name");
	
	int regno1= sc.nextInt();
	int age1 = sc.nextInt();
	int semester1 = sc.nextInt();
	int fees1 = sc.nextInt();
	String smp =sc.nextLine();
	String name1=sc.nextLine();
	ug[UG.UGno] = new UG(name1,regno1,age1,semester1,fees1);
	UG.UGno++;
	break;

case 2:
	System.out.println("Enter regno, age, semester, fees, name");
	
	int regno= sc.nextInt();
	int age = sc.nextInt();
	int semester = sc.nextInt();
	int fees = sc.nextInt();
	String emp= sc.nextLine();
	String name=sc.nextLine();
	pg[PG.PGno] = new PG(name,regno,age,semester,fees);
	PG.PGno++;
	break;

case 3:
	
	System.out.println("\nDetails of UG students");
	for(int i=0;i<UG.UGno;i++) {

		System.out.println("Name: "+ug[i].name+" Regno: "+ug[i].regno+" Age: "+ug[i].age+" Semester: "+ug[i].semester+" Fees: "+ug[i].fees);}

	System.out.println("\nDetails of PG students");
		for(int i=0;i<PG.PGno;i++) {

		System.out.println("Name: "+pg[i].name+" Regno: "+pg[i].regno+" Age: "+pg[i].age+" Semester: "+pg[i].semester+" Fees: "+pg[i].fees);}

	break;


}



} while (c!=0);








}
} 