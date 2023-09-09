class Employee{

String name;
String city;
int basic;
int da;
int hra;

void getdata(String name,String city,int basic,int da,int hra){

this.name=name;
this.city=city;
this.basic=basic;
this.da=da;
this.hra=hra;}

int calculate(){
return basic+basic*da/100+basic*hra/100;}

void display(){
System.out.println(calculate());}

}


class MainEmp{
public static void main(String args[]){

Employee emp=new Employee();
emp.getdata("Piyush","Pune",200000,10,15);
emp.display();






}

}