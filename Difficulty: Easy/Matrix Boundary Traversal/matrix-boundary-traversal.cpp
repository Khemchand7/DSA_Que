//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to return list of integers that form the boundary
    // traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int>>& mat) {
        int n = mat.size();           // Number of rows
        int m = mat[0].size();        // Number of columns
        vector<int> ans;

        int i = 0;                    // Row index
        int j = 0;                    // Column index

        // Traverse top row (left to right)
        for(int k = 1; k < m; k++) {
            ans.push_back(mat[i][j]);
            j++;
        }

        // Traverse right column (top to bottom)
        for(int k = 1; k < n; k++) {
            ans.push_back(mat[i][j]);
            i++;
        }

        // Traverse bottom row (right to left)
        for(int k = 1; k < m; k++) {
            ans.push_back(mat[i][j]);
            j--;
        }

        // Traverse left column (bottom to top)
        for(int k = 1; k < n; k++) {
            ans.push_back(mat[i][j]);
            i--;
        }

        return ans;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends