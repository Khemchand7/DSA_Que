class Solution {
public:

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        // dp[i][j] = length of LCS using first i chars of str1
        // and first j chars of str2
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Build LCS table
        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                // Characters match
                if(str1[i - 1] == str2[j - 1]) {

                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                // Take maximum LCS by skipping one character
                else {

                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = n;
        int j = m;

        string ans = "";

        // Build shortest common supersequence
        while(i > 0 && j > 0) {

            // Same character -> include only once
            if(str1[i - 1] == str2[j - 1]) {

                ans += str1[i - 1];

                i--;
                j--;
            }

            // Move towards larger LCS value from top
            else if(dp[i - 1][j] > dp[i][j - 1]) {

                ans += str1[i - 1];

                i--;
            }

            // Move towards larger LCS value from left
            else {

                ans += str2[j - 1];

                j--;
            }
        }

        // Add remaining characters of str1
        while(i > 0) {

            ans += str1[i - 1];

            i--;
        }

        // Add remaining characters of str2
        while(j > 0) {

            ans += str2[j - 1];

            j--;
        }

        // Reverse because answer was built backwards
        reverse(ans.begin(), ans.end());

        return ans;
    }
};