//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        int n = arr.size();
        int curSum = 0;            // Current subarray sum
        int maxSum = INT_MIN;      // Maximum subarray sum found
        int start = 0, end = 0;    // Indices of the maximum sum subarray
        int tempStart = 0;         // Temporary start index for tracking subarrays
        bool allNegative = true;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] >=0) allNegative = false;
            
            if(arr[i] < 0) { // Reset sum when encountering a negative number
                curSum = 0;
                tempStart = i + 1;
            }
            
            curSum += arr[i];      // Add current element to sum
            
            if(curSum >= maxSum) {  // Update max sum and subarray indices
                maxSum = curSum;
                start = tempStart;
                end = i;
            }
            
            if(curSum < 0) {       // Reset sum if it becomes negative
                curSum = 0;
                tempStart = i + 1;
            }
        }
        
         // Handle case where all elements are negative
        if(allNegative){
            return {-1};
        }

        return vector<int>(arr.begin() + start, arr.begin() + end + 1);
    }
};


//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from the input string

        Solution obj;
        vector<int> result = obj.findSubarray(a);

        // Print the result in the required format
        if (result.empty()) {
            cout << "[]"; // Print empty brackets if no non-negative subarray is found
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << "\n~\n"; // Ensure a new line after each test case output
    }

    return 0;
}

// } Driver Code Ends