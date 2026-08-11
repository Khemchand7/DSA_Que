class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        
        stack<int> st;
        vector<int> ans(n);
        
        for(int i = 0;  i< n; i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            st.empty() ? ans[i] = -1 : ans[i] = st.top();
            st.push(arr[i]);
            
        }
        return ans;
        
    }
};