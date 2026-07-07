class Solution {
public:
// Duplicates make it impossible to identify the sorted half,
// so shrink the search space from both ends.
// Shrinking both ends may lead to O(n) in the worst case.
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Target found
            if (nums[mid] == target)
                return true;

            // If duplicates exist at both ends, shrink the search space
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
                continue;// may be possibility that after removing one there may be other as  well need to remove all
            }

            // Check if the left half is sorted
            if (nums[start] <= nums[mid]) {

                // Target lies in the sorted left half
                if (target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;
                }
                // Otherwise, search in the right half
                else {
                    start = mid + 1;
                }
            }

            // Otherwise, the right half is sorted
            else {

                // Target lies in the sorted right half
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
        return false;
    }
};