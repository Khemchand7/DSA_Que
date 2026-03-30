class Solution {
public:
    int solveRec(string str1, string str2, int i, int j){
        int n = str1.length();
        int m = str2.length();

        if(i == n) return m - j;
        if(j == m) return n - i;

        int ans = 0;
        if(str1[i] == str2[j])
             ans = solveRec(str1, str2, i+1, j+1);
        else{
            int insert = 1 + solveRec(str1, str2, i, j+1);
            int deleted = 1 + solveRec(str1, str2, i+1, j);
            int replace = 1 + solveRec(str1, str2, i+1, j+1);
            ans = min(insert, min(deleted, replace));
        }
        return ans;
    }

    int solveMem(string &str1, string &str2, int i, int j, vector<vector<int> > &dp){
        int n = str1.length();
        int m = str2.length();

        if(i == n) return m - j;
        if(j == m) return n - i;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(str1[i] == str2[j])
             ans = solveMem(str1, str2, i+1, j+1, dp);
        else{
            int insert = 1 + solveMem(str1, str2, i, j+1, dp);
            int deleted = 1 + solveMem(str1, str2, i+1, j, dp);
            int replace = 1 + solveMem(str1, str2, i+1, j+1, dp);
            ans = min(insert, min(deleted, replace));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int i = 0;
        int j = 0;

        vector<vector<int> > dp(n+1, vector<int> ( m+1, -1));

        //int ans = solveRec(word1, word2, i, j);
        int ans = solveMem(word1, word2, i, j, dp);


        return ans;
    }
};