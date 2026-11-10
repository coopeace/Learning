class MaxNumber{
  public static void main(String[] args) {
    //int len = args.length;
    //int max = -10000;
    if ( args.length< 2 ) {
      System.out.println("Usage: java MaxNumber <n1> <n2>");
      System.exit(0);
    }
    /*for ( int i = 0; i < len ; i++ ) {
      int n = Integer.parseInt(args[i]);
      if ( n > max ){
        max = n;
      }
    }*/
    int n1 = Integer.parseInt(args[0]);
    int n2 = Integer.parseInt(args[1]);
    int max =  (n1 > n2) ? n1 : n2;
    System.out.println("Max value is " + max);
  }
}

// Output :

// javac MaxNumber.java 

// java -cp . MaxNumber 56 
// Usage: java MaxNumber <num1> <num2> ........

// java -cp . MaxNumber 56 78 90 101
// Max value is 101
