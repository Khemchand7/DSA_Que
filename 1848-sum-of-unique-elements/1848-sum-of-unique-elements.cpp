class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq; // Map to store frequency of each number
        int sum = 0; // Variable to store sum of unique elements

        // Count the frequency of each number in the array
        for(auto val : nums){
            freq[val]++;
        }

        // Iterate through the array again to sum only unique elements
        for(auto val : nums){
            if(freq[val] == 1){ // If the element occurs only once we can alos write as pair.second == 1
                sum += val;
            }
        }

        return sum; // Return the sum of all unique elements
    }
};
