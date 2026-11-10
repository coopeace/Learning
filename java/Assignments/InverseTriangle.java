import java.util.Scanner;

class InverseTriangle{
  public static void main(String[] args) {
    int n;
    Scanner in = new Scanner(System.in);

    System.out.print("Enter a number : ");
    n = in.nextInt();
    
    for ( int i = n ; i > 0 ; i-- ) {
      for ( int j = 1 ; j <= i ; j++ ) {
        System.out.print(i+" ");
      }
      System.out.println("");
    }
    in.close();
  }
}

// Output

// javac InverseTriangle.java 
//
// java -cp . InverseTriangle
// Enter a number : 4
// 4 4 4 4 
// 3 3 3 
// 2 2 
// 1 
//
// java -cp . InverssTriangle
// Enter a number : 5
// 5 5 5 5 5 
// 4 4 4 4 
// 3 3 3 
// 2 2 
// 1 
