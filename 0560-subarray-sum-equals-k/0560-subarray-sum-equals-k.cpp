class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pSum = 0; // Prefix sum of elements
        int ans = 0; // Count of subarrays with sum equal to k
        unordered_map<int, int> umap; // Stores frequency of prefix sums

        for (int j = 0; j < n; j++) {
            pSum += nums[j]; // Update prefix sum

            if (pSum == k) ans++; // Subarray from index 0 to j has sum k

            int val = pSum - k;
            if (umap.find(val) != umap.end()) {
                ans += umap[val]; // Add count of previous prefix sums that make current subarray sum k
            }

            umap[pSum]++; // Store/update the frequency of current prefix sum
        }

        return ans; // Return total number of valid subarrays
    }
};
