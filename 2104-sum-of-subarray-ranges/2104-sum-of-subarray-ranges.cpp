class Solution {
public:
    // Previous Smaller or Equal Element
    vector<int> prevSmallerEqualEle(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> psee(n, -1);

        for (int i = 0; i < n; i++) {

            // Keep equal elements to handle duplicates.
            // Only strictly greater elements are removed.
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return psee;
    }

    // Previous Greater or Equal Element
    vector<int> prevGreaterEqualEle(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> pgee(n, -1);

        for (int i = 0; i < n; i++) {

            // Keep equal elements to handle duplicates.
            // Only strictly smaller elements are removed.
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            pgee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pgee;
    }

    // Next Smaller Element
    vector<int> nextSmallerEle(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nse(n, n);

        for (int i = n - 1; i >= 0; i--) {

            // Remove greater OR equal elements.
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }

    // Next Greater Element
    vector<int> nextGreaterEle(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nge(n, n);

        for (int i = n - 1; i >= 0; i--) {

            // Remove smaller OR equal elements.
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            nge[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nge;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> psee = prevSmallerEqualEle(nums, n);
        vector<int> pgee = prevGreaterEqualEle(nums, n);

        vector<int> nse = nextSmallerEle(nums, n);
        vector<int> nge = nextGreaterEle(nums, n);

        long long sum = 0;

        for (int i = 0; i < n; i++) {

            // Contribution of nums[i] as the minimum
            long long leftMin = i - psee[i];
            long long rightMin = nse[i] - i;

            long long minContribution =
                leftMin * rightMin * nums[i];

            // Contribution of nums[i] as the maximum
            long long leftMax = i - pgee[i];
            long long rightMax = nge[i] - i;

            long long maxContribution =
                leftMax * rightMax * nums[i];

            // Range = maximum - minimum
            sum += maxContribution - minContribution;
        }

        return sum;
    }
};