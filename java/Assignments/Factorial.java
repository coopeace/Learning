import java.util.Scanner;

class Factorial {
  public static void main(String[] args) {
    int num;
    long factorial = 1;
    Scanner in = new Scanner(System.in);

    do {
      System.out.print("Enter a positive integer : ");
      num = in.nextInt();
    } while (num < 0);

    for (int i = 2; i <= num; i++) {
      factorial *= i;
    }

    System.out.println("Factorial of " + num + " is " + factorial);

    in.close();
  }
}

// Output

// javac Factorial.java
//
// java -cp . Factorial
// Enter a positive integer : 1
// Factorial of 1 is 1
//
// java -cp . Factorial
// Enter a positive integer : 5
// Factorial of 5 is 120
