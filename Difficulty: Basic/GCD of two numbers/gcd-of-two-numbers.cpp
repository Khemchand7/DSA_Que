//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int gcd(int a, int b) {
        if(a==0) return b;
        
        if(b==0) return a;
        
        while(a>0 && b>0){
            if(a>b) a= a-b;
            else b=b-a;
        }
        return a?a:b;
    }
};
// Logic gcd(a,b) = gcd(a-b,b) if a > b; 
//               = gcd(a,b-a) if b > a;

// dry run gcd(48,24)=gcd(48-24,24)\
//                   =gcd(24,24)
//                   =gcd(24-24,24)
//                   =gcd(0,24)


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.gcd(a, b);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends