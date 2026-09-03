class ZeroEvenOdd {
    private int n;

    // ZERO starts with 1 permit, so zero thread can run first.
    Semaphore zeroSem = new Semaphore(1);

    // Odd and Even threads must wait initially.
    Semaphore oddSem = new Semaphore(0);
    Semaphore evenSem = new Semaphore(0);

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {

        // ZERO needs to be printed n times.
        for (int i = 1; i <= n; i++) {

            // Wait until the number thread finishes
            // and gives permission back to ZERO.
            zeroSem.acquire();

            // Print 0.
            printNumber.accept(0);

            // If i is odd, give permission to the ODD thread.
            if ((i & 1) == 1)
                oddSem.release();

            // If i is even, give permission to the EVEN thread.
            else
                evenSem.release();
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {

        // Even thread prints: 2, 4, 6, ...
        for (int i = 2; i <= n; i += 2) {

            // Wait until ZERO gives permission.
            evenSem.acquire();

            // Print the even number.
            printNumber.accept(i);

            // Give permission back to ZERO.
            zeroSem.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {

        // Odd thread prints: 1, 3, 5, ...
        for (int i = 1; i <= n; i += 2) {

            // Wait until ZERO gives permission.
            oddSem.acquire();

            // Print the odd number.
            printNumber.accept(i);

            // Give permission back to ZERO.
            zeroSem.release();
        }
    }
}
