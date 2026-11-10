import java.util.Scanner;

class Reverse{
  public static void main(String[] args) {
    int n,m,rev=0;
    Scanner in = new Scanner(System.in);

    System.out.print("Enter a integer : ");
    n = in.nextInt();
    
    m=n;
    while (m!=0){
      rev *= 10;
      rev += m % 10;
      m /= 10 ;
    }

    System.out.println("Reverse of " + n + " is " + rev);

    in.close();
  }
}

// Output

// javac Reverse.java 
//
// java -cp . Reverse
// Enter a positive integer : 23
// Reverse of 23 is 32
//
// java -cp . Reverse
// Enter a positive integer : 189345
// Reverse of 189345 is 543981 
