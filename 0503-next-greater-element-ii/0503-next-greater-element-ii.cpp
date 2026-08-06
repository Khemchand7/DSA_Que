class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        stack<int> st;

        // Traverse the array twice from right to left to simulate a circular array
        for (int i = 2 * n - 1; i >= 0; i--) {

            // Remove all elements that are smaller than or equal to the current element
            // since they cannot be its next greater element
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            // Store the answer only during the first pass (i < n)
            // By now, the stack contains candidates from both the right side
            // and the beginning of the array (circular traversal)
            if (i < n) {
                ans[i] = st.empty() ? -1 : st.top();// bcs ans will be in reverse order
            }

            // Current element can be the next greater element for
            // elements lying to its left
            st.push(nums[i % n]);
        }

        return ans;
    }
};

/* nums :1 2 3 4 3
idx  :0 1 2 3 4

st : 4 3 2 1
ans : 2  3 4 -1 4          */