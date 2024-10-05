//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse the first 'k' elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        
        // Step 1: Create a stack to temporarily hold the first 'k' elements of the queue.
        stack<int> st;
        
        // Step 2: Remove the first 'k' elements from the queue and push them onto the stack.
        for(int i = 0; i < k; i++){
            int frontElement = q.front();
            q.pop();   
            st.push(frontElement);
        }
        
        // Step 3: Now the stack has the first 'k' elements in reverse order.
        // Pop all elements from the stack and push them back into the queue.
        while(!st.empty()){
            int topElement = st.top();
            st.pop();              
            q.push(topElement);        
        }
        
        // Step 4: The first 'k' elements are now reversed in the queue, but the rest of the elements
        // are in their original order. Now we need to move the remaining 'n-k' elements 
        // (i.e., those after the first 'k' elements) to the back of the queue.
        int n = q.size();  // 'n' holds the updated size of the queue after reversing 'k' elements.
        for(int i = 0; i < n - k; i++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
        
        // Return the modified queue with the first 'k' elements reversed.
        return q;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends