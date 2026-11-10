import java.util.Scanner;

class Conversion{
  public static void main(String[] args){
    int n;
    System.out.print("Enter a number:");
    Scanner in = new Scanner(System.in);
    n = in.nextInt();
    System.out.println("binary is "+Integer.toString(n,2));
    System.out.println("octal is "+Integer.toString(n,8));
    System.out.println("hexadecimal is "+Integer.toString(n,16).toUpperCase());
    in.close();
  }
}
