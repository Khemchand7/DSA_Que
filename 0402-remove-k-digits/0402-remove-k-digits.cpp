class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (int i = 0; i < num.length(); i++) {

            // Remove larger previous digits to get the smallest number
            // if st.top() == num[i] we should add in the stack e.g 112 and expected 11 
            while (!st.empty() && k > 0 && st.top() - '0' > num[i] - '0') {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // No digits left after deletion
        if (st.empty()) return "0";

        // if there is still digits to pop e.g 12345
        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }

        string ans = "";

        // Stack gives digits in reverse order
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Remove trailing zeros before reversing
        while (!ans.empty() && ans.back() == '0') {
            ans.pop_back();
        }

        // Number contains only zeros
        if (ans.empty()) return "0";

        // Restore the original order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};