class Solution {
  public:
     int LCS(string &str1, string &str2){

        int n = str1.size();
        int m = str2.size();

        // dp[i][j] = length of LCS using first i chars of str1
        // and first j chars of str2
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= m; j++){

                // Characters match
                if(str1[i - 1] == str2[j - 1]){

                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                // Skip one character from either string
                else{

                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Length of longest common subsequence
        return dp[n][m];
    }
  
    int minDeletions(string &s) {
        int n = s.length();

        // Reverse original string
        string s2 = s;
        reverse(s2.begin(), s2.end());

        // LCS of string and its reverse
        // gives longest palindromic subsequence
        int len_LCS = LCS(s, s2);

        // Minimum deletion required
        // = total length - longest palindromic subsequence
        return n - len_LCS;
        
    }
};