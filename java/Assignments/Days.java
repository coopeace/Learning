import java.util.Scanner;

class Days {
  public static void main(String[] args) {
    int months, days;
    Scanner in = new Scanner(System.in);
    System.out.print("Enter number of days:");
    days = in.nextInt();
    months = days / 30;
    days = days % 30;
    System.out.println("Months : " + months);
    System.out.println("Days : " + days);
    in.close();
  }
}

// javac Days.java
