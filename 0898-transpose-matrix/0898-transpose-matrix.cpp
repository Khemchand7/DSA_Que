class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();        // Number of rows in the original matrix
        int m = matrix[0].size();    // Number of columns in the original matrix

        vector<vector<int>> result;   // Result matrix to store the transpose
        
        for(int j = 0; j < m; j++) {
            vector<int> temp;         // Temporary vector to store the current row of the transposed matrix
            for(int i = 0; i < n; i++) {
                temp.push_back(matrix[i][j]);  // Add the element at (i, j) to the temporary vector
            }
            result.push_back(temp);   // Add the temporary vector as a row to the result matrix
        }
        
        return result;  // Return the transposed matrix
    }
};