/* 
Logic:
- Perform binary search on columns.
- For each middle column, find its maximum element.
- Compare it only with its left and right neighbors as we already have max of col 
- If it is greater than both, it is a peak.
- Otherwise, move towards the larger neighbor since a peak is guaranteed in that direction.
 */

class Solution {
public:
    int getMaxRowIndex(vector<vector<int>>& mat, int col, int n){
        int maxValue = INT_MIN;
        int row = -1;

        // Find the row having the maximum element in the current column
        for(int i = 0; i < n; i++){
            if(mat[i][col] > maxValue){
                maxValue = mat[i][col];
                row = i;
            }
        }
        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int start = 0;
        int end = m - 1;

        // Binary search on columns
        while(start <= end){
            int mid = start + (end - start)/2;

            // Get the row containing the maximum element in the middle column
            int maxRowIndex = getMaxRowIndex(mat, mid, n);

            // Treat out-of-bound neighbors as -1
            int left = (mid - 1 >= 0) ? mat[maxRowIndex][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxRowIndex][mid + 1] : -1;

            // Found a peak element
            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
                return {maxRowIndex, mid};

            // Peak must exist on the left side
            else if(mat[maxRowIndex][mid] < left)
                end = mid - 1;

            // Peak must exist on the right side
            else
                start = mid + 1;
        }

        return {-1, -1};
    }
};

/*
Time Complexity: O(n * log m)
- Finding the maximum element in a column takes O(n).
- Binary search runs for O(log m) columns.

Space Complexity: O(1)
*/