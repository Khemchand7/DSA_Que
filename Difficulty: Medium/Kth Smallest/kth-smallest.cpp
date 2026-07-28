class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        int n = arr.size();

        // Max Heap to maintain the k smallest elements
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {

            // Insert first k elements into the heap
            if (pq.size() < k) {
                pq.push(arr[i]);
            }

            // If current element is smaller than the largest
            // among the current k smallest, replace it
            else if (pq.top() > arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        // Largest among the k smallest elements
        return pq.top();
    }
};