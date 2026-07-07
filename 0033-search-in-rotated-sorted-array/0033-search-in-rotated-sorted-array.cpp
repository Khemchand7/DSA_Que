class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            // Calculate middle index safely
            int mid = start + (end - start) / 2;

            // Target found
            if (nums[mid] == target)
                return mid;

            // Check if the left half is sorted
            else if (nums[start] <= nums[mid]) {

                // Target lies within the sorted left half
                if (target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;
                }
                // Otherwise, search in the right half
                else {
                    start = mid + 1;
                }
            }

            // Otherwise, the right half must be sorted
            else {

                // Target lies within the sorted right half
                if (target >= nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                }
                // Otherwise, search in the left half
                else {
                    end = mid - 1;
                }
            }
        }

        // Target not present
        return -1;
    }
};