class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);   // Default is 0 (no warmer day exists)

        // Stores indices of temperatures in monotonic decreasing order
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove all indices whose temperatures are
            // less than or equal to the current temperature
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If a warmer temperature exists, store the number of days to wait
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }

            // Push the current index as it may be the next warmer day
            // for temperatures on its left
            st.push(i);
        }

        return ans;
    }
};