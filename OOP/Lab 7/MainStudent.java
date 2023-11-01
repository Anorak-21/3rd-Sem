class Student_Detail{

private int ID;
private String CollegeName;
private String Name;

Student_Detail(int ID,String CollegeName,String Name){
this.ID=ID;
this.CollegeName=CollegeName;
this.Name=Name;}

void display_details(){
System.out.println("Details: College Name "+CollegeName+" Name "+Name+" ID "+ID);}
}


class MainStudent{
	public static void main(String args[]){
Student_Detail Obj1 = new Student_Detail(123456,"MIT","Piyush");
Student_Detail Obj2 = new Student_Detail(78910,"MIT","Akul");

Obj1.display_details();
Obj2.display_details();

}}