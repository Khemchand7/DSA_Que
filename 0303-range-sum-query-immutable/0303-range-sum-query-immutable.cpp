class NumArray {
public:
    // Prefix sum vector to store cumulative sums of the input array
    vector<int> pSum;

    // Constructor that takes the input array and builds the prefix sum
    NumArray(vector<int>& nums) {
        int n = nums.size();

        // Resize pSum to the same size as nums and initialize all elements to 0
        // This is necessary to avoid out-of-bounds access
        pSum.resize(n);

        // First element of prefix sum is same as the first element of input
        pSum[0] = nums[0];

        // Build the prefix sum array
        for (int i = 1; i < n; i++) {
            pSum[i] = pSum[i - 1] + nums[i];
        }
    }

    // Function to return the sum of elements from index 'left' to 'right' (inclusive)
    int sumRange(int left, int right) {
        if (left == 0) {
            return pSum[right];
        } else {
            return pSum[right] - pSum[left - 1];
        }
    }
};

