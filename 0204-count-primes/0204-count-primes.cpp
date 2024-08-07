class Solution {
public:
//Sieve of Eratosthemes Algorithm
    int countPrimes(int n) {
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
    }
};