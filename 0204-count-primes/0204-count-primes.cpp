class Solution {
public:
//Sieve of Eratosthemes Algorithm
/*     int UnoptimizedcountPrimes(int n) {
        if (n == 0)
            return 0;
        vector<bool> prime(n, true);//n size ki vector create ki aur sabko prime mark kar dia 
        int ans = 0;
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                ++ans;//prime[2] is true so enters the loop ans will increase by 1;
                int j = 2 * i;// ab 2 ke jitne bhi multiple hai unko non prime mark karenge j=2*2=4
                while (j < n) {
                    prime[j] = false;//prime[4]==false
                    j += i;// loop ko chalane ke lie ab jitne bhi 2 ke multiple hai unhe false mark karenge j=j+i=4+2=6, and it will goes for 8,10,12,14 and so on . creating multiples of i by adding i ;
                }
            }
        }
        return ans;
    } */

    // Optimized Sieve of Eratosthenes Algorithm
    int countPrimes(int n) {
        if (n <= 2) // Since there are no prime numbers less than 2 as the que says it should be 
                    //strictly less the n;
            return 0;
        
        vector<bool> prime(n, true); // Initialize vector with 'true' to mark all numbers as prime
        prime[0] = prime[1] = false; // 0 and 1 are not prime numbers
        int ans = n - 2; // Start with all numbers marked as prime except 0 and 1 aisa islie lia kyuki loop me sirf jab hi enter kar rhe 
                         // jab multiles ko hata rhe hai to ++ans se correct result nhi aaega this logic will work better;
        
        for (int i = 2; i * i < n; i++) { // Optimization: i * i < n
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) { // Mark multiples of i as non-prime
                    if (prime[j]) { // Only decrement count for the first time we mark it non-prime
                        prime[j] = false;
                        --ans;//yahan pr multiples ko hata rhe hai ans me se 
                    }
                }
            }
        }
        
        return ans;
    }
};