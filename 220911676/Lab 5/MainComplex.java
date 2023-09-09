class Complex {
 

double real;
double imaginary;

Complex(double real, double imaginary) {
this.real = real;
this.imaginary = imaginary;}

void display() {
System.out.println(real + " + " + imaginary + "i");}

static Complex add(int num, Complex com) {
        double newReal = com.real + num;
        return new Complex(newReal,com.imaginary);}

static Complex add(Complex com1,Complex com2) {
        double newReal = com1.real + com2.real;
        double newImaginary = com1.imaginary + com2.imaginary;
        return new Complex(newReal, newImaginary);}

}

class MainComplex {
    public static void main(String[] args) {
        Complex complex1 = new Complex(3.0, 2.0);
        Complex complex2 = new Complex(1.5, 4.5);
	int integer = 5;

        System.out.println("Complex Number 1:");
        complex1.display();

        System.out.println("Complex Number 2:");
        complex2.display();

        System.out.println("Integer to be added: " + integer);

        Complex result1 = Complex.add(integer,complex1);
        System.out.println("Result of Adding Integer to Complex Number 1:");
        result1.display();

        Complex result2 = Complex.add(complex2,complex1);
        System.out.println("Result of Adding Complex Number 2 to Complex Number 1:");
        result2.display();
    }
}
