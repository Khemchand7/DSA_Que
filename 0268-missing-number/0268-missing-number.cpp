class Solution {
public:
    int missingNumber(vector<int>& nums) {
     int sum=0;
    int n=nums.size();
       for(int i=0;i<n;i++){
        sum+=nums[i];
       }
       
       int actual_sum=(n*(n+1))/2;
       return actual_sum-sum;
    }
};