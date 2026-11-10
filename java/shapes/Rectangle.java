package shapes;

public class Rectangle extends Shape{
  private final int length;
  private final int width;

  public Rectangle (int length,int width){
    this.length = length;
    this.width = width;
  }

  public Rectangle (int length){
    this(length,10);
  }
  
  @Override
  public float perimeter(){
    return 2*(this.length+this.width);
  }

  @Override
  public float area(){
    return this.length*this.width;
  }
}
