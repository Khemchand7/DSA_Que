class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Always perform binary search on the smaller array.
        if(n1 > n2) 
            return findMedianSortedArrays(nums2, nums1);

        int start = 0;
        int end = n1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            // Partition points in both arrays.
            int cut1 = mid;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // Left and right values around the partitions.
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // Correct partition found.
            if(l1 <= r2 && l2 <= r1){

                // Even total elements -> average of middle two.
                if(((n1 + n2) & 1) == 0){
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                }

                // Odd total elements -> maximum of left partition.
                return (double)max(l1, l2);
            }

            // Move partition to the left.
            else if(l1 > r2){
                end = cut1 - 1;
            }

            // Move partition to the right.
            else{
                start = cut1 + 1;
            }
        }

        return -1.0;
    }
};