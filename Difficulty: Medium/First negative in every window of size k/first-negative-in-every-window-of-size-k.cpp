//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    // Deque to store indices of negative numbers in the current window
    deque<long long int> dq;
    
    // Vector to store the result, i.e., first negative integer in each window
    vector<long long> ans;
    
    // Process the first window of size K
    for(int i = 0; i < K; i++) {
        // If the current element is negative, add its index to the deque
        if(A[i] < 0) {
            dq.push_back(i);
        }
    }
    
    // Check if there is any negative number in the first window
    // If deque is not empty, the front of the deque holds the index of the first negative number
    if(dq.size() > 0) {
        ans.push_back(A[dq.front()]);  // Add the first negative number to the result
    }
    else {
        ans.push_back(0);  // If no negative number, add 0 to the result
    }
    
    // Process the rest of the windows (from index K to N-1)
    for(int i = K; i < N; i++) {
        // Remove elements from the deque that are out of the current window range
        // i - dq.front() >= K means the element at dq.front() is out of the current window
        if(!dq.empty() && (i - dq.front() >= K)) {
            dq.pop_front();  // Remove the element from the deque
        }
        
        // Add the current element (A[i]) to the deque if it is negative
        if(A[i] < 0) {
            dq.push_back(i);  // Push the index of the negative element
        }
        
        // After updating the deque, check if it contains any negative number
        // If deque is not empty, the front holds the index of the first negative number in the current window
        if(dq.size() > 0) {
            ans.push_back(A[dq.front()]);  // Add the first negative number to the result
        }
        else {
            ans.push_back(0);  // If no negative number, add 0 to the result
        }
    }
    
    // Return the result vector containing the first negative integer for each window
    return ans;
}
