class GenericStack<T> {
    private T[] stack;
    private int top;
    public GenericStack() {
        stack = (T[]) new Object[100];
        top = -1;}
    public void push(T item) {
        stack[++top] = item;}
    public T pop() {
        if (top == -1) {
            return null;}
        return stack[top--];}
    public boolean isEmpty() {
        return top == -1;}}

class Student {
    private String name;
    private int age;
    public Student(String name, int age) {
        this.name = name;
        this.age = age;}
    public String getName() {
        return name;}
    public int getAge() {
        return age;}
}

class Employee {
    private String name;
    private int salary;
    public Employee(String name, int salary) {
        this.name = name;
        this.salary = salary;}
    public String getName() {
        return name;}
    public int getSalary() {
        return salary;}}

class MainGen {
    public static void main(String[] args) {
        GenericStack<Student> studentStack = new GenericStack<>();
        studentStack.push(new Student("Alice", 20));
        studentStack.push(new Student("Bob", 21));
        studentStack.push(new Student("Charlie", 22));

        while (!studentStack.isEmpty()) {
            Student student = studentStack.pop();
            System.out.println("Name: " + student.getName() + ", Age: " + student.getAge());
        }

        GenericStack<Employee> employeeStack = new GenericStack<>();
        employeeStack.push(new Employee("David", 50000));
        employeeStack.push(new Employee("Eva", 60000));
        employeeStack.push(new Employee("Frank", 70000));

        while (!employeeStack.isEmpty()) {
            Employee employee = employeeStack.pop();
            System.out.println("Name: " + employee.getName() + ", Salary: " + employee.getSalary());
        }
    }
}
