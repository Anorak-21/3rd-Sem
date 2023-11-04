import java.util.Scanner;

class MyThread extends Thread {
    public void run() {
        System.out.println("Thread created by inheriting Thread class");}}

class MyRunnable implements Runnable {
    public void run() {
        System.out.println("Thread created by implementing Runnable interface");}}

class MainThread{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.println("Menu:");
            System.out.println("1. Create and start a Thread using Thread class");
            System.out.println("2. Create and start a Thread using Runnable interface");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    MyThread thread1 = new MyThread();
                    thread1.start();
                    break;
                case 2:
                    MyRunnable myRunnable = new MyRunnable();
                    Thread thread2 = new Thread(myRunnable);
                    thread2.start();
                    break;
                case 3:
                    System.out.println("Exiting the program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please select a valid option.");}
        }while (choice != 3);
    }
}
