//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int firstOccurance(int arr[], int n, int target){
  int start=0;
  int end=n-1;
  int ans=-1;
  int mid = start + (end-start)/2;
  while(start<=end){
    if(arr[mid]==target){
      // answer ko store karna hai 
      ans=mid;
      //left me jaana hai 
      end=mid-1;

    }
    else if(arr[mid]>target){
      //left me jao 
      end=mid-1;
    }
    else if(arr[mid]<target){
      //right me jao 
      
      start=mid+1;
    }
    //modify mid 
    mid = start + (end-start)/2;
  }
  return ans;
}
int lastOccurance(int arr[], int n, int target){
  int start=0;
  int end=n-1;
  int ans=-1;
  int mid = start + (end-start)/2;
  while(start<=end){
    if(arr[mid]==target){
      // answer ko store karna hai 
      ans=mid;
      //right  me jaana hai 
      start=mid+1;

    }
    else if(arr[mid]>target){
      //left me jao 
      end=mid-1;
    }
    else if(arr[mid]<target){
      //right me jao 
      start=mid+1;
    }
    //modify mid 
    mid = start + (end-start)/2;
  }
  return ans;
}

	
	int count(int arr[], int n, int x) {
	    int firstIndex= firstOccurance(arr, n, x);
  int lastIndex= lastOccurance(arr, n, x);
  int totalOccurance=lastIndex-firstIndex+1;
  if(firstIndex==-1 && lastIndex==-1){
      return 0;
  }
  else{
      return totalOccurance;
  }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends