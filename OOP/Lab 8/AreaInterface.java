import java.util.*;

interface Shape
{
    double area();
}

class Rectangle implements Shape
{
    double length;
    double width;
    Rectangle(double length,double width)
    {
        this.length=length;
        this.width=width;
    }
    public double area()
    {
        return width*length;
    }
}

class Circle implements Shape
{
    double radius;
    Circle(double radius)
    {
        this.radius=radius;
    }
    public double area()
    {
        return 3.1416*radius*radius;
    }
}

class AreaInterface{
    public static void main(String args[]){

        Scanner in = new Scanner(System.in);
        System.out.println("Enter Length of Rectangle: ");
        double length = in.nextDouble();
        System.out.println("Enter Width of Rectangle: ");
        double width = in.nextDouble();
        Rectangle R = new Rectangle(length,width);
        System.out.println("Enter Radius of Circle: ");
        double radius = in.nextDouble();
        Circle C = new Circle(radius);
        Shape S;
        S = R;
        System.out.println("Area of Rectangle: "+S.area());
        S = C;
        System.out.println("Area of Circle: "+S.area());
        in.close();
    }
}