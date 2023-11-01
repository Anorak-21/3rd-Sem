import java.util.Scanner;

public class MainStudent {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name;
        int rollNumber;
        float marks1, marks2, marks3;
        float totalMarks, percentage;

        try {
            System.out.print("Enter student's name: ");
            name = sc.nextLine();
            System.out.print("Enter student's roll number: ");
            rollNumber = Integer.parseInt(sc.nextLine());
            System.out.print("Enter marks in subject 1,2,3: ");
            marks1 = sc.nextInt();
            marks2 = sc.nextInt();
            marks3 = sc.nextInt();

            totalMarks = marks1 + marks2 + marks3;
            percentage = (totalMarks / 300) * 100;

            System.out.println("Total Marks: " + totalMarks);
            System.out.println("Percentage: " + percentage + "%");
            System.out.println("Grade: " + (percentage/10));

        } catch (NumberFormatException e) {
            System.out.println("\nError: Invalid input. Please enter a valid number.");
        }
    }
}
