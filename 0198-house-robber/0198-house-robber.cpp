class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;  
        // no houses → no money

        if (n == 1) return nums[0];  
        // only one house → must rob it

        vector<int> dp(n);  
        // dp[i] = max money we can rob till index i

        dp[0] = nums[0];  
        // only first house

        dp[1] = max(nums[0], nums[1]);  
        // choose best between first two houses

        for (int i = 2; i < n; i++) {
            int included = nums[i] + dp[i - 2];  
            // rob current → cannot take previous

            int notIncluded = dp[i - 1];  
            // skip current → take previous best

            dp[i] = max(included, notIncluded);  
            // choose best option
        }

        return dp[n - 1];  
        // max money till last house
    }
};