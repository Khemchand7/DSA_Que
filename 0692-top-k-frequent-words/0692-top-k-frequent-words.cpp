class Solution {
public:

    struct cmp {

        bool operator()(pair<int,string> a,
                        pair<int,string> b) {

            // Lower frequency should stay on top
            if(a.first != b.first)
                return a.first > b.first;

            // If same frequency, lexicographically larger stays on top
            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> freq;

        for(string &word : words)
            freq[word]++;

        priority_queue<pair<int,string>,
                       vector<pair<int,string>>,
                       cmp> pq;

        for(auto &it : freq){

            pq.push({it.second, it.first});

            if(pq.size() > k)
                pq.pop();
        }

        vector<string> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};