//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    
    //using stack --> O(n) T.C and S.C
    queue<int> rev(queue<int> q)
    {
        stack<int>st;
        
        while(!q.empty()){
            int frontElement = q.front();
            q.pop();
            st.push(frontElement);
        }
        while(!st.empty()){
            int topElement = st.top();
            st.pop();
            q.push(topElement);
        }
        return q;
        
        //function call of recursive solution;
        //  rev1(q);
        //  return q;
    }
    void rev1(queue<int> &q)
    {
        //base case
        if(q.empty()){
            return;
        }
        int frontElement = q.front();
        q.pop();
        
        
        rev1(q);
        q.push(frontElement);
        
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends