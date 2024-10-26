class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        int posIndex = 0;     // Index to place positive numbers
        int negIndex = 1;     // Index to place negative numbers
        vector<int> ans(n, 0); // Result vector initialized with zeros of size n

        // Iterate over each element in the input array
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                ans[posIndex] = nums[i]; // Place positive number at posIndex
                posIndex += 2;           // Move to the next position for positive numbers
            }
            if(nums[i] < 0) {
                ans[negIndex] = nums[i]; // Place negative number at negIndex
                negIndex += 2;           // Move to the next position for negative numbers
            }
        }

        return ans; // Return the rearranged array
    }
};
