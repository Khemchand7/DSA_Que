//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
        int carry = 0;
        string ans;
        int i = n-1;
        int j = m-1;
        //flow of code: sabse pehle ist loo chalegi jab tak i and j both are 0 or greater than 0
        //uske bad jab last wali digit hogi jisme ya to a zero hoga ya b to usko alag se handle kia hai 
        
        while(i>=0 && j>=0){//when both the digits are of equal in length
            int x = a[i] + b[j] + carry;
            int digit = x % 10;
            ans.push_back(digit + '0');
            carry=x / 10;
            i--,j--;
        }
        
        while(j>=0){//written the code explictily for the case when a[i]==0
            int x = 0 + b[j] + carry;
            int digit = x % 10;
            ans.push_back(digit + '0');
            carry=x / 10;
            j--;
        }
        while(i>=0){//written the code explicitly for the case when b[j]==0
            int x = a[i] + 0 + carry;
            int digit = x % 10;
            ans.push_back(digit + '0');
            carry=x / 10;
            i--;
        }
        if(carry){//last me carry backi hogi to usko bhi string me add karna hoga
            ans.push_back(carry + '0');
        }
        while(ans[ans.size()-1]=='0'){//last me jab trainiling 0 hogi to reverse karne pr wo 0009562 aisa show karega jabki ans 9562 sirf yeh hona chaie islie last wali 0 pop kar rhe hai 
        //agar iska return type int hota to yeh step karne ki jarurat nhi padti
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());//last se loop chala rhe hahi to string me ans reverse order me hai to return karne se pehle usko reverse karna padega
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}
// } Driver Code Ends