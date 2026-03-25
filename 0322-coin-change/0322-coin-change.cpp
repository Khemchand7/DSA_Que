class Solution {
public:
    int solveRec(vector<int>& coins, int amount) {

        if (amount == 0) {
            return 0;
        }

        int n = coins.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (coins[i] <= amount) {
                int recAns = solveRec(coins, amount - coins[i]);
                if (recAns != INT_MAX) {
                    ans = min(ans, 1 + recAns);
                }
            }
        }

        return ans;
    }

    int solveDP(vector<int>& coins, int amount, vector<int> dp) {

        if (amount == 0) {
            return 0;
        }

        int n = coins.size();
        int ans = INT_MAX;

        if (dp[amount] != -1) {
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
        dp[amount] = ans;
        return ans;
    }

    int solveTabulation(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int ans = INT_MAX;
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    int recAns = dp[i - coins[j]];
                    if (recAns != INT_MAX) {
                        ans = min(ans, 1 + recAns);
                    }
                }
            }
            dp[i] = ans;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> dp(n + 1, -1);

        // int ans = solveRec(coins, n);
        // int ans = solveDP(coins, n, dp);
        int ans = solveTabulation(coins, n);
        return ans == INT_MAX ? -1 : ans;
    }
};