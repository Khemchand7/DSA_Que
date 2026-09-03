class Foo {

    // Represents which method is allowed to execute next.
    // 1 -> first()
    // 2 -> second()
    // 3 -> third()
    private int state = 1;

    public Foo() {

    }

    // synchronized means only ONE thread can execute this method
    // at a time on the same Foo object.
    //
    // It also allows us to safely use wait() and notifyAll()
    // because both require the thread to own the object's lock.
    public synchronized void first(Runnable printFirst) throws InterruptedException {

        // Since state starts at 1, first() is the first method
        // that is supposed to execute.
        //
        // printFirst.run() outputs "first".
        printFirst.run();

        // first() has completed.
        // Change state to 2 so that second() can proceed.
        state = 2;

        // Wake up threads that may be waiting on this Foo object's lock.
        // In particular, this can wake up the thread executing second().
        notifyAll();
    }

    public synchronized void second(Runnable printSecond) throws InterruptedException {

        // If first() has not completed yet (state != 2),
        // second() must wait.
        //
        // wait() does TWO important things:
        // 1. Releases the Foo object's lock.
        // 2. Puts this thread into the WAITING state.
        //
        // This allows first() to acquire the lock and execute.
        while (state != 2) {
            wait();
        }

        // At this point state == 2, meaning first() has completed.
        // Now it is safe to print "second".
        //
        // printSecond.run() outputs "second".
        printSecond.run();

        // second() has completed.
        // Change state to 3 so that third() can proceed.
        state = 3;

        // Wake up any thread waiting for state == 3.
        notifyAll();
    }

    public synchronized void third(Runnable printThird) throws InterruptedException {

        // If second() has not completed yet (state != 3),
        // third() must wait.
        //
        // wait() releases the lock, allowing second() to execute.
        while (state != 3) {
            wait();
        }

        // At this point:
        // state == 3
        // first() has completed
        // second() has completed
        //
        // Therefore it is safe to print "third".
        //
        // printThird.run() outputs "third".
        printThird.run();
    }
}