class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        stack<char> st;

        for(char c : s){
            if(!st.empty() && st.top() == c){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        string ans(st.size(),' ');
        for(int i = st.size()-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};