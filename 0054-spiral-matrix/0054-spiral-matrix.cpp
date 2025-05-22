class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();         // Number of rows in the matrix
        int m = matrix[0].size();      // Number of columns in the matrix
        vector<int> ans;

        // Define the boundaries of the matrix
        int sRow = 0, sCol = 0;        // Starting row and column
        int eRow = n - 1, eCol = m - 1; // Ending row and column

        // Loop until the starting boundaries cross the ending boundaries
        while (sRow <= eRow && sCol <= eCol) {
            // Traverse the top row from left to right
            for (int j = sCol; j <= eCol; j++) {
                ans.push_back(matrix[sRow][j]);
            }

            // Traverse the right column from top to bottom
            for (int i = sRow + 1; i <= eRow; i++) {
                ans.push_back(matrix[i][eCol]);
            }

            // Traverse the bottom row from right to left (only if there's more than one row left)
            for (int j = eCol - 1; j >= sCol; j--) {
                if (sRow == eRow) {
                    break;  // Avoid duplicate row
                }
                ans.push_back(matrix[eRow][j]);
            }

            // Traverse the left column from bottom to top (only if there's more than one column left)
            for (int i = eRow - 1; i >= sRow + 1; i--) {
                if (sCol == eCol) {
                    break;  // Avoid duplicate column
                }
                ans.push_back(matrix[i][sCol]);
            }

            // Move the boundaries inward
            sRow++;
            sCol++;
            eRow--;
            eCol--;
        }

        return ans;
    }
};
