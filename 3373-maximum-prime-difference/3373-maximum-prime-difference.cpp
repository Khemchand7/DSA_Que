class Solution {
public:
    // Helper function to check if a number is prime
    bool checkPrime(int n) {
        if (n <= 1) return false;           // Numbers <= 1 are not prime
        if (n == 2) return true;            // 2 is the only even prime number
        for (int i = 2; i * i <= n; i++) {  // Check for factors up to sqrt(n)
            if (n % i == 0) return false;   // n is not prime if divisible by any i
        }
        return true;                        // n is prime
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int firstPrimeIndex = -1;           // Index of the first prime found
        int lastPrimeIndex = -1;            // Index of the last prime found
        int maxLength = -1;

        for (int i = 0; i < n; i++) {
            if (checkPrime(nums[i])) {      // Check if current number is prime
                if (firstPrimeIndex == -1)  // Set the first prime index if not set
                    firstPrimeIndex = i;
                lastPrimeIndex = i;         // Update the last prime index
            }
        }

        maxLength = lastPrimeIndex - firstPrimeIndex;  // Calculate maximum difference
        return maxLength;                   
    }
};
