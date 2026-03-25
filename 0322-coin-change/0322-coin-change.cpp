class Solution {
public:

    // Pure recursion
    int solveRec(vector<int>& coins, int amount) {

        if (amount == 0) {
            return 0; // base case: 0 coins needed to make amount 0
        }

        int n = coins.size();
        int ans = INT_MAX; // represents impossible state initially

        for (int i = 0; i < n; i++) {
            if (coins[i] <= amount) { // choose coin only if it does not exceed amount

                int recAns = solveRec(coins, amount - coins[i]); // solve smaller subproblem

                if (recAns != INT_MAX) { // avoid overflow from 1 + INT_MAX
                    ans = min(ans, 1 + recAns); // include current coin
                }
            }
        }

        return ans; // minimum coins required for this amount
    }

    // Memoization (Top-Down DP)
    int solveDP(vector<int>& coins, int amount, vector<int> &dp) {

        if (amount == 0) {
            return 0;
        }

        int n = coins.size();
        int ans = INT_MAX;

        if (dp[amount] != -1) { // return already computed result
            return dp[amount];
        }

        for (int i = 0; i < n; i++) {
            if (coins[i] <= amount) {

                int recAns = solveDP(coins, amount - coins[i], dp);

                if (recAns != INT_MAX) {
                    ans = min(ans, 1 + recAns);
                }
            }
        }

        dp[amount] = ans; // store result for reuse
        return ans;
    }

    // Bottom-Up DP (Tabulation)
    int solveTabulation(vector<int>& coins, int amount) {

        int n = amount;
        vector<int> dp(n + 1, INT_MAX); // dp[i] = minimum coins needed for amount i

        dp[0] = 0; // base case

        for (int i = 1; i <= n; i++) {

            int ans = INT_MAX;

            for (int j = 0; j < coins.size(); j++) {

                if (coins[j] <= i) {

                    int recAns = dp[i - coins[j]]; // previous subproblem

                    if (recAns != INT_MAX) {
                        ans = min(ans, 1 + recAns); // include coin j
                    }
                }
            }

            dp[i] = ans; // store best answer for amount i
        }

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = amount;
        vector<int> dp(n + 1, -1);

        // int ans = solveRec(coins, n);
        //int ans = solveDP(coins, n, dp);
        int ans = solveTabulation(coins, n);

        return ans == INT_MAX ? -1 : ans; // if impossible return -1
    }
};