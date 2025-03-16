class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;         // Stores the current subarray sum
        int ans = INT_MIN;   // Stores the maximum subarray sum found so far

        for(int i = 0; i < n; i++) {
            sum += nums[i];  // Add current element to the subarray sum
            ans = max(sum, ans); // Update maximum subarray sum if needed
            
            if(sum < 0) {    // If sum becomes negative, reset to 0 (start a new subarray)
                sum = 0;
            }
        }
        return ans;          // Return the maximum subarray sum
    }
};
