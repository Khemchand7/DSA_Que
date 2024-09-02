class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Index for the last element in nums1's initial part
        int j = n - 1; // Index for the last element in nums2
        int k = m + n - 1; // Index for the last element in nums1's total length

        // Merge from the end to avoid overwriting
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If there are remaining elements in nums2, copy them over
        // nums1 ke elements copy karane ki jarurat islie nhi hai kyuki nums1 already place ho chuke honge
/*         Remaining Elements:

        If nums2 runs out of elements first (j < 0), the remaining elements in nums1 are already sorted and in their correct       positions,         so there's no need to explicitly copy them.
        If nums1 runs out first (i < 0), then we continue to copy the remaining elements from nums2 into nums1 */
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

/* Memory Overlap: Since nums1 is intended to hold the merged array, it is assumed that it has enough space at the end to accommodate all elements of nums2. Directly merging from the start can overwrite elements that haven't been merged yet.

Incorrect Strategy: The correct strategy is to start filling nums1 from the end, moving backwards. This way, you can safely overwrite elements without losing data. */
