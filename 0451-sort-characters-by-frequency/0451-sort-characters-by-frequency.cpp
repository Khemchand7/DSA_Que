class Solution {
public:
    struct cmp{
        bool operator()(pair<int,char> a, pair<int,char> b){

            // Higher frequency should have higher priority
            if(a.first != b.first){
                return a.first < b.first;
            }

            // If frequencies are equal, smaller character gets higher priority
            return a.second > b.second;
        }
    };

    string frequencySort(string s) {

        unordered_map<char,int> freq;

        // Max heap storing {frequency, character}
        priority_queue<pair<int,char>, vector<pair<int,char>>, cmp> pq;

        // Count frequency of every character
        for(auto &c : s){
            freq[c]++;
        }

        // Push {frequency, character} into the heap
        for(auto &it : freq){
            pq.push({it.second, it.first});
        }

        string ans = "";

        // Process characters from highest frequency to lowest
        while(!pq.empty()){

            auto [freq, character] = pq.top();
            pq.pop();

            // Append the character 'freq' number of times
            while(freq--){
                ans += character;
            }
        }

        return ans;
    }
};