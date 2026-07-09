class Solution {
public:
    // Check if array can be split into at most k subarrays
    // such that no subarray sum exceeds totalSum.
    bool checkSum(vector<int>& nums, int k, int totalSum){
        int currSum = 0;
        int currSubArr = 1;   // Start with one subarray

        for(auto ele : nums){
            currSum += ele;

            // If current subarray exceeds allowed sum,
            // start a new subarray from current element.
            if(currSum > totalSum){
                currSubArr++;
                currSum = ele;
            }

            // More than k subarrays needed -> not possible.
            if(currSubArr > k){
                return false;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        // Minimum possible answer = largest element.
        int start = *max_element(nums.begin(), nums.end());

        // Maximum possible answer = sum of all elements.
        int end = accumulate(nums.begin(), nums.end(), 0);

        int ans = 0;

        // Binary search on the maximum allowed subarray sum.
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(checkSum(nums, k, mid)){
                ans = mid;          // Current answer is possible.
                end = mid - 1;      // Try to minimize it further.
            }
            else{
                start = mid + 1;    // Increase allowed maximum sum.
            }
        }

        return ans;
    }
};