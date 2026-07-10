class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        // Treat the 2D matrix as a single sorted 1D array
        int n = row * col;

        int start = 0;
        int end = n - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            // Convert 1D index back to 2D coordinates
            int rowIndex = mid / col;
            int colIndex = mid % col;

            int currNumber = matrix[rowIndex][colIndex];

            if(currNumber == target)
                return true;

            // Search in the left half
            else if(currNumber > target)
                end = mid - 1;

            // Search in the right half
            else
                start = mid + 1;
        }

        return false;
    }
};

/*
Dry Run:

Matrix:
1  3  5  7
10 11 16 20
23 30 34 60

Target = 16

Virtual 1D array: --> it is possible bcs first ele of  next row is > last row ele
Index : 0  1  2  3  4  5  6  7  8  9 10 11
Value : 1  3  5  7 10 11 16 20 23 30 34 60

Iteration 1:
start = 0, end = 11
mid = 5
row = 5 / 4 = 1
col = 5 % 4 = 1
matrix[1][1] = 11
11 < 16 → Search right half

Iteration 2:
start = 6, end = 11
mid = 8
row = 8 / 4 = 2
col = 8 % 4 = 0
matrix[2][0] = 23
23 > 16 → Search left half

Iteration 3:
start = 6, end = 7
mid = 6
row = 6 / 4 = 1
col = 6 % 4 = 2
matrix[1][2] = 16
Target found.
*/

/*
Time Complexity  : O(log(row * col))
Space Complexity : O(1)
*/