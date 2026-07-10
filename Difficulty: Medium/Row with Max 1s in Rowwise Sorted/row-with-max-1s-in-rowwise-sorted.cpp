class Solution {
public:
    int firstOccurance(vector<int> array, int target, int n) {
        int start = 0;
        int end = n - 1;
        int first = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (array[mid] == target) {
                first = mid;
                end = mid - 1;      // Search on left
            }
            else if (array[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return first;
    }

    int rowWithMax1s(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        int maxOneCount = 0;
        int row = -1;

        for (int i = 0; i < n; i++) {
            int first = firstOccurance(arr[i], 1, m);

            int oneCount = 0;
            if (first != -1)
                oneCount = m - first;

            if (oneCount > maxOneCount) {
                maxOneCount = oneCount;
                row = i;
            }
        }

        return row;
    }
};