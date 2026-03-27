class Solution {
public:
    int solveRec(int start, int end) {
        if (start >= end)
            return 0; // no cost when only one number or empty range

        int ans = INT_MAX;

        // try every number as the first guess
        for (int i = start; i <= end; i++) {

            // worst-case cost after choosing i
            ans = min(ans,
                      i + max(solveRec(start, i - 1),   // number is smaller
                              solveRec(i + 1, end)));   // number is larger
        }

        return ans;
    }

    int solveMem(int start, int end, vector<vector<int>>& dp) {
        if (start >= end)
            return 0; // base case

        if (dp[start][end] != -1)
            return dp[start][end]; // return stored result

        int ans = INT_MAX;

        for (int i = start; i <= end; i++) {

            // compute cost for choosing i
            ans = min(ans,
                      i + max(solveMem(start, i - 1, dp),
                              solveMem(i + 1, end, dp)));
        }

        dp[start][end] = ans; // store computed answer
        return dp[start][end];
    }

    int solveTab(int n) {

        // dp[start][end] = minimum money needed to guarantee win in range [start,end]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // fill table bottom-up (reverse order of recursion)
        for (int start = n; start >= 1; start--) {
            for (int end = 1; end <= n; end++) {

                if (start >= end)
                    continue; // base case already 0

                int ans = INT_MAX;

                // try every number as first guess
                for (int i = start; i <= end; i++) {

                    // worst case cost after choosing i
                    ans = min(ans,
                              i + max(dp[start][i - 1],  // left range
                                      dp[i + 1][end]));  // right range
                }

                dp[start][end] = ans; // store best cost for this range
            }
        }

        return dp[1][n]; // answer for range [1,n]
    }

    int getMoneyAmount(int n) {

        // recursion
        // int ans = solveRec(1, n);

        // memoization
        /* vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = solveMem(1, n, dp); */

        // tabulation
        int ans = solveTab(n);

        return ans;
    }
};