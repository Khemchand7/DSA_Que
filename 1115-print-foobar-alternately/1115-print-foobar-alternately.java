class FooBar {

    private int n;

    // fooSemaphore starts with 1 permit.
    //
    // This means foo() is allowed to run first.
    private Semaphore fooSemaphore = new Semaphore(1);

    // barSemaphore starts with 0 permits.
    //
    // This means bar() must WAIT initially.
    // It can run only after foo() calls barSemaphore.release().
    private Semaphore barSemaphore = new Semaphore(0);


    public FooBar(int n) {
        this.n = n;
    }


    public void foo(Runnable printFoo) throws InterruptedException {

        // We need to print "foo" n times.
        for (int i = 0; i < n; i++) {

            // Take permission from fooSemaphore.
            //
            // Initially fooSemaphore = 1, so foo() can continue.
            //
            // After acquire():
            // fooSemaphore = 0
            //
            // So foo() cannot print "foo" again until bar()
            // gives the permission back.
            fooSemaphore.acquire();

            // Print "foo".
            printFoo.run();

            // Give permission to bar().
            //
            // barSemaphore becomes 1, so bar() can continue.
            barSemaphore.release();
        }
    }


    public void bar(Runnable printBar) throws InterruptedException {

        // We need to print "bar" n times.
        for (int i = 0; i < n; i++) {

            // Take permission from barSemaphore.
            //
            // Initially barSemaphore = 0, so bar() BLOCKS here.
            //
            // It will continue only after foo() calls:
            // barSemaphore.release()
            barSemaphore.acquire();

            // Now foo() has already printed "foo",
            // so we can print "bar".
            printBar.run();

            // Give permission back to foo().
            //
            // fooSemaphore becomes 1, allowing foo() to
            // print the next "foo".
            fooSemaphore.release();
        }
    }
}