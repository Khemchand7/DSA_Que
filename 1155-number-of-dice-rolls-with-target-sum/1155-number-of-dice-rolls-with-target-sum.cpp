class Solution {
public:

    // Pure recursion
    int solveRec(int n, int k, int target) {

        // invalid state: negative dice or negative target
        if (n < 0 || target < 0) {
            return 0;
        }

        // base case: exact dice used and exact target formed
        if (n == 0 && target == 0) {
            return 1;
        }

        int ans = 0;

        // try every face value from 1 → k
        for (int i = 1; i <= k; i++) {
            ans += solveRec(n - 1, k, target - i);
        }

        return ans;
    }

    // Memoization (Top-Down DP)
    int solveMem(int n, int k, int target, vector<vector<int>>& dp) {

        const int MOD = 1e9 + 7;

        // invalid state
        if (n < 0 || target < 0) {
            return 0;
        }

        // base case
        if (n == 0 && target == 0) {
            return 1;
        }

        // step1: check if answer already exists
        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        int ans = 0;

        // step2: solve one case and rest using recursion
        for (int i = 1; i <= k; i++) {
            ans = (ans + solveMem(n - 1, k, target - i, dp)) % MOD;
        }

        // step3: store answer in dp
        dp[n][target] = ans;

        return ans;
    }

    // Tabulation (Bottom-Up DP)
    int solveTabulation(int n, int k, int target) {

        const int MOD = 1e9 + 7;

        // step1: create dp array
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // step2: base case initialization
        dp[0][0] = 1;   // 0 dice → make sum 0 in 1 way

        // step3: reverse the recursion flow using loops
        for (int dice = 1; dice <= n; dice++) {

            for (int tgt = 1; tgt <= target; tgt++) {

                int ans = 0;

                // try all face values
                for (int i = 1; i <= k; i++) {

                    // ensure target doesn't go negative
                    if(tgt - i >= 0) 
                        ans = (ans + dp[dice - 1][tgt - i]) % MOD;
                }

                // store result for current state
                dp[dice][tgt] = ans;
            }
        }

        // final answer: using n dice to make target
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {

        // recursion
        // int ans = solveRec(n, k, target);

        // memoization
        /* vector<vector<int> > dp(n + 1, vector<int>(target + 1,-1));
        int ans = solveMem(n, k, target, dp); */

        // tabulation
        int ans = solveTabulation(n,k, target);

        return ans;
    }
};