class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();       // Get the number of rows in the matrix
        int col = matrix[0].size();     // Get the number of columns in the matrix
        
        // Step 1: Transpose the matrix (swap elements symmetrically along the diagonal)
        for(int i = 0; i < row; i++) {
            for(int j = i; j < col; j++) {
                swap(matrix[i][j], matrix[j][i]);  // Swap element at (i, j) with (j, i)
            }
        }
        
        // Step 2: Reverse each row to get the final rotated matrix
        for(int i = 0; i < row; i++) {
            reverse(matrix[i].begin(), matrix[i].end());  // Reverse each row to rotate by 90 degrees
        }
    }
};
