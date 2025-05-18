//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        int n = arr.size();
        int winSize = 0; // Number of good elements (≤ k)
        int m = 0;       // Count of bad elements (> k) in current window
        int minSwap = 0;

        // Count total good elements to determine window size
        for(int i = 0; i < n; i++) {
            if(arr[i] <= k) winSize++;
        }

        // Count bad elements in the first window
        for(int i = 0; i < winSize; i++) {
            if(arr[i] > k) m++;
        }

        minSwap = m; // Initial minimum swaps with no. of swap required in ist window

        int s = 1, e = winSize;

        // Slide the window
        while(e < n) {
            // Bad enters, good exits
            if(arr[s - 1] <= k && arr[e] > k) m++;

            // Good enters, bad exits
            else if(arr[s - 1] > k && arr[e] <= k) m--;

            minSwap = min(minSwap, m);
            s++;
            e++;
        }

        return minSwap;
    }
};




//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.minSwap(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends