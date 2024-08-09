class Solution {
public:

    vector<bool> basePrimes(int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

    vector<int> PrimeRange(int L, int R) {
        vector<bool> sieve = basePrimes(sqrt(R));
        vector<int> basePrimeList;
        for (int i = 2; i < sieve.size(); i++) {
            if (sieve[i]) {
                basePrimeList.push_back(i);
            }
        }

        vector<bool> segSieve(R - L + 1, true);
        if (L == 1) {
            segSieve[0] = false;
        }

        for (auto prime : basePrimeList) {
            int first_mul = (L / prime) * prime;
            if (first_mul < L) {
                first_mul += prime;
            }
            int j = max(first_mul, prime * prime);
            while (j <= R) {
                segSieve[j - L] = false;
                j += prime;
            }
        }

        vector<int> primesInGivenRange;
        for (int i = 0; i < segSieve.size(); i++) {
            if (segSieve[i]) {
                primesInGivenRange.push_back(i + L);
            }
        }
        return primesInGivenRange;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> prime = PrimeRange(left, right);
        if (prime.size() < 2) {
            return {-1, -1}; // Less than two primes in the range
        }
        
        int diff = INT_MAX;
        vector<int> ans(2,-1);

        // Iterate over the list of primes to find the closest pair
        for (int i = 0; i < prime.size() - 1; i++) {
            int diffPrime = prime[i + 1] - prime[i];
            if (diffPrime < diff) {
                diff = diffPrime;
                ans[0]=prime[i];
                ans[1]=prime[i+1];
            }
        }
        
        return ans;
    }
};
