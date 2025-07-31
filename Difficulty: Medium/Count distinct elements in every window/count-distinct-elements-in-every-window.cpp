class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int,int> freq;
        vector<int> ans;
        
        // Count elements in the first window
        for(int i = 0; i < k; i++) {
            freq[arr[i]]++;
        }
        ans.push_back(freq.size());

        int s = 1, e = k;

        // Slide the window
        while(e < n) {
            freq[arr[s - 1]]--;           // Remove the outgoing element
            if(freq[arr[s - 1]] == 0) {
                freq.erase(arr[s - 1]);   // Erase if frequency becomes 0
            }
            freq[arr[e]]++;               // Add the incoming element
            ans.push_back(freq.size());   // Store distinct count
            s++; 
            e++;
        }

        return ans;
    }
};
