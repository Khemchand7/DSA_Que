class Solution {
public:

    int solveDP(int n , vector<int>& dp){

        if(n == 0){
            return 1;                // one valid way: already at step 0
        }

        if(n < 0){
            return 0;                // invalid path
        }

        if(dp[n] != -1){
            return dp[n];            // return memoized result
        }
        
        int oneStep = solveDP(n-1, dp);  // take 1 step
        int twoStep = solveDP(n-2, dp);  // take 2 steps
        
        int ans = (oneStep + twoStep); // total ways from both choices
        dp[n] = ans;                         // store result

        return ans;
    }

    int solveTabulation(int n){
        vector<int> dp(n+1,0);

        dp[0] = 1;                    // base case: one way to stay at step 0

        for(int i = 1; i <= n; i++){
            
            int oneStep = dp[i-1];    // ways reaching from i-1
            
            int twoStep = 0;
            if(i > 1) 
                twoStep = dp[i-2];    // ways reaching from i-2
            
            int ans = (oneStep + twoStep); // combine both transitions
            dp[i] = ans;                          // store ways to reach step i
        }

        return dp[n];                // final answer
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);   // memoization array

         return solveDP(n, dp);    // top-down DP
        //return solveTabulation(n);   // bottom-up DP
    }
};