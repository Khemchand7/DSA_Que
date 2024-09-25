//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void insertAtBottomHelper(stack<int> &st,int x){
        //base case
        if(st.empty()){
            st.push(x);
            return;
        }
        //ek case solve 
        int temp = st.top();
        st.pop();
        //recursive call
        insertAtBottomHelper(st,x);
        //backtracking
        st.push(temp);
        
    }
    stack<int> insertAtBottom(stack<int> st,int x){
        //copying 1 stack into other but not necessary as in insertAtBottom function stack is passed by value not by reference
        // stack<int> st1(st);
        insertAtBottomHelper(st, x);
        return st;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends