class Solution {
public:
    // Binary Search:
    // Before the single element, pairs start at even indices.
    // After the single element, the pairing pattern shifts, allowing binary search.
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Handle edge cases where the single element is at the boundaries
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int start = 1;
        int end = n - 2;

        while(start <= end){
            int mid = start + (end - start) / 2;

            // Found the element whose adjacent elements are different
            if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // Pairing is valid:
            // - Odd index pairs with previous element.
            // - Even index pairs with next element.
            // So, the single element must be on the right.
            else if(((mid & 1) == 1 && nums[mid - 1] == nums[mid]) ||
                    ((mid & 1) == 0 && nums[mid] == nums[mid + 1]))
                start = mid + 1;

            // Pairing pattern is broken, so search on the left.
            else
                end = mid - 1;
        }

        return -1;
    }
};