class Solution {
public:
    int solveRec(int start, int end) {
        if (start >= end)
            return 0;
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans =
                min(ans, i + max(solveRec(start, i - 1), solveRec(i + 1, end)));
        }
        return ans;
    }

    int solveMem(int start, int end, vector<vector<int>>& dp) {
        if (start >= end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans, i + max(solveMem(start, i - 1, dp),
                                   solveMem(i + 1, end, dp)));
        }

        dp[start][end] = ans;
        return dp[start][end];
    }

    int solveTab(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int start = n; start >= 1; start--) {
            for (int end = 1; end <= n; end++) {
                if(start >= end) continue;
                int ans = INT_MAX;
                for (int i = start; i <= end; i++) {
                    ans = min(ans, i + max(solveMem(start, i - 1, dp),
                                           solveMem(i + 1, end, dp)));
                }

                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        // int ans = solveRec(1, n);
        /* vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = solveMem(1, n, dp); */
        int ans = solveTab(n); 

        return ans;
    }
};