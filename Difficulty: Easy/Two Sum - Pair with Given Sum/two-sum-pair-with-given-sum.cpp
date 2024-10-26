//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // Sort the array to enable the two-pointer approach
        sort(arr.begin(), arr.end());
        
        // Get the size of the array
        int n = arr.size();
        
        // Initialize two pointers, one at the beginning and one at the end of the sorted array
        int start = 0;
        int end = n - 1;
        
        // Loop through the array until the pointers meet
        while(start<end) {
            // Check if the sum of elements at the two pointers equals the target
            if(arr[start] + arr[end] == target) 
                return true; // If so, return true as a pair was found
            
            // If the sum is less than the target, increment the start pointer to increase the sum
            else if(arr[start] + arr[end] < target) 
                start++;
            
            // If the sum is greater than the target, decrement the end pointer to decrease the sum
            else 
                end--;
        }
        
        // Return false if no such pair is found
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--) {
        int x;
        cin >> x;
        cin.ignore(); // To discard any leftover newline characters

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends