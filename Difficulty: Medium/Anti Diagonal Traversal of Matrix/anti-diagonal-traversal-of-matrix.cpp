//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    // Helper function to collect one anti-diagonal starting from (row, col)
    void helper(int row, int col, int N, vector<vector<int>> matrix, vector<int>& ans) {
        int i = row, j = col;
        
        // Traverse the anti-diagonal: move down (i++) and left (j--)
        while(i < N && j >= 0) {
            ans.push_back(matrix[i][j]);  // Add current element to result
            i++;
            j--;
        }
    }

    // Main function to return anti-diagonal traversal
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
        int N = matrix.size();  // Matrix is N x N
        vector<int> ans;

        // Traverse starting from each element in the first row
        for(int j = 0; j < N; j++) {
            helper(0, j, N, matrix, ans);
        }

        // Traverse starting from each element in the last column (excluding first row)
        for(int i = 1; i < N; i++) {
            helper(i, N - 1, N, matrix, ans);
        }

        return ans;  // Return collected anti-diagonal elements
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