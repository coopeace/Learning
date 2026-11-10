import java.util.Scanner;

class Palindrome{
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

    if (n==rev){
      System.out.println(n + " is a palindrome.");
    }
    else{
      System.out.println(n + " is not a palindrome.");
    }
    in.close();
  }
}

// Output

// javac Palindrome.java 
//
// java -cp . Palindrome
// Enter a integer : 23
// 23 is not a palindrome.
//
// java -cp . Palindrome
// Enter a integer : 999
// 999 is a palindrome.
