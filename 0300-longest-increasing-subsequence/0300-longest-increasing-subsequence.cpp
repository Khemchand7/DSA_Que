class Solution {
public:
    int solveRec(vector<int> &nums, int prev, int curr){

        // Base case: reached end of array
        if(curr >= nums.size()){
            return 0;
        }

        int include = 0;

        // Include current element if it forms increasing sequence
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveRec(nums, curr, curr + 1);
        }
        
        // Skip current element
        int exclude = solveRec(nums, prev, curr + 1);

        int ans = max(include, exclude);
        return ans;
    }

    int solveDP(vector<int> &nums, int prev, int curr, vector<vector<int>> &dp){

        // Base case
        if(curr >= nums.size()){
            return 0;
        }

        // prev + 1 used because prev can be -1 (vector index cannot be negative)
        if(dp[prev + 1][curr] != -1){
            return dp[prev + 1][curr];
        }

        int include = 0;

        // Choose current element if increasing condition satisfied
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveDP(nums, curr, curr + 1, dp);
        }
        
        // Do not choose current element
        int exclude = solveDP(nums, prev, curr + 1, dp);

        int ans = max(include, exclude);

        // Store result in DP table
        dp[prev + 1][curr] = ans;

        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        int prev = -1;   // no previous element chosen
        int curr = 0;    // start from first element

        // dp[prev+1][curr] memoization table
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solveDP(nums, prev, curr, dp);
    }
};