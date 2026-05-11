class Solution {
public:
    int LCS(string &str1, string &str2){
        
        int n = str1.length();
        int m = str2.length();
        
        // dp[i][j] = LCS length using first i chars of str1
        // and first j chars of str2
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                
                // Characters match
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    // Skip one character
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }

    bool isSubsequence(string s, string t) {
        int len_LCS = LCS(s,t);
        // if length of LCS is equals to length of string s then yes s is a subsequence of t else no
        return len_LCS == s.length();
    }
};