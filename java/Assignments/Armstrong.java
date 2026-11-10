import java.util.Scanner;

public class Armstrong {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        
        int n = 0;
        
        // Count number of digits
        int temp = num;
        while (temp != 0) {
            temp /= 10;
            n++;
        }
        
        temp = num;
        int sum = 0;
        
        // Calculate the sum
        while (temp != 0) {
            int digit = temp % 10;
            sum += Math.pow(digit, n);
            temp /= 10;
        }
        
        if (sum == num) {
            System.out.println(num + " is an Armstrong number.");
        } else {
            System.out.println(num + " is NOT an Armstrong number.");
        }
        
        sc.close();
    }
}
