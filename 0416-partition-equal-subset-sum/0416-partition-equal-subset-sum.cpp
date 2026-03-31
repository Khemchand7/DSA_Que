class Solution {
public:
    int solveRec(vector<int>& arr, int target, int index) {

        if (target == 0)
            return 1;
        // success base case: subset found

        if (index >= arr.size() || target < 0)
            return 0;
        // failure case: no elements left or target became negative

        int include = solveRec(arr, target - arr[index], index + 1);
        // take current element

        int exclude = solveRec(arr, target, index + 1);
        // skip current element

        return (include || exclude);
        // if any path works → subset exists
    }

    int solveMem(vector<int>& arr, int target, int index,
                 vector<vector<int>>& dp) {

        if (target == 0)
            return 1;

        if (index >= arr.size() || target < 0)
            return 0;

        if (dp[index][target] != -1)
            return dp[index][target];
        // step1 (DP template): if answer already computed, return it

        int include = solveMem(arr, target - arr[index], index + 1, dp);
        int exclude = solveMem(arr, target, index + 1, dp);

        return dp[index][target] = (include || exclude);
        // step2 (DP template): store computed answer
    }

    int solveTab(vector<int>& arr, int target) {

        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        // dp[i][j] → can we make sum j using elements from index i → n-1

        for (int j = 0; j <= n; j++) {
            dp[j][0] = 1;
        }
        // base case: target 0 is always possible (empty subset)

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= target; j++) {

                int include = 0;

                if (j - arr[i] >= 0)
                    include = dp[i + 1][j - arr[i]];
                // include current element

                int exclude = dp[i + 1][j];
                // exclude current element

                dp[i][j] = (include || exclude);
            }
        }

        return dp[0][target];
        // answer: can we make target starting from index 0
    }

    int solveTabSO(vector<int>& arr, int target) {

        int n = arr.size();

        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        //  optimized: we only need current row and next row

        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        curr[0] = 1;
        next[0] = 1;
        // base case: target 0 is always possible

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= target; j++) {

                int include = 0;

                if (j - arr[i] >= 0)
                    include = next[j - arr[i]];
                // include → check if remaining sum was possible in next row

                int exclude = next[j];
                // exclude → simply move to next index

                curr[j] = (include || exclude);
            }

            next = curr;
            // IMPORTANT step (common DP mistake if forgotten)
            // move current row to next row for next iteration
        }

        return curr[target];
        // answer: can we form target using array
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int index = 0;

        int totalSum = accumulate(nums.begin(),nums.end(),0);

        if(totalSum & 1) return false;

        int target = totalSum >> 1;
        //vector<vector<int>> dp(n+1, vector<int>(target+1,-1));

        //int ans = solveRec(nums, target, index);
        //int ans = solveMem(nums, target, index, dp);
        int ans = solveTab(nums, target);
        return ans;
    }
};