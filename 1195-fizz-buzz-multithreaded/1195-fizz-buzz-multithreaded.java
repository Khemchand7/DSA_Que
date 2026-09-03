class FizzBuzz {
    private int n;

    // Fizz thread starts with NO permission
    Semaphore fizzSem = new Semaphore(0);

    // Buzz thread starts with NO permission
    Semaphore buzzSem = new Semaphore(0);

    // FizzBuzz thread starts with NO permission
    Semaphore fizzbuzzSem = new Semaphore(0);

    // Number thread starts with permission
    // It acts as the controller/dispatcher
    Semaphore numberSem = new Semaphore(1);

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {

        // Fizz is needed for multiples of 3
        for (int i = 3; i <= n; i += 3) {

            // 15 belongs to fizzbuzz, not fizz
            if (i % 15 == 0)
                continue;

            // Wait until number() gives fizz permission
            fizzSem.acquire();

            // Print "fizz"
            printFizz.run();

            // Tell number() that fizz is finished
            numberSem.release();
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {

        // Buzz is needed for multiples of 5
        for (int i = 5; i <= n; i += 5) {

            // 15 belongs to fizzbuzz, not buzz
            if (i % 15 == 0)
                continue;

            // Wait until number() gives buzz permission
            buzzSem.acquire();

            // Print "buzz"
            printBuzz.run();

            // Tell number() that buzz is finished
            numberSem.release();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {

        // FizzBuzz is needed for multiples of 15
        for (int i = 15; i <= n; i += 15) {

            // Wait until number() gives fizzbuzz permission
            fizzbuzzSem.acquire();

            // Print "fizzbuzz"
            printFizzBuzz.run();

            // Tell number() that fizzbuzz is finished
            numberSem.release();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {

        // Check every number from 1 to n
        for (int i = 1; i <= n; i++) {

            // Wait until the previous thread gives number permission
            numberSem.acquire();

            // Multiple of both 3 and 5
            if (i % 15 == 0) {

                // Give permission to fizzbuzz thread
                fizzbuzzSem.release();

            // Multiple of 3 only
            } else if (i % 3 == 0) {

                // Give permission to fizz thread
                fizzSem.release();

            // Multiple of 5 only
            } else if (i % 5 == 0) {

                // Give permission to buzz thread
                buzzSem.release();

            // Not divisible by 3 or 5
            } else {

                // Number thread prints the number itself
                printNumber.accept(i);

                // Continue to the next number
                numberSem.release();
            }
        }
    }
}

/* 
number()
   │
   │ decides who should print
   ↓
┌──────────┬──────────┬────────────┐
│ fizz     │ buzz     │ fizzbuzz   │
│ release  │ release  │ release    │
└──────────┴──────────┴────────────┘
       │
       ↓
other thread acquires permission
       │
       ↓
prints
       │
       ↓
numberSem.release()
       │
       ↓
number() continues
 */