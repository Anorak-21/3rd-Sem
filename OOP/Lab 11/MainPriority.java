class MainPriority implements Runnable {
    public void run() {
        try {
            // code that may throw InterruptedException
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted");
        }
    }

    public static void main(String[] args) {
        MainPriority mt = new MainPriority();
        Thread t = new Thread(mt);
        t.setPriority(8);
        t.start();
        t.interrupt();
    }
}