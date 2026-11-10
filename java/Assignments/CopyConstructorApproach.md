# Beginner's Guide: The Copy Constructor (Adapter) Approach

---

## 1. What was the original problem?

In `Matrix.java`, you had a static method:
```java
public static Matrix insertion(Scanner scanner) { ... }
```
When you called:
```java
ExtendedMatrix A = ExtendedMatrix.insertion(scanner);
```
Java saw that `ExtendedMatrix` didn't have its own `insertion` method, so it called `Matrix.insertion(...)`.

However:
1. `Matrix.insertion(...)` returns a **`Matrix`** object (`new Matrix(...)`).
2. `A` is of type **`ExtendedMatrix`**.
3. In Java, **a parent cannot automatically be assigned to a child**. Even though every `ExtendedMatrix` is a `Matrix`, **not every `Matrix` is an `ExtendedMatrix`**!
4. Even if you forced it with a cast `(ExtendedMatrix) ...`, it would crash at runtime (`ClassCastException`) because the object created in memory is actually just a plain `Matrix`.

---

## 2. What is the Copy Constructor / Conversion Approach?

Imagine someone hands you a standard plain cake (`Matrix`). You want a birthday cake with candles and frosting (`ExtendedMatrix`). 

Instead of baking a whole new cake from scratch, you take the plain cake and **wrap** it inside your birthday cake box, adding the candles and decorations on top!

In Java, a **copy constructor** (or conversion constructor) is a constructor that takes an existing object and uses its data to initialize the new object:

```java
// Inside ExtendedMatrix.java
public ExtendedMatrix(Matrix m) {
    super(m.r, m.c);      // 1. Tell parent Matrix the row and col size
    this.data = m.data;   // 2. Share/copy the 2D array data
}
```

---

## 3. How to implement it step-by-step

### Step 1: Keep `Matrix.java` completely untouched
You don't need to change a single line in `Matrix.java`!
It can keep its original static method:
```java
public static Matrix insertion(Scanner scanner) {
    System.out.print("Enter number of rows and cols:");
    int r = scanner.nextInt();
    int c = scanner.nextInt();
    Matrix m = new Matrix(r, c);

    System.out.println("Enter elements->");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m.data[i][j] = scanner.nextInt();
        }
    }
    return m;
}
```

---

### Step 2: Add the conversion constructor to `ExtendedMatrix.java`
```java
class ExtendedMatrix extends Matrix {
    public int diagonal, upper, lower;

    // Normal constructor
    public ExtendedMatrix(int r, int c) {
        super(r, c);
    }

    // Conversion / Copy Constructor:
    // Takes any existing Matrix and turns it into an ExtendedMatrix
    public ExtendedMatrix(Matrix m) {
        super(m.r, m.c);
        this.data = m.data;
    }

    // (Optional) If you still want to call ExtendedMatrix.insertion(scanner):
    public static ExtendedMatrix insertion(Scanner scanner) {
        // First get a regular Matrix from Matrix.insertion:
        Matrix plainMatrix = Matrix.insertion(scanner);
        // Then convert it into an ExtendedMatrix using our constructor:
        return new ExtendedMatrix(plainMatrix);
    }

    // ... rest of your methods (calculatePartitionSums, transpose, etc.)
}
```

---

### Step 3: Use it in `Run.java`

You now have two ways to use it in `Run.java`:

#### Way A: Directly wrap `Matrix.insertion`
```java
Scanner scanner = new Scanner(System.in);
ExtendedMatrix A = new ExtendedMatrix(Matrix.insertion(scanner));
```

#### Way B: Call `ExtendedMatrix.insertion`
```java
Scanner scanner = new Scanner(System.in);
ExtendedMatrix A = ExtendedMatrix.insertion(scanner);
```

Both work seamlessly and compile with zero errors!

---

## 4. An Important Detail: Shallow Copy vs. Deep Copy

In the constructor:
```java
this.data = m.data;
```
This is a **shallow copy**. Both `m` and the new `ExtendedMatrix` point to the **same 2D array in memory**. For reading input right after creation, this is completely fine and very fast.

If you ever need the new matrix to have its own independent copy of the numbers (so changing one doesn't affect the other), you do a **deep copy**:
```java
public ExtendedMatrix(Matrix m) {
    super(m.r, m.c);
    this.data = new int[m.r][m.c];
    for (int i = 0; i < m.r; i++) {
        for (int j = 0; j < m.c; j++) {
            this.data[i][j] = m.data[i][j];
        }
    }
}
```

---

## 5. When should you use this approach?

| Situation | Best Approach | Why? |
| :--- | :--- | :--- |
| **You CAN modify `Matrix.java`** | **Approach 1 (Constructor with `Scanner`)** | Cleaner OOP design. No extra temporary objects created. Subclasses just call `super(scanner)`. |
| **You CANNOT modify `Matrix.java`** (e.g. provided by teacher or 3rd-party library) | **Approach 2 (Copy / Conversion Constructor)** | Reuses `Matrix.insertion` without touching `Matrix.java`. Works as an adapter. |

---

## Quick Summary

- **Static methods do not support `@Override`** because they belong to the class, not individual objects.
- A **Copy / Conversion Constructor** lets you turn an existing instance of a parent class into a child class by adopting its data.
