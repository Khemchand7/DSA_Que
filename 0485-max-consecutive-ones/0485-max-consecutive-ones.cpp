class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0; // Tracks the current streak of consecutive 1s
        int ans = 0; // Stores the maximum streak of consecutive 1s

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++; // Increase count when 1 is found
                ans = max(count, ans); // Update maximum streak if needed
            } 
            else {
                count = 0; // Reset count when a 0 is encountered
            }
        }
        return ans; // Return the maximum streak of consecutive 1s
    }
};
