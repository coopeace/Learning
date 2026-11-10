import java.util.Scanner;

class Run{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ExtendedMatrix A = new ExtendedMatrix(scanner);
    A.calculatePartitionSums();
    System.out.println("diagonal:"+A.diagonal);
    System.out.println("upper:"+A.upper);
    System.out.println("lower:"+A.lower);
    Matrix B = A.transpose();
    B.display();
    scanner.close();
  }
}
