class Solution {
public:
    // Previous Smaller or Equal Element
    vector<int> prevSmallerEqualEle(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> psee(n, -1);

        for (int i = 0; i < n; i++) {

            // Remove only strictly greater elements.
            // Equal elements are kept to handle duplicates correctly.
            // e.g 1,1 ans should be 3 but we not include only strictly greater it will come 
            // as 4 which is wrong as it will treat 1,1 two time instead of one
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return psee;
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

    int sumSubarrayMins(vector<int>& arr) {
        const long long MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> psee = prevSmallerEqualEle(arr, n);
        vector<int> nse = nextSmallerEle(arr, n);

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;

            // Number of subarrays where arr[i] is the minimum.
            long long currSum = ((left % MOD) * (right % MOD)) % MOD;
            currSum = (currSum * (arr[i] % MOD)) % MOD;

            sum = (sum + currSum) % MOD;
        }

        return sum;
    }
};