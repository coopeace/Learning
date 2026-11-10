import shapes.*;

class ShapeDemo{
  public static void main(String[] args) {
    Shape rec = new Rectangle(19,23);
    Shape cir = new Circle(5); 
    System.out.println("Perimeter of the Rectangle : " + rec.perimeter());
    System.out.println("Area of the Rectangle : " + rec.area());
    System.out.println("Circumference of the Circle : " + cir.perimeter());
    System.out.println("Area of the Circle : " + cir.area());
  }
}
