import java.util.Scanner;

class SumOfDigits{
  public static void main(String[] args) {
    int n,m,sum=0;
    Scanner in = new Scanner(System.in);

    System.out.print("Enter a integer : ");
    n = in.nextInt();
    
    m=n;
    while (m!=0){
      sum += m % 10;
      m /= 10 ;
    }

    System.out.println("Sum of " + n + " is " + sum);

    in.close();
  }
}

// Output

// javac SumOfDigits.java 
//
// java -cp . SumOfDigits
// Enter a integer : 35912
// Sum of 35912 is 20
//
// java -cp . SumOfDigits
// Enter a integer : 7893421
// Sum of 7893421 is 34
