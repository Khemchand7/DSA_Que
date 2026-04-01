class Solution {
public:
    int solveRec(vector<int>& nums, int prev, int curr) {

        // Base case: reached end of array
        if (curr >= nums.size()) {
            return 0;
        }

        int include = 0;

        // Include current element if it forms increasing sequence
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveRec(nums, curr, curr + 1);
        }

        // Skip current element
        int exclude = solveRec(nums, prev, curr + 1);

        int ans = max(include, exclude);
        return ans;
    }

    int solveDP(vector<int>& nums, int prev, int curr,
                vector<vector<int>>& dp) {

        // Base case
        if (curr >= nums.size()) {
            return 0;
        }

        // prev + 1 used because prev can be -1 (vector index cannot be
        // negative)
        if (dp[prev + 1][curr] != -1) {
            return dp[prev + 1][curr];
        }

        int include = 0;

        // Choose current element if increasing condition satisfied
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveDP(nums, curr, curr + 1, dp);
        }

        // Do not choose current element
        int exclude = solveDP(nums, prev, curr + 1, dp);

        int ans = max(include, exclude);

        // Store result in DP table
        dp[prev + 1][curr] = ans;

        return ans;
    }

    int solveTabulation(vector<int>& nums) {
        int n = nums.size();

        // dp[prev+1][curr] : LIS length starting from state (prev, curr)
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--) {

            // prev must always be before curr in the array
            for (int prev = curr - 1; prev >= -1; prev--) {

                int include = 0;

                // include current element if it keeps sequence increasing
                if (prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + dp[curr + 1][curr + 1];
                }

                // skip current element
                int exclude = dp[curr + 1][prev + 1];

                int ans = max(include, exclude);

                // prev+1 used because prev can be -1 (avoid negative index)
                dp[curr][prev + 1] = ans;
            }
        }

        // start state: prev = -1 , curr = 0
        return dp[0][-1 + 1];
    }

    int solveTabulationSO(vector<int>& nums) {
        int n = nums.size();

        // current[prev+1] and next[prev+1] store LIS length for state (prev,
        // curr)
        vector<int> current(n + 1, 0);
        vector<int> next(n + 1, 0);

        // iterate curr from back because recursion goes curr -> curr+1
        for (int curr = n - 1; curr >= 0; curr--) {

            // prev must always lie before curr
            for (int prev = curr - 1; prev >= -1; prev--) {

                int include = 0;

                // include nums[curr] if it forms increasing sequence
                if (prev == -1 || nums[curr] > nums[prev]) {
                    include =
                        1 + next[curr + 1]; // move to state (curr, curr+1)
                }

                int exclude =
                    next[prev + 1]; // skip curr → state (prev, curr+1)

                int ans = max(include, exclude);

                // prev+1 shift is required because prev can be -1
                current[prev + 1] = ans;
            }

            next = current; // move current row to next row for next iteration
        }

        // start state: prev = -1 , curr = 0
        return current[0];
    }

    int solveUsingBinarySearch(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        ans.push_back(
            nums[0]); // ans[i] = smallest possible tail of LIS

        for (int i = 1; i < n; i++) {

            // if current number is greater than largest element
            // we can extend the LIS
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } else {
                // find first element >= nums[i]
                // this keeps ans sorted and ensures smallest tail
                int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

                // replace to maintain minimal tail value
                ans[idx] = nums[i];
            }
        }

        return ans.size(); // length of LIS
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        int prev = -1; // no previous element chosen
        int curr = 0;  // start from first element

        // dp[prev+1][curr] memoization table
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // return solveDP(nums, prev, curr, dp);
        // return solveTabulation(nums);
        // return solveTabulationSO(nums);
        return solveUsingBinarySearch(nums);
    }
};