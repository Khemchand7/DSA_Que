//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    bool isPossibleSolution(int arr[], int n, int k, long long sol){
        int c=1;
        int timeSum=0;
        for(int i=0;i<n;i++){
            if(arr[i]>sol) return false;
            if(arr[i]+timeSum>sol){
                c++;
                timeSum=arr[i];
                if(c>k) return false;
            }
            else{
                timeSum+=arr[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long start=0;
        long long end=0;
        for(int i=0;i<n;i++){
            end+=arr[i];
        }
        long long mid=start+(end-start)/2;
        long long ans=-1;
        while(start<=end){
            if(isPossibleSolution(arr,n,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends