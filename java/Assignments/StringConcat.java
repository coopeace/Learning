public class StringConcat {
    public static void main(String[] args) {
        String[] words = {"Java", "is", "fast", "and", "robust"};
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < words.length; i++) {
            sb.append(words[i]);

            if (i < words.length - 1) {
                sb.append(" ");
            }
        }

        String result = sb.toString();
        System.out.println("Result: " + result);
    }
}
