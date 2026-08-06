        class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);   // Default answer is 0 (no warmer day exists)

        // {temperature, index}
        stack<pair<int, int>> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove all temperatures that are smaller than or equal to
            // the current temperature since they can never be the next warmer day
            while (!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }

            // If a warmer day exists, store the number of days to wait
            if (!st.empty())
                ans[i] = st.top().second - i;

            // Current temperature can be the next warmer day
            // for temperatures on its left
            st.push({temperatures[i], i});
        }

        return ans;
    }
};      