class Solution {
public:
    int solveRec(int A) {

        if (A == 0)
            return 0; // Base case: 0 requires 0 squares

        int count = A; // Worst case: 1^2 + 1^2 + ... (A times)

        for (int i = 1; i * i <= A; i++) { // Try every square <= A

            // Choose square (i*i) and solve remaining value
            count = min(count, 1 + solveRec(A - i * i));
        }

        return count; // Minimum squares required
    }

    int solveDP(int A, vector<int>& dp) {

        if (A == 0)
            return 0; // Base case

        if (dp[A] != -1)
            return dp[A]; // Return already computed result

        int count = A; // Worst case initialization

        for (int i = 1; i * i <= A; i++) {

            // Try taking square i*i and recursively solve remaining part
            count = min(count, 1 + solveDP(A - i * i, dp));
        }

        dp[A] = count; // Store result in DP array
        return dp[A];
    }

    int solveTab(int A) {

        vector<int> dp(A + 1,
                       0); // dp[i] = minimum squares required to form sum i

        for (int i = 1; i <= A; i++) {

            int count = i; // worst case: i = 1² + 1² + ... (i times)

            for (int j = 1; j * j <= i; j++) { // try every square number ≤ i

                // take square (j*j) and check remaining value (i - j*j)
                count = min(count, 1 + dp[i - j * j]);
            }

            dp[i] = count; // store minimum squares required for i
        }

        return dp[A]; // answer for A
    }

    int numSquares(int A) {
         //return solveRec(A);          // Pure recursion (very slow:

        vector<int> dp(A+1, -1);        // DP array for memoization
        return solveDP(A, dp);          // Top-down DP

        /* return solveTab(A); */
    }
};