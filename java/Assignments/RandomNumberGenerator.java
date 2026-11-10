import java.util.Random;

class RandomNumberGenerator{
  public static void main(String[] args){
    Random rand = new Random();
    int num;
    for (int i=0;i<5;i++){
      // int num = (int) (Math.random()*100);
      num = rand.nextInt(100)+1;
      System.out.println(num);
    }
  }
}
