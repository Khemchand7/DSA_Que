//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
  bool isPossibleSolution(int n, int arr[], int m, int sol){
      int c=1;//c is initialized to 1 because we are considering the first student initially. As we iterate through the books, we increment c whenever we need to assign books to a new student because the current sum of pages exceeds sol. This ensures that we correctly count the number of students required for the current solution.
      int pageSum=0;
      for(int i=0;i<n;i++){
          if(sol<arr[i]) return false;//If sol (current solution's maximum page limit) is less than the number of pages in the current book, return false since it's not possible to assign this book to any student.
          
          if(pageSum+arr[i]>sol){//If adding the current book's pages to pageSum exceeds sol, increment the student count c, reset pageSum to the current book's pages.
              c++;
              pageSum=arr[i];// Assign the current book to the new student
              if(c>m) return false;// If students exceed m, return false
          }
          else{
              pageSum+=arr[i];//ssame student ko hi books assign ho rhi hai yahan
          }
      }
      return true;
  }
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(m>n) return -1;// If there are more students than books, return -1
        int start=0;
        int end=accumulate(arr,arr+n,0); //start , end and initial sum // The upper bound is the total sum of all pages
        long long  mid=start+(end-start)/2;
        long long  ans=-1;
        while(start<=end){
            if(isPossibleSolution( n, arr, m, mid)){
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

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
