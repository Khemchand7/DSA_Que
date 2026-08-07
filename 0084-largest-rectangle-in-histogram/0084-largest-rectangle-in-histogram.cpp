/* 
Fix each bar as the minimum height of the rectangle.
Find how far this bar can extend to the left and right until a smaller bar appears.
When a bar is popped from the monotonic stack, both its boundaries become known, so compute its maximum area immediately.
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Stores indices in increasing order of heights
        stack<int> st;

        int maxArea = 0;

        // Traverse all bars
        for (int i = 0; i < n; i++) {

            // Current bar becomes the Next Smaller Element (NSE)
            // for all taller or equal bars in the stack
            while (!st.empty() && heights[st.top()] >= heights[i]) {

                int height = heights[st.top()];
                st.pop();

                int nse = i;

                // After popping, the new stack top becomes
                // the Previous Smaller Element (PSE)
                int pse = st.empty() ? -1 : st.top();

                int width = nse - pse - 1;
                int currArea = height * width;

                maxArea = max(maxArea, currArea);
            }

            // Maintain monotonic increasing stack
            st.push(i);
        }

        // Remaining bars have no smaller element on the right,
        // so their NSE is 'n'
        while (!st.empty()) {

            int height = heights[st.top()];
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            int width = nse - pse - 1;
            int currArea = height * width;

            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }
};