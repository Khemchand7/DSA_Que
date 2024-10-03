//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Helper function to find previous smaller elements
    void prevSmallerElement(int arr[], int n, vector<int>& ans) {
        stack<int> st;
        st.push(-1);  // Push -1 to handle cases with no smaller element
        
        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            
            // Pop elements from the stack while they are greater than or equal to the current element
            while (st.top() >= curr) {
                st.pop();
            }
            
            // The top of the stack is the previous smaller element, or -1 if none exists
            ans[i] = st.top();
            
            // Push the current element to the stack for future comparisons
            st.push(curr);
        }
    }

    // Function to return the list of previous smaller elements for each array element
    vector<int> leftSmaller(int n, int a[]) {
        vector<int> ans(n);  // Create a vector to store the result
        prevSmallerElement(a, n, ans);  // Fill the result vector with previous smaller elements
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends