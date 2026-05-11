class Solution {
public:

    int LongestRepeatingSubsequence(string &s) {

        // Create another copy of same string
        string s2 = s;

        int n = s.length();

        // dp[i][j] = length of longest repeating subsequence
        // using first i chars of s and first j chars of s2
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Build LCS table on same string
        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= n; j++) {

                // Characters match but indices must be different
                if(s[i - 1] == s[j - 1] && i != j) {

                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                // Skip one character from either side
                else {

                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Length of longest repeating subsequence
        return dp[n][n];
    }
};