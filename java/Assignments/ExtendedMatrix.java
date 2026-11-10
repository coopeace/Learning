import java.util.Scanner;

class ExtendedMatrix extends Matrix{
  public int diagonal,upper,lower;

  public ExtendedMatrix(int r,int c){
    super(r, c);
  }

  public ExtendedMatrix(Scanner scanner){
    super(scanner);
  }

  public void calculatePartitionSums(){
    if (this.r != this.c){
      System.out.println("Error: Partition sums are only defined for square matrices");
      return;
    }

    this.diagonal = 0;
    this.lower = 0;
    this.upper = 0;

    for (int i=0;i<this.r;i++){
      this.diagonal += this.data[i][i];
      for (int j=0;j<this.c;j++){
        if (i<j){
          this.upper += this.data[i][j]; 
        } else if (i>j) {
          this.lower += this.data[i][j];
        }
      }
    }
    System.out.println("Diagonal Elements Sum:"+this.diagonal);
    System.out.println("Upper Triangle Sum:"+this.upper);
    System.out.println("Lower Triangle Sum:"+this.lower);
  }

  public Matrix transpose(){
    Matrix result = new Matrix(this.c, this.r);
    for (int i=0;i<this.r;i++){
      for (int j=0;j<this.c;j++){
        result.data[j][i]=this.data[i][j];
      }
    }
    return result;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ExtendedMatrix A = new ExtendedMatrix(scanner);
    A.calculatePartitionSums();
    Matrix B = A.transpose();
    System.out.println("Transpose of the Matrix:");
    B.display();
    scanner.close();
  }
} 


