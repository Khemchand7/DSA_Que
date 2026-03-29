class Solution {
public:
    int solveRec(string str1, string str2, int i, int j){
        if(i == str1.length() || j == str2.length())
            return 0;

        int ans = 0;
        if(str1[i] == str2[j])
            ans = 1 + solveRec(str1, str2, i+1, j+1);

        else
            ans = 0 + max(solveRec(str1, str2, i+1, j), solveRec(str1, str2, i, j+1) );

        return ans;
    }

    int solveMem(string &str1, string &str2, int i, int j, vector<vector<int> > &dp){
        if(i == str1.length() || j == str2.length())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(str1[i] == str2[j])
            ans = 1 + solveMem(str1, str2, i+1, j+1, dp);

        else
            ans = 0 + max(solveMem(str1, str2, i+1, j, dp), solveMem(str1, str2, i, j+1, dp) );

        dp[i][j] = ans;
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        vector<vector<int> > dp( text1.length() + 1, vector<int> (text2.length()+1, -1));

        //return solveRec(text1, text2, i, j);
        return solveMem(text1, text2, i, j, dp);
    }
};