import java.util.Scanner;

public class Matrix{
  public int r,c;
  public int[][] data;

  public Matrix(int r,int c){
    this.r=r;
    this.c=c;
    this.data=new int[r][c];
  }

  public Matrix(Scanner scanner){
    System.out.print("Enter number of rows and cols:");
    this.r = scanner.nextInt();
    this.c = scanner.nextInt();
    this.data = new int[this.r][this.c];

    System.out.println("Enter elements->");
    for (int i=0;i<this.r;i++){
      for (int j=0;j<this.c;j++){
        this.data[i][j]=scanner.nextInt();
      }
    }
  }

  // public static Matrix insertion(Scanner scanner){
  //   return new Matrix(scanner);
  // }

  public Matrix add(Matrix other){
    if (this.r!=other.r || this.c!=other.c){
      System.out.println("Error : Dimension mismatch");
      return null;
    }
    Matrix result = new Matrix(this.r, this.c);
    for (int i=0;i<result.r;i++){
      for (int j=0;j<result.c;j++){
        result.data[i][j] = this.data[i][j] + other.data[i][j];
      }
    }
    return result;
  }

  public void display(){
    for (int i=0;i<this.r;i++){
      for (int j=0;j<this.c;j++){
        System.out.print(" "+this.data[i][j]);
      }
      System.out.println();
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    Matrix A = new Matrix(scanner);
    Matrix B = new Matrix(scanner);
    Matrix C = A.add(B);
    if (C!=null) {
      System.out.println("(A + B) = ");
      C.display();
    }
    scanner.close();
  }
}
