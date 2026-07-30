class Solution {
public:
    struct cmp {

        bool operator()(pair<int, string> a, pair<int, string> b) {

            // Higher frequency should come first
            if (a.first != b.first)
                return a.first < b.first;

            // If frequency is same, lexicographically smaller word first
            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        // Count frequency of each word
        for (string &word : words)
            freq[word]++;

        // Max Heap
        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       cmp> pq;

        // Push all unique words into heap
        for (auto &it : freq)
            pq.push({it.second, it.first});

        vector<string> ans;

        // Extract top k frequent words
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};