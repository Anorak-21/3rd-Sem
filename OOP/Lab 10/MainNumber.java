import java.util.Scanner;

class MainNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: ");
        String input = sc.nextLine();
        try {
            int num = Integer.parseInt(input);
            System.out.println("The number is " + num);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter a valid integer.");
        }
    }
}
