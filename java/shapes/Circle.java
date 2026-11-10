package shapes;

public class Circle extends Shape{
  private final float pi = 3.14F;
  private final float radius;

  public Circle(int radius){
    this.radius = radius;
  }
  
  @Override
  public float perimeter(){
    return 2*pi*this.radius;
  }
  
  @Override
  public float area(){
    return pi*this.radius*this.radius;
  }
  
  // Called inside StaticDemo
  public static void greetings(){
    System.out.println("Hello, This is Circle.");
  }
}
