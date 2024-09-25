//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insertAtBottom(stack<int> &st,int x){
        //base case
        if(st.empty()){
            st.push(x);
            return;
        }
        //ek case solve
        int temp = st.top();
        st.pop();
        //recursive call
        insertAtBottom(st,x);
        //backtracking
        st.push(temp);//yahan pr temp ko insert karana hai na ki x ko mistake hui bar bar
    }
    void Reverse(stack<int> &St){
        if(St.empty()){
            return;
        }
        //ek case solve
        int x = St.top();
        St.pop();
        //recursive call
        Reverse(St);
        //backtracking
        insertAtBottom(St,x);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends