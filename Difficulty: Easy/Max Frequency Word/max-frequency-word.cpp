class Solution {
  public:
    string maximumFrequency(string& s) {
        unordered_map<string,int>freq;
        string word = "";
        vector<string> order;
        int n = s.size();
        
        for(int i = 0; i <= n; i++){
            if(i == n || s[i] == ' '){
                if(!word.empty()){
                    freq[word]++;
                    order.push_back(word);
                    word = "";
                }
                
            }
            else{
                word += s[i];
            }
        }
        
        int maxFreq = INT_MIN;
        for(auto &it : freq){
            maxFreq = max(maxFreq, it.second);
        }
        
        for (string &w : order) {

            if (freq[w] == maxFreq)
                return w + " " + to_string(maxFreq);
        }
        return "";
    }
};