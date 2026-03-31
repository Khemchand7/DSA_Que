class Solution {
  public:
  
  int solveRec(vector<int>& arr, int target, int index){
      if(target == 0) return 1;
      if(index >= arr.size() || target < 0) return 0;
     
      int include = solveRec(arr, target - arr[index], index+1 );
      int exclude = solveRec(arr, target, index+1 );
      return (include || exclude);
  }
  
  int solveMem(vector<int>& arr, int target, int index, vector<vector<int>> &dp){
      if(target == 0) return 1;
      if(index >= arr.size() || target < 0) return 0;
      
      if(dp[index][target] != -1) return dp[index][target];
     
      int include = solveMem(arr, target - arr[index], index+1, dp );
      int exclude = solveMem(arr, target, index+1, dp );
      return dp[index][target] = (include || exclude);
  }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
       int n = arr.size();
       int index = 0;
       
       //int totalSum = accumulate(arr.begin(), arr.end(), 0);
       
       //int target = totalSum >> 1;
       
       vector<vector<int>> dp(n+1, vector<int>(sum + 1,-1));
       
       //int ans = solveRec(arr, sum, index);
       int ans = solveMem(arr, sum, index, dp);
       
       return ans;
        
    }
};