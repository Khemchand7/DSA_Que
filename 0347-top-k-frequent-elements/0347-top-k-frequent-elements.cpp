class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        // Store the frequency of each number
        unordered_map<int, int> mp;

        // Min Heap -> {frequency, number}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<int> ans;

        // Count the frequency of each element
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        // Maintain the k most frequent elements
        for (auto &it : mp) {

            // Insert first k elements
            if (pq.size() < k) {
                pq.push({it.second, it.first});
            }

            // Replace if current element has a higher frequency
            else if (pq.top().first < it.second) {
                pq.pop();
                pq.push({it.second, it.first});
            }
        }

        // Extract the k most frequent elements
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};