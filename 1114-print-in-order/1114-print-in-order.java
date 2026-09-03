class Foo {

    // Semaphore used to control when second() can execute.
    //
    // Initial value = 0
    // So initially, second() is NOT allowed to proceed.
    //
    // first() will call second.release(), which increases
    // the permit count to 1 and allows second() to continue.
    private Semaphore second = new Semaphore(0);

    // Semaphore used to control when third() can execute.
    //
    // Initial value = 0
    // So initially, third() is NOT allowed to proceed.
    //
    // second() will call third.release(), which allows
    // third() to continue.
    private Semaphore third = new Semaphore(0);


    public Foo() {

    }


    public void first(Runnable printFirst) throws InterruptedException {

        // first() does not need to wait for anyone.
        // It is the first method in the required sequence.
        //
        // printFirst.run() outputs "first".
        printFirst.run();

        // first() has finished printing "first".
        //
        // release() adds ONE permit to the 'second' semaphore.
        //
        // This gives permission to second() to continue.
        second.release();
    }


    public void second(Runnable printSecond) throws InterruptedException {

        // acquire() tries to take ONE permit from 'second'.
        //
        // Initially:
        // second = 0 permits
        //
        // Therefore, if second() runs before first(),
        // it will BLOCK here.
        //
        // After first() calls second.release():
        // second = 1 permit
        //
        // acquire() takes that permit:
        // second = 0
        //
        // Now second() is allowed to continue.
        second.acquire();


        // At this point we know that first() has already completed.
        //
        // printSecond.run() outputs "second".
        printSecond.run();


        // second() has finished printing "second".
        //
        // Give ONE permit to the 'third' semaphore.
        //
        // This gives permission to third() to continue.
        third.release();
    }


    public void third(Runnable printThird) throws InterruptedException {

        // acquire() tries to take ONE permit from 'third'.
        //
        // Initially:
        // third = 0 permits
        //
        // Therefore, third() will BLOCK here.
        //
        // Only after second() executes:
        //
        //     third.release();
        //
        // will this acquire() be able to continue.
        third.acquire();


        // At this point we know:
        // first() has completed
        // second() has completed
        //
        // So it is safe to print "third".
        //
        // printThird.run() outputs "third".
        printThird.run();
    }
}