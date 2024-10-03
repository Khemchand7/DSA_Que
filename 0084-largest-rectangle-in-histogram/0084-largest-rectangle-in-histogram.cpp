class Solution {
public:
    // This function returns a vector containing the indices of the next smaller elements for each element in the array
    // If no smaller element exists, the value will be -1.
    vector<int> nextSmallerElement(vector<int>&arr, int n) {
        stack<int> st;
        st.push(-1);  // Push -1 as a placeholder for elements that don't have a smaller element on the right
        vector<int> ans(n);  // Resultant vector to store the indices of the next smaller element
        
        // Traverse the array from right to left to find the next smaller element
        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];  // Current element we're analyzing

            // Pop elements from the stack until we find an element smaller than the current one or reach the end (-1)
            while (st.top() != -1 && arr[st.top()] >= curr) {//equals to is imp because otherwise equals to wale case me pop ni karega and we won't get -1 as ans istead we get curr 
                st.pop();
            }

            // The current top of the stack is the index of the next smaller element
            ans[i] = st.top();

            // Push the index of the current element onto the stack for future comparisons
            st.push(i);
        }
        return ans;
    }

    // This function returns a vector containing the indices of the previous smaller elements for each element in the array
    // If no smaller element exists, the value will be -1.
    vector<int> prevSmallerElement(vector<int>&arr, int n) {
        stack<int> st;
        st.push(-1);  // Push -1 as a placeholder for elements that don't have a smaller element on the left
        vector<int> ans(n);  // Resultant vector to store the indices of the previous smaller element

        // Traverse the array from left to right to find the previous smaller element
        for (int i = 0; i < n; i++) {
            int curr = arr[i];  // Current element we're analyzing

            // Pop elements from the stack until we find an element smaller than the current one or reach the end (-1)
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }

            // The current top of the stack is the index of the previous smaller element
            ans[i] = st.top();

            // Push the index of the current element onto the stack for future comparisons
            st.push(i);
        }
        return ans;
    }

    // This function calculates the largest rectangle area that can be formed in a histogram
    // 'heights' represents the heights of the histogram bars
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();  // Number of elements (bars) in the histogram

        // Get the indices of the next smaller elements for each bar
        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        // Get the indices of the previous smaller elements for each bar
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int maxArea = INT_MIN;  // Variable to store the maximum area found

        // Loop through each bar in the histogram to calculate the area of the largest rectangle that can be formed
        for (int i = 0; i < n; i++) {
            int len = heights[i];  // The height of the current bar
            
            // If no smaller element exists on the right (next smaller element is -1), treat it as if it extends to the end of the histogram
            if (next[i] == -1) {
                next[i] = n;
            }
            
            // Calculate the width of the rectangle that can be formed with the current bar as the shortest bar
            int wid = next[i] - prev[i] - 1;

            // Calculate the area of the rectangle (height * width)
            int area = len * wid;

            // Update the maximum area if we find a larger one
            maxArea = max(area, maxArea);
        }

        // Return the largest rectangle area found
        return maxArea;
    }
};
