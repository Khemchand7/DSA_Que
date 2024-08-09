//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    // Function to generate base primes up to sqrt(N) using the Sieve of Eratosthenes
    vector<bool> basePrimes(int n) {
        // Initialize a boolean vector `prime` to mark prime numbers
        vector<bool> prime(n + 1, true);
        // 0 and 1 are not prime numbers
        prime[0] = prime[1] = false;

        // Loop to mark non-prime numbers using Sieve of Eratosthenes
        for (int i = 2; i * i <= n; i++) {
            // If `i` is a prime number
            if (prime[i]) {
                // Mark all multiples of `i` as non-prime
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        // Return the boolean vector marking prime numbers
        return prime;
    }

    
    // Function to find all prime numbers in the range [M, N]
    vector<int> primeRange(int M, int N) {
        // Generate primes up to sqrt(N) for use in the segmented sieve
        vector<bool> sieve = basePrimes(sqrt(N));
        vector<int> basePrimesList;

        // Extracting the prime numbers from the boolean sieve
        for (int i = 2; i < sieve.size(); i++) {
            if (sieve[i]) {
                basePrimesList.push_back(i);
            }
        }
        
        // Initialize a boolean vector for the segmented sieve to mark primes in [M, N]
        vector<bool> segSieve(N - M + 1, true);
        // Special case: if M is 1, mark 1 as non-prime
        if (M == 1) {
            segSieve[0] = false;
        }
        
        // Mark non-prime numbers in the range [M, N] using the base primes
        for (auto prime : basePrimesList) {
            // Find the first multiple of the base prime greater than or equal to M
            int first_mul = (M / prime) * prime;
            if (first_mul < M) {
                first_mul += prime;
            }
            // Ensure that the marking starts from prime's square if necessary
            int j = max(first_mul, prime * prime);
            while (j <= N) {
                // Mark this number as non-prime
                segSieve[j - M] = false;
                // Move to the next multiple of the prime
                j += prime;
            }
        }
        
        // Collect all the prime numbers from the segmented sieve
        vector<int> primes;
        for (int i = 0; i < segSieve.size(); i++) {
            if (segSieve[i]) {
                primes.push_back(M + i);
            }
        }
        // Return the list of primes in the range [M, N]
        return primes;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends