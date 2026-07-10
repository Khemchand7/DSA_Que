/* 
Logic:
- From the top-right corner:
  • Left elements are smaller.
  • Bottom elements are larger.
- If current > target, move left.
- If current < target, move down.
- This discards one entire row or column in every iteration.
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Start from the top-right corner
        int i = 0;
        int j = m - 1;

        // Eliminate one row or one column in each step
        while(i < n && j >= 0){
            if(matrix[i][j] == target)
                return true;

            // Current element is too large, move left
            else if(matrix[i][j] > target)
                j--;

            // Current element is too small, move down
            else
                i++;
        }

        return false;
    }
};

/*
Time Complexity: O(n + m)
Space Complexity: O(1)
*/