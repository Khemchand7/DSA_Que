class Solution {
  public:
    bool subArrayExists(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> uset;  // Stores all prefix sums seen so far
        uset.insert(0);           // Insert 0 to handle case where subarray starting from index 0 has sum 0
        long long pSum = 0;       // Tracks prefix sum

        for (auto num : arr) {
            pSum += num;          // Update prefix sum

            // If this prefix sum was seen before, a subarray with sum 0 exists
            if (uset.count(pSum)) return true;

            uset.insert(pSum);    // Otherwise, store the current prefix sum
        }
        
        // No zero-sum subarray found
        return false;
    }
};