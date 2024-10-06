//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   vector<int> rearrangeQueue(queue<int> &q) {
    // Create an auxiliary queue to hold the first half of the elements.
    queue<int> q2;
    
    // Get the size of the original queue.
    int size = q.size();
    
    // Move the first half of the elements from q to q2.
    for (int i = 0; i < size / 2; i++) {
        int frontElement = q.front();  // Get the front element of q.
        q.pop();                       // Remove the front element from q.
        q2.push(frontElement);         // Push the front element to q2.
    }

    // Interleave elements from q2 (first half) and q (second half).
    for (int i = 0; i < size / 2; i++) {
        int firstElement = q2.front(); // Get the front element from q2 (first half).
        q2.pop();                      // Remove it from q2.
        q.push(firstElement);          // Push the first half element back to q.
        
        int secondElement = q.front(); // Get the front element from q (second half).
        q.pop();                       // Remove the front element from q.
        q.push(secondElement);         // Push the second half element back to q.
    }

    // Prepare a vector to store the final rearranged queue elements.
    vector<int> ans;
    
    // Move all elements from q to the vector.
    while (!q.empty()) {
        ans.push_back(q.front());      // Add the front element of q to the vector.
        q.pop();                       // Remove the element from q.
    }

    // Return the final vector containing the rearranged elements.
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
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends