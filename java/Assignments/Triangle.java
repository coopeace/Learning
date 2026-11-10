import java.util.Scanner;

class Triangle{
  public static void main(String[] args) {
    int n;
    Scanner in = new Scanner(System.in);

    System.out.print("Enter a number : ");
    n = in.nextInt();
    
    for ( int i = 1 ; i <= n ; i++ ) {
      for ( int j = 1 ; j <= i ; j++ ) {
        System.out.print(i+" ");
      }
      System.out.println("");
    }
    in.close();
  }
}

// Output

// javac Triangle.java 
//
// java -cp . Triangle
// Enter a number : 4
// 1 
// 2 2 
// 3 3 3 
// 4 4 4 4 
//
// java -cp . Triangle
// Enter a number : 5
// 1 
// 2 2 
// 3 3 3 
// 4 4 4 4 
// 5 5 5 5 5 
