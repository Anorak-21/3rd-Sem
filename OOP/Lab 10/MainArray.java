import java.util.Scanner;

public class MainArray{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int size = sc.nextInt();
        int[] arr = new int[size];
        try {
            for (int i = 0; i < size + 1; i++) {
                arr[i] = i;
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Array index out of bounds exception occurred.");
        }
    }
}
