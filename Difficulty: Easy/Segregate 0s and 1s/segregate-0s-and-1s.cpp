//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // Initialize two pointers: s (start) and e (end)
        int s = 0;
        int e = arr.size() - 1;
        
        // Loop until the two pointers meet
        while (s < e) {
            // Move the 's' pointer to the right as long as arr[s] is 0
            while (s < e && arr[s] == 0) {
                s++;
            }
            
            // Move the 'e' pointer to the left as long as arr[e] is 1
            while (s < e && arr[e] == 1) {
                e--;
            }
            
            // If arr[s] is 1 and arr[e] is 0, swap them
            if (arr[s] == 1 && arr[e] == 0) {
                swap(arr[s], arr[e]);
            }
        }
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
        int n = arr.size();
        Solution ob;
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends