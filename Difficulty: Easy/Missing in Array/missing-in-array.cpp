//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        // Calculate the expected number of elements (n) including the missing one
        int n = arr.size() + 1;
        
        // Calculate the sum of the first n natural numbers
        int expectedSum = n * (n + 1) / 2;
        
        // Initialize sum to hold the sum of elements in the array
        int sum = 0;
        
        // Sum up all elements in the array
        for (auto num : arr) {
            sum += num;
        }
        
        // The missing number is the difference between expectedSum and sum
        int missingNumber = expectedSum - sum;
        return missingNumber;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNumber(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends