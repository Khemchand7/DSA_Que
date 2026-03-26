class Solution {
public:
    int solveRec(int n, int k, int target){
        if(n < 0 || target < 0){
            return 0;
        }

        if(n == 0 && target == 0){
            return 1;
        }
        
        int ans = 0;

        for(int i = 1; i <=k; i++){
            ans += solveRec(n-1, k, target - i);
        }

        return ans;
    }

    int solveMem(int n, int k, int target, vector<vector<int> >& dp){
        const int MOD = 1e9 + 7;

        if(n < 0 || target < 0){
            return 0;
        }

        if(n == 0 && target == 0){
            return 1;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }
        
        int ans = 0;

        for(int i = 1; i <=k; i++){
            ans = (ans + solveMem(n-1, k, target - i, dp)) % MOD;
        }

        dp[n][target] = ans;

        return ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        
        //int ans = solveRec(n, k, target);
        vector<vector<int> > dp(n + 1, vector<int>(target + 1,-1));
        int ans = solveMem(n, k, target, dp);
        return ans;
    }
};