class WorkerThread extends Thread {
    public WorkerThread(String name) {
        super(name);
    }

    @Override
    public void run() {
        for (int i = 1; i <= 3; i++) {
            System.out.println(getName() + " running step " + i);
            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

public class MultithreadingThreadClass {
    public static void main(String[] args) {
        WorkerThread thread1 = new WorkerThread("Thread-1");
        WorkerThread thread2 = new WorkerThread("Thread-2");

        // Always call start(), not run()
        thread1.start();
        thread2.start();
    }
}
