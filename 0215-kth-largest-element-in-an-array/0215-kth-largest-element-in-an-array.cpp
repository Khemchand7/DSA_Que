class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        // Min Heap to maintain the k largest elements
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++) {

            // Insert first k elements into the heap
            if (pq.size() < k) {
                pq.push(nums[i]);
            }

            // If current element is larger than the smallest
            // among the current k largest, replace it
            else if (pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        // Smallest among the k largest elements
        return pq.top();
    }
};