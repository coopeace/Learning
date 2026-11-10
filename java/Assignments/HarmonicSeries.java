import java.util.Scanner;

class HarmonicSeries{
  public static void main(String[] args) {
    int n,m;
    float sum=0;
    Scanner in = new Scanner(System.in);

    System.out.print("Enter a integer : ");
    n = in.nextInt();
    m=n;
    for ( int i = 1 ; i <= m ; i++ ) {
      System.out.print("1/"+i+" ");
      if (i!=m) {
        System.out.print("+ ");
      }
      sum += 1 / (float) i;
      }
    System.out.println("= "+sum);
    in.close();
  }
}

// Output

// javac HarmonicSeries.java 
//
// java -cp . HarmonicSeries
// Enter a number : 5
// 1/1 + 1/2 + 1/3 + 1/4 + 1/5 = 2.2833335

