import java.util.Scanner;

class PrimeNumber{
  public static void main(String[] args) {
    int n;
    Scanner in = new Scanner(System.in);

    System.out.print("Enter a number : ");
    n = in.nextInt();
    
    for ( int i = 2 ; i < n/2 ; i++ ) {
      if ( n%i==0 ) {
        System.out.println(n + " is not a prime number");
        System.exit(0);
      }
    }
    System.out.println(n + " is a prime number");
    in.close();
  }
}

// Output

// javac PrimeNumber.java 
//
// java -cp . PrimeNumber
// Enter a number : 17
// 17 is a prime number

// java -cp . PrimeNumber
// Enter a number : 23
// 23 is a prime number

// java -cp . PrimeNumber
// Enter a number : 68
// 68 is not a prime number
