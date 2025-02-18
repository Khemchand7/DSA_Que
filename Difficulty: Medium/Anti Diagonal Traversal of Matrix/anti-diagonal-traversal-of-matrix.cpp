//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    // Helper function to traverse diagonally from (i, j)
    void helper(int i, int j, vector<vector<int>> matrix, vector<int>& result) {
        int n = matrix.size();
        while (i < n && j >= 0) {
            result.push_back(matrix[i][j]); // Add element to result
            i++; 
            j--;
        }
    }

    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
        int n = matrix.size();
        vector<int> result;

        // Traverse diagonals starting from first row
        for (int j = 0; j < n; j++) {
            helper(0, j, matrix, result);
        }

        // Traverse diagonals starting from last column (excluding first row)
        for (int i = 1; i < n; i++) {
            helper(i, n - 1, matrix, result);
        }

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends