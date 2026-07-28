class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        // Max Heap -> {distance, value}
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {

            // Insert first k elements
            if (pq.size() < k) {
                pq.push({abs(arr[i] - x), arr[i]});
            }

            // If current element is closer, replace the farthest element
            else if (pq.top().first > abs(arr[i] - x)) {
                pq.pop();
                pq.push({abs(arr[i] - x), arr[i]});
            }

            // If distance is same, prefer the smaller value
            else if (pq.top().first == abs(arr[i] - x) &&
                     pq.top().second > arr[i]) {
                pq.pop();
                pq.push({abs(arr[i] - x), arr[i]});
            }
        }

        vector<int> ans;

        // Extract the k closest elements
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Return the result in ascending order
        sort(ans.begin(), ans.end());

        return ans;
    }
};