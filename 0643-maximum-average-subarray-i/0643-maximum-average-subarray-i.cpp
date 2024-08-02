class Solution {
public:

    double bruteForce(vector<int>& nums, int& k){
        //Time Complexity of this code is O(n*n) due to which it is showing error Time Limit exceed
        // we will solve this in o(n) using sliding window method
        int maxSum=INT_MIN;
        int i=0,j=k-1;
        while(j < nums.size()){
           int sum=0;
            for( int y=i;y<=j;y++){
                 sum+=nums[y];
            }
            maxSum = max(sum,maxSum);
            i++,j++;
        }
        double maxAvg = maxSum/(double)k;
        return maxAvg;
    }
    double slidingWindow(vector<int>& nums, int& k){
        int maxSum=INT_MIN;
        int i=0,j=k-1;
        int sum=0;
        for(int y=i;y<=j;y++){
            sum+=nums[y];
        }
        maxSum=max(sum,maxSum);//yahan pr islie assing kia kyuki agar sirf ek hi element hua to kabhi while loop ke andar enter hi nhi karega jisse ans INT_MIN aaega
        j++;
        while(j<nums.size()){
            sum-=nums[i++];
            sum+=nums[j++];//yahan pr j ko increment islie kia hai kyuki upr wala j ab accesible nhi hai loop ke bahar jab hi jaega jab pura traverse kar lega to aage badane ke lie j++ kia hai 
            maxSum=max(sum,maxSum);
        }
        double maxAvg = maxSum/(double)k;
        return maxAvg;
    }
    double findMaxAverage(vector<int>& nums, int k) {
       //return bruteForce(nums,k); 
       return slidingWindow(nums,k);
    }
};