class RectangleArea{
	public static void main(String args[]){

	length=Integer.parseInt(args[0]);
	breadth=Integer.parseInt(args[1]); 
	int area=length *breadth;
	int cir=(length+breadth)*2;
	System.out.println("Length of Rectangle = "+ length);
	System.out.println("breadth of Rectangle = "+ breadth);
	System.out.println("Area of Rectangle ="+ area);
	System.out.println("Circumference of Rectangle ="+ cir);


}}