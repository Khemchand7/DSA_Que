//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
void deleteMidHelper(stack<int>& s, int pos) {
    // Base case: If position is 1, we remove the middle element
    if (pos == 1) {
        s.pop();
        return;
    }
    
    // Store the top element and remove it temporarily
    int temp = s.top();
    s.pop();
    
    // Recursive call for the next position
    deleteMidHelper(s, pos - 1);
    
    // Push the stored element back after the middle element is removed
    s.push(temp);
}

// Function to delete the middle element of a stack.
void deleteMid(stack<int>& s, int sizeOfStack) {
    int pos = (sizeOfStack / 2) + 1; // Middle element for both even and odd sizes
    deleteMidHelper(s, pos);
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends