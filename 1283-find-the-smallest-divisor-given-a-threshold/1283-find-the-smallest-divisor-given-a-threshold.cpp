class Solution {
public:
    int getSum(vector<int>& nums, int divisor, int n){
        int sum = 0;

        for(int i = 0; i < n; i++){
            // Add the ceiling value of each division
            //sum += ceil((double)nums[i] / divisor);
            sum += (nums[i] + divisor - 1)/divisor;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        // Divisor can range from 1 to the largest element
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());

        int ans = -1;

        while(start <= end){
            // Try the middle divisor
            int mid = start + (end - start) / 2;

            // Calculate the required sum using the current divisor
            int sum = getSum(nums, mid, n);

            if(sum <= threshold){
                // Current divisor is valid, try to find a smaller one
                ans = mid;
                end = mid - 1;
            }
            else{
                // Sum exceeds threshold, increase the divisor
                start = mid + 1;
            }
        }

        return ans;
    }
};