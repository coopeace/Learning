import java.util.Scanner;

public class Circle{
  public float r;
  public float pi = 3.14F;

  public Circle(float r){
    this.r=r;
  }

  public float get_circumference(){
    return 2*pi*this.r;
  }
  public float get_area(){
    return pi*this.r*this.r;
  }
}

class Main{
  public static void main(String[] args) {
    float r;
    Scanner in = new Scanner(System.in);
    System.out.print("Enter Circle Radius: ");
    r = in.nextFloat();
    Circle c1 = new Circle(r);
    System.out.println("Circumference of Circle of radius "+c1.r+" is "+ c1.get_circumference());
    System.out.println("Area of Circle of radius "+c1.r+" is "+ c1.get_area());
    in.close();
  }
}

// Output

// javac Circle.java 
//
// java -cp . Circle
// Enter Circle Radius: 5
// Circumference of Circle of radius 5.0 is 31.400002
// Area of Circle of radius 5.0 is 78.5
//
// java -cp . Circle
// Enter Circle Radius: 3
// Circumference of Circle of radius 3.0 is 18.84
// Area of Circle of radius 3.0 is 28.26
