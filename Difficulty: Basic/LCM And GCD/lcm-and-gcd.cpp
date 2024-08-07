//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long gcdOfAandB(long long A , long long B){
        if(A==0) return B;
        if(B==0) return A;
        while(A>0 && B>0){
            if(A>B) A=A-B;
            else B=B-A;
        }
        return A?A:B;
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // LCM(A,B) * GCD(A,B) = A * B;
        //LCM(A,B) =  (A*B)/GCD(A,B)
        
        vector<long long> ans;
        long long gcd = gcdOfAandB(A,B);
        long long lcm = (A*B) / gcd;
        ans.push_back(lcm);
        ans.push_back(gcd);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends