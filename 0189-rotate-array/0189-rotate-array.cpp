class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int newIndex;                    // Variable to store the new index after rotation
        int n = nums.size();             // Get the size of the array
        vector<int> ans(n);              // Create a temporary array to store rotated elements

        // Loop through each element in the original array
        for(int currIndex = 0; currIndex < n; currIndex++) {
            newIndex = (currIndex + k) % n;   // Calculate the new index after rotation
            ans[newIndex] = nums[currIndex];  // Place the element at its new index in the temp array
        }

        nums = ans;   // Copy the rotated array back to the original array
    }
};
