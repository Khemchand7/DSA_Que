class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int startingRow = 0;
        int endingCol = col - 1;
        int endingRow = row - 1;
        int startingCol = 0;
        int totalElements = row * col;
        int count = 0;
        vector<int> ans;

        while (count < totalElements) {
            // printing starting row
            for (int i = startingCol; i <= endingCol && count < totalElements;
                 i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++; // for handing duplicates ab agli bar next col se
                           // start hoga aur repetition nhi hoga
            // printing ending col
            for (int i = startingRow; i <= endingRow && count < totalElements;
                 i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            // printing ending row
            for (int i = endingCol; i >= startingCol && count < totalElements;
                 i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            // printing starting col
            for (int i = endingRow; i >= startingRow && count < totalElements;
                 i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};