class Solution {
public:
    /* int solveRec(vector<int>& prices, int idx, int buy, int cap){
        // base case: no days left OR no transactions left
        if(idx >= prices.size() || cap == 0) return 0;

        int profit = 0;

        if(buy){
            // option1: buy stock -> money spent so negative
            // transaction not completed yet, so cap stays same
            int buyStock = -prices[idx] + solveRec(prices, idx + 1, 0, cap);

            // option2: skip this day
            int skip = solveRec(prices, idx + 1, 1, cap);

            profit = max(buyStock,skip);
        }
        else{ // sell state
            // option1: sell stock -> transaction completed so cap--
            int sellStock = prices[idx] + solveRec(prices, idx + 1, 1, cap - 1);

            // option2: skip selling today
            int skip = solveRec(prices, idx + 1, 0, cap);

            profit = max(sellStock, skip);
        }

        return profit;
    } */

    /* int solveMem(vector<int>& prices, int idx, int buy, int cap, vector<vector<vector<int>>> &dp){
        if(idx >= prices.size() || cap == 0) return 0;

        // return already computed result
        if(dp[idx][buy][cap] != -1){
            return dp[idx][buy][cap];
        }

        int profit = 0;

        if(buy){
            int buyStock = -prices[idx] + solveMem(prices, idx + 1, 0, cap, dp);
            int skip = solveMem(prices, idx + 1, 1, cap, dp);
            profit = max(buyStock,skip);
        }
        else{ // sell state
            int sellStock = prices[idx] + solveMem(prices, idx + 1, 1, cap - 1, dp);
            int skip = solveMem(prices, idx + 1, 0, cap, dp);
            profit = max(sellStock, skip);
        }

        // store computed result
        dp[idx][buy][cap] = profit;

        return dp[idx][buy][cap];
    } */

    /* int solveTab(vector<int>& prices){
        int n = prices.size();

        // dp[idx][buy][cap]
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(3,0)));

        // fill table from last day to first
        for(int idx = n-1; idx >=0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <=2; cap++){

                    int profit = 0;

                    if(buy){
                        // buy stock
                        int buyStock = -prices[idx] + dp[idx + 1][0][cap];

                        // skip buying
                        int skip = dp[idx + 1][1][cap];

                        profit = max(buyStock,skip);
                    }
                    else{ // sell state

                        // sell stock -> transaction finished
                        int sellStock = prices[idx] + dp[idx + 1][1][cap-1];

                        // skip selling
                        int skip = dp[idx + 1][0][cap];

                        profit = max(sellStock, skip);
                    }

                    dp[idx][buy][cap] = profit;
                }
            }
        }

        // start from day 0, buy allowed, 2 transactions available
        return dp[0][1][2];
    } */

    int solveTabSO(vector<int>& prices){
        int n = prices.size();

        // space optimized DP (only next row needed)
        vector<vector<int>>curr(2,vector<int>(3,0));
        vector<vector<int>>next(2,vector<int>(3,0));

        for(int idx = n-1; idx >=0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <=2; cap++){

                    int profit = 0;

                    if(buy){
                        int buyStock = -prices[idx] + next[0][cap];
                        int skip = next[1][cap];
                        profit = max(buyStock,skip);
                    }
                    else{ // sell state
                        int sellStock = prices[idx] + next[1][cap-1];
                        int skip = next[0][cap];
                        profit = max(sellStock, skip);
                    }

                    curr[buy][cap] = profit;
                }
            }

            // move current row to next for next iteration
            next = curr;
        }

        // final answer
        return curr[1][2];
    }

    int maxProfit(vector<int>& prices) {
        // int n = prices.size();

        // recursion start state
        // idx = 0, buy allowed = 1, max transactions = 2

        // int ans = solveRec(prices,idx, buy, cap);
        // int ans = solveMem(prices,idx, buy, cap, dp);
        // int ans = solveTab(prices);

        int ans = solveTabSO(prices);

        return ans;
    }
};