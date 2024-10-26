//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans; // Result vector to store the repeating and missing numbers
        
        // First loop: Mark elements as visited by negating the value at their respective index
        for(int i = 0; i < n; i++) {
            int index = abs(arr[i]); // Get the absolute value to ignore already negated values
            
            // Check if the element at (index - 1) is positive
            if(arr[index - 1] > 0) {
                arr[index - 1] *= -1; // Negate it to mark it as visited
            }
            else {
                // If the element is already negative, it means this number is repeated
                ans.push_back(abs(arr[i])); // Add the repeating number to the result
            }
        }
        
        // Second loop: Identify the missing element
        for(int i = 0; i < n; i++) {
            // If a value is positive, it means the index + 1 (element) was never visited
            if(arr[i] > 0) {
                ans.push_back(i + 1); // Add the missing number (index + 1) to the result
            }
        }
        
        // Return the result containing the repeating and missing elements
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends