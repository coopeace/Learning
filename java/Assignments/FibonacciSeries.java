import java.util.Scanner;

public class FibonacciSeries {

    public static void printFibonacci(int n) {
        if (n <= 0) {
            System.out.println("Please enter a positive integer greater than 0.");
            return;
        }

        long a = 0;
        long b = 1;

        System.out.print("Fibonacci series up to " + n + " terms: ");

        for (int i = 1; i <= n; i++) {
            System.out.print(a + (i == n ? "" : " "));

            long next = a + b;
            a = b;
            b = next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of terms (N): ");
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            printFibonacci(n);
        } else {
            System.out.println("Invalid input! Please enter an integer.");
        }

        sc.close();
    }
}
