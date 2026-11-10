abstract class Animal {
  public abstract void eating();
  public abstract void sound();

  public void sleeping(){
    System.out.println("Zzzz....");
  }
}

interface Flyable{
  void flying();
}

abstract class Bird extends Animal implements Flyable{
  @Override
  public void flying() {
      System.out.println("Flapping wings and soaring in the sky.");
  }
}

class Crow extends Bird{
  @Override
  public void eating() {
      System.out.println("Crow is eating.Crunch crunch!!");
  }

  @Override
  public void sound() {
      System.out.println("Caw... Caw...");
  }

} 

public class Main{
  public static void main(String[] args) {
    Bird crow = new Crow();
    crow.flying();
    crow.sound();
    crow.eating();
    crow.sleeping();
  }
}
