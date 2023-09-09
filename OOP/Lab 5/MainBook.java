import java.util.*;

class Book{

String title;
String author;
int edition;

Book(){
this.title="";
this.author="";
this.edition=0;}


Book(String title,String author,int edition) {
this.title=title;
this.author=author;
this.edition=edition;}

void display(){
System.out.println("Title: "+title+" Author: "+author+" Edition: "+edition);}
}

class MainBook{
public static void main(String args[]){

Scanner sc= new Scanner(System.in);

Book[] book= new Book[6];
book[0]= new Book("ABCD","Piyush",1);
book[1]= new Book();
book[2]= new Book("PQRS","Udai",4);
book[3]= new Book("GRTS","Akul",5);
book[4]= new Book();
book[5]= new Book("HSI","Ishan",2);


System.out.print("Enter author name ");  
String str= sc.nextLine();  


for(int i=0; i<book.length;i++){
	if(book[i].author.equals(str)) {book[i].display();}}


}
}