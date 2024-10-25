class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;                  // Pointer to track the position of 0s
        int right = nums.size() - 1;    // Pointer to track the position of 2s
        int index = 0;                  // Pointer to iterate through the array

        // Iterate until index crosses the right pointer
        while(index <= right) {
            if(nums[index] == 0) {
                // If the current element is 0, swap it with the left pointer
                swap(nums[index], nums[left]);
                left++;    // Move the left pointer to the right
                index++;   // Move the index forward as this position is sorted
            }
            else if(nums[index] == 2) {
                // If the current element is 2, swap it with the right pointer
                swap(nums[index], nums[right]);
                right--;   // Move the right pointer to the left
                // Don't increment index here, as we need to check the swapped element at index
            }
            else {
                // If the current element is 1, just move the index forward
                index++;
            }
        }
    }
};
