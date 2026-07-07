class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // If only one element is present, it is the peak.
        if(n == 1) return 0;

        // Check if the first element is the peak.
        if(nums[0] > nums[1]) return 0;

        // Check if the last element is the peak.
        if(nums[n - 1] > nums[n - 2]) return n - 1;

        // Ignore the first and last elements as they are already checked.
        int start = 1;
        int end = n - 2;

        while(start <= end){
            int mid = start + (end - start) / 2;

            // Peak element found.
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
                return mid;
            }

            // We are on the increasing slope, so peak lies on the right.
            else if(nums[mid] > nums[mid - 1]){
                start = mid + 1;
            }

            // We are on the decreasing slope, so peak lies on the left.
            else{
                end = mid - 1;
            }
        }

        return -1;
    }
};