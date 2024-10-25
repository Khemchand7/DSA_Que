//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int DiagonalSum(vector<vector<int> >& matrix) {
        int row = matrix.size();              // Get the number of rows in the matrix
        int col = matrix[0].size();           // Get the number of columns in the matrix
        int sum = 0;                          // Initialize the sum variable

        // Loop through each row in the matrix
        for(int i = 0; i < row; i++) {
            // Loop through each column in the matrix
            for(int j = 0; j < col; j++) {
                // If it's a primary diagonal element (where row index equals column index)
                if(i == j) sum += matrix[i][j];
                
                // If it's a secondary diagonal element (where row + column index equals to no. of col-1)
                if((i + j) == col - 1) sum += matrix[i][j];
            }
        }

        return sum; // Return the sum of primary and secondary diagonal elements
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.DiagonalSum(matrix);
		cout << ans <<'\n';
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends