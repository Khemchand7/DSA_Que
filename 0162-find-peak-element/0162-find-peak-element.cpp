class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            // if left side is increasing, peak lies on right
            if (nums[mid] < nums[mid + 1]) {
                s = mid + 1;
            } 
            // otherwise, peak lies on left or at mid
            else {
                e = mid;
            }
        }
        return s;  // index of peak element
    }
};
