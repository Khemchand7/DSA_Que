class Solution {
public:
    int solveRec(vector<int>& arr, vector<vector<int>>& maxi, int left,
                 int right) {
        if (left == right)
            return 0;

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            int leftAns = solveRec(arr, maxi, left, i);
            int rightAns = solveRec(arr, maxi, i + 1, right);
            int cost = maxi[left][i] * maxi[i + 1][right];
            ans = min(ans, leftAns + rightAns + cost);
        }
        return ans;
    }

    int solveMem(vector<int>& arr, vector<vector<int>>& maxi, int left,
                 int right, vector<vector<int>>& dp) {
        if (left == right)
            return 0;

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            int leftAns = solveMem(arr, maxi, left, i, dp);
            int rightAns = solveMem(arr, maxi, i + 1, right, dp);
            int cost = maxi[left][i] * maxi[i + 1][right];
            ans = min(ans, leftAns + rightAns + cost);
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
    int solveTab(vector<int>& arr, vector<vector<int>>& maxi) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int left = n - 1; left >= 0; left--) {
            for (int right = 0; right < n; right++) {
                int ans = INT_MAX;
                if(left >= right) continue;
                
                for (int i = left; i < right; i++) {
                    int leftAns = dp[left][i];
                    int rightAns =dp[i + 1][right];
                    int cost = maxi[left][i] * maxi[i + 1][right];
                    ans = min(ans, leftAns + rightAns + cost);
                }
                dp[left][right] = ans;
                
            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> maxi(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            maxi[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[i][j] = max(arr[j], maxi[i][j - 1]);
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // int ans = solveRec(arr, maxi, 0, n-1);
        //int ans = solveMem(arr, maxi, 0, n - 1, dp);
        int ans = solveTab(arr, maxi);
        return ans;
    }
};