class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int>freq; // To store frequency of elements

        for(auto pair : nums){
            // Count how many times (pair - k) occurred before
            if(freq.count(pair - k)){
                ans += freq[pair - k];
            }
            // Count how many times (pair + k) occurred before
            if(freq.count(pair + k)){
                ans += freq[pair + k];
            }
            freq[pair]++; // Update frequency of current number
        }
        return ans;
    }
};
