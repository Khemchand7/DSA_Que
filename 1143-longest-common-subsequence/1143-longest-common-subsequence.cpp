class Solution {
public:
    int solveRec(string str1, string str2, int i, int j){
        // base case: if any string finishes, no subsequence possible
        if(i == str1.length() || j == str2.length())
            return 0;

        int ans = 0;

        // if characters match, include them in subsequence
        if(str1[i] == str2[j])
            ans = 1 + solveRec(str1, str2, i+1, j+1);

        else
            // try skipping character from either string
            ans = 0 + max(solveRec(str1, str2, i+1, j), solveRec(str1, str2, i, j+1) );

        return ans;
    }

    int solveMem(string &str1, string &str2, int i, int j, vector<vector<int> > &dp){
        // base case
        if(i == str1.length() || j == str2.length())
            return 0;

        // step1: check if answer already computed
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        // characters match → include in LCS
        if(str1[i] == str2[j])
            ans = 1 + solveMem(str1, str2, i+1, j+1, dp);

        else
            // explore both possibilities
            ans = 0 + max(solveMem(str1, str2, i+1, j, dp), solveMem(str1, str2, i, j+1, dp) );

        // step2: store answer in dp
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTab(string str1, string str2){
        // step1: create dp array
        vector<vector<int>> dp(str1.length() + 1, vector<int> (str2.length() + 1, 0) );

        // step3: reverse flow of recursion
        for( int i = str1.length()-1; i >=0; i-- ){
            for(int j = str2.length()-1; j >=0; j-- ){

                int ans = 0;

                // characters match → move diagonally
                if(str1[i] == str2[j])
                    ans = 1 + dp[i+1][j+1];

                else
                    // take best by skipping either char
                    ans = 0 + max(dp[i+1][j], dp[i][j+1] );

                dp[i][j] = ans; // store result
            }
        }

        // answer for full strings
        return dp[0][0];
    }

    int solveTabSO(string str1, string str2){
        // space optimization: only two rows needed
        vector<int> curr(str2.length() + 1, 0);
        vector<int> next(str2.length() + 1, 0);

        for( int i = str1.length()-1; i >=0; i-- ){
            for(int j = str2.length()-1; j >=0; j-- ){

                int ans = 0;

                // characters match
                if(str1[i] == str2[j])
                    ans = 1 + next[j+1];

                else
                    // next[j] → dp[i+1][j], curr[j+1] → dp[i][j+1]
                    ans = 0 + max(next[j], curr[j+1] );

                curr[j] = ans;
            }

            // move current row to next row
            next = curr;
        }

        // final answer
        return curr[0];
    }

    int longestCommonSubsequence(string text1, string text2) {

        int i = 0;
        int j = 0;

        // dp for memoization
        vector<vector<int> > dp( text1.length() + 1, vector<int> (text2.length()+1, -1));

        //return solveRec(text1, text2, i, j);
        //return solveMem(text1, text2, i, j, dp);
        //return solveTab(text1, text2);

        // optimized tabulation
        return solveTabSO(text1, text2);
    }
};