//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        int start = 0;
        int end = arr.size()-1;
        int mid = start +(end-start)/2;
        int temp =0;
        while(start<=end){
           if(arr[mid] == 1){
               start = mid+1;
           }
           else{
              temp = mid;//store the first position of zero
               end = mid-1;
           }
           mid = start +(end-start)/2;
        }
        int zeros = arr.size()-temp;
        return zeros;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.countZeroes(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends