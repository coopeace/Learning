
public class Add{
    public static void main(String[] args){
      if (args.length!=2){
        System.out.println("Usage : java Add num1 num2");
        System.exit(0);
        // return;
      }
        int sum = Integer.parseInt(args[0]) + Integer.parseInt(args[1]);
        System.out.println("Sum is " + sum);
    }
}
