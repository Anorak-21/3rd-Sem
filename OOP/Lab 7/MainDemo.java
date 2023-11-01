class Demo{

static int counter;

Demo(){
counter++;
System.out.println("Counter is increased");}
}

class MainDemo{
	public static void main(String args[]){

Demo Obj1 = new Demo();
Demo Obj2 = new Demo();
Demo Obj3 = new Demo();

System.out.println("The total number of objects created "+Demo.counter);
}}