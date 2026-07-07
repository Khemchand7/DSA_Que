class Solution {
public:
    // Binary Search:
    // Treat each pair as one unit.
    // If the number of elements up to a complete pair is even,
    // the single element lies on the right; otherwise, it lies on the left.
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Handle edge cases where the single element is at the boundaries
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int start = 2;
        int end = n - 3;

        while(start <= end){
            int mid = start + (end - start) / 2;

            // Found the single element
            if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // Move to the second index of the current pair
            if(nums[mid] == nums[mid + 1])
                mid = mid + 1;

            // Number of elements from start to the current complete pair
            int len = mid - start + 1;

            // Even length => single element is on the right
            if((len & 1) == 0){
                start = mid + 1;
            }
            // Odd length => single element is on the left
            else{
                end = mid - 1;
            }
        }

        return -1;
    }
};