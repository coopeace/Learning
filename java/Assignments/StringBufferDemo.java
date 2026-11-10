public class StringBufferDemo {
    public static void main(String[] args) {
        // 1. Initializing StringBuffer
        StringBuffer sb = new StringBuffer("Hello");
        System.out.println("Initial content: " + sb);

        // 2. append() - Adds to the end
        sb.append(" World");
        System.out.println("After append: " + sb); // Hello World

        // 3. insert() - Inserts text at index 5
        sb.insert(5, ", Beautiful");
        System.out.println("After insert: " + sb); // Hello, Beautiful World

        // 4. replace() - Replaces characters from index 7 to 16
        // Replaces "Beautiful" with "Java"
        sb.replace(7, 16, "Java");
        System.out.println("After replace: " + sb); // Hello, Java World

        // 5. delete() - Deletes characters from index 5 to 7 (removes ", ")
        sb.delete(5, 7);
        System.out.println("After delete: " + sb); // HelloJava World

        // 6. deleteCharAt() - Deletes character at index 9 (removes the space)
        sb.deleteCharAt(9);
        System.out.println("After deleteCharAt: " + sb); // HelloJavaWorld

        // 7. charAt() and setCharAt()
        System.out.println("Character at index 0: " + sb.charAt(0)); // H
        sb.setCharAt(0, 'h');
        System.out.println("After setCharAt: " + sb); // helloJavaWorld

        // 8. reverse() - Reverses the sequence
        sb.reverse();
        System.out.println("After reverse: " + sb); // dlroWavaJolleh

        // Reverse back to normal for subsequent tests
        sb.reverse();

        // 9. length() vs capacity()
        System.out.println("Current length: " + sb.length());
        System.out.println("Current capacity: " + sb.capacity());

        // 10. ensureCapacity()
        // If the new capacity needed is greater than current capacity,
        // it grows using the rule: (old_capacity * 2) + 2
        sb.ensureCapacity(50);
        System.out.println("Capacity after ensureCapacity(50): " + sb.capacity());
    }
}

// Output
//
// Initial content: Hello
// After append: Hello World
// After insert: Hello, Beautiful World
// After replace: Hello, Java World
// After delete: HelloJava World
// After deleteCharAt: HelloJavaWorld
// Character at index 0: H
// After setCharAt: helloJavaWorld
// After reverse: dlroWavaJolleh
// Current length: 14
// Current capacity: 21
// Capacity after ensureCapacity(50): 50
