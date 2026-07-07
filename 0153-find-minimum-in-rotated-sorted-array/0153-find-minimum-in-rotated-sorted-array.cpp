class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = INT_MAX;   // Stores the minimum element found so far

        while(start <= end){
            int mid = start + (end - start)/2;

            // If left half is sorted, its first element is the minimum of this half
            if(nums[start] <= nums[mid]){
                ans = min(ans, nums[start]);   // Update answer with left half's minimum
                start = mid + 1;               // Search in the right half
            }
            else{
                // Right half is sorted, so minimum lies in the left unsorted half
                ans = min(ans, nums[mid]);     // Mid can be the minimum
                end = mid - 1;                 // Continue searching on the left
            }
        }

        return ans;
    }
};