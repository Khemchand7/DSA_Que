//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to rotate the array elements by one position to the right
    void rotate(vector<int> &arr) {
        // Store the last element of the array in a temporary variable
        int temp = arr[arr.size() - 1];
        
        // Shift elements to the right by one position, starting from the end
        // agar left to right jaenge to sab me starting wala element aa jaega
        for (int i = arr.size() - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        
        // Place the last element at the first position
        arr[0] = temp;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        ob.rotate(arr);
        for (long long i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends