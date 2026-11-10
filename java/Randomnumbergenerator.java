class Randomnumbergenerator {

    public static void main(String args[]) {
        for (int i = 1; i <= 5; i++) {
            System.out.println((int) (Math.random() * 100));
        }
    }
}

/* Output:
 * javac Randomnumbergenerator
 * java Randomnumbergenerator
 * 12
 * 33
 * 30
 * 97
 * 39
 */
