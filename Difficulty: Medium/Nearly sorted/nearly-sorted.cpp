class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();

        // Min Heap to maintain the next k+1 candidate elements
        priority_queue<int, vector<int>, greater<int>> pq;

        // Insert the first k+1 elements into the heap
        for (int i = 0; i <= k; i++) {
            pq.push(arr[i]);
        }

        int index = 0;

        // Process the remaining elements
        for (int i = k + 1; i < n; i++) {

            // Place the smallest element at its correct position
            arr[index] = pq.top();
            index++;
            pq.pop();

            // Add the next element to maintain k+1 candidates
            pq.push(arr[i]);
        }

        // Place the remaining elements from the heap
        while (!pq.empty()) {
            arr[index] = pq.top();
            pq.pop();
            index++;
        }
    }
};