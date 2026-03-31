class Solution {
public:

    // ---------------- RECURSION ----------------
    int solveRec(vector<int>& arr, vector<vector<int>>& maxi, int left, int right) {

        // base case: single leaf → no non-leaf node cost
        if (left == right)
            return 0;

        int ans = INT_MAX;

        // try every possible partition
        for (int i = left; i < right; i++) {

            int leftAns = solveRec(arr, maxi, left, i);       // cost of left subtree
            int rightAns = solveRec(arr, maxi, i + 1, right); // cost of right subtree

            int cost = maxi[left][i] * maxi[i + 1][right];    // cost of current node

            ans = min(ans, leftAns + rightAns + cost);        // choose minimum
        }

        return ans;
    }


    // ---------------- MEMOIZATION ----------------
    int solveMem(vector<int>& arr, vector<vector<int>>& maxi, int left,
                 int right, vector<vector<int>>& dp) {

        if (left == right)
            return 0;

        // step1: if answer already exists
        if (dp[left][right] != -1)
            return dp[left][right];

        int ans = INT_MAX;

        for (int i = left; i < right; i++) {

            int leftAns = solveMem(arr, maxi, left, i, dp);
            int rightAns = solveMem(arr, maxi, i + 1, right, dp);

            int cost = maxi[left][i] * maxi[i + 1][right];

            ans = min(ans, leftAns + rightAns + cost);
        }

        // step2: store answer
        dp[left][right] = ans;
        return dp[left][right];
    }


    // ---------------- TABULATION ----------------
    int solveTab(vector<int>& arr, vector<vector<int>>& maxi) {

        int n = arr.size();

        // dp[i][j] → minimum cost to build tree from arr[i..j]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // reverse recursion flow
        for (int left = n - 1; left >= 0; left--) {

            for (int right = 0; right < n; right++) {

                if (left >= right) continue;  // base case already 0

                int ans = INT_MAX;

                // partition point
                for (int i = left; i < right; i++) {

                    int leftAns = dp[left][i];       // left subtree cost
                    int rightAns = dp[i + 1][right]; // right subtree cost

                    int cost = maxi[left][i] * maxi[i + 1][right]; // root cost

                    ans = min(ans, leftAns + rightAns + cost);
                }

                dp[left][right] = ans;  // store result
            }
        }

        return dp[0][n-1];
    }


    int mctFromLeafValues(vector<int>& arr) {

        int n = arr.size();

        // maxi[i][j] → maximum value in subarray arr[i..j]
        vector<vector<int>> maxi(n, vector<int>(n, 0));

        // precompute maximum for all ranges
        for (int i = 0; i < n; i++) {

            maxi[i][i] = arr[i];

            for (int j = i + 1; j < n; j++) {
                maxi[i][j] = max(arr[j], maxi[i][j - 1]);
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // int ans = solveRec(arr, maxi, 0, n-1);
        // int ans = solveMem(arr, maxi, 0, n - 1, dp);

        int ans = solveTab(arr, maxi);

        return ans;
    }
};