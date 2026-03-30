class Solution {
public:
    int solveRec(string str1, string str2, int i, int j) {
        int n = str1.length();
        int m = str2.length();

        // If str1 finished → need to insert remaining characters of str2
        if (i == n)
            return m - j;

        // If str2 finished → need to delete remaining characters of str1
        if (j == m)
            return n - i;

        int ans = 0;

        // If characters match → move both pointers
        if (str1[i] == str2[j])
            ans = solveRec(str1, str2, i + 1, j + 1);
        else {
            // Insert character
            int insert = 1 + solveRec(str1, str2, i, j + 1);

            // Delete character
            int deleted = 1 + solveRec(str1, str2, i + 1, j);

            // Replace character
            int replace = 1 + solveRec(str1, str2, i + 1, j + 1);

            // Take minimum of the three operations
            ans = min(insert, min(deleted, replace));
        }

        return ans;
    }

    int solveMem(string& str1, string& str2, int i, int j,
                 vector<vector<int>>& dp) {
        int n = str1.length();
        int m = str2.length();

        // Same base cases as recursion
        if (i == n)
            return m - j;
        if (j == m)
            return n - i;

        // If answer already computed → reuse it
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        if (str1[i] == str2[j])
            ans = solveMem(str1, str2, i + 1, j + 1, dp);
        else {
            int insert = 1 + solveMem(str1, str2, i, j + 1, dp);
            int deleted = 1 + solveMem(str1, str2, i + 1, j, dp);
            int replace = 1 + solveMem(str1, str2, i + 1, j + 1, dp);

            ans = min(insert, min(deleted, replace));
        }

        // Store computed result
        dp[i][j] = ans;

        return dp[i][j];
    }

    int solveTab(string& str1, string& str2) {
        int n = str1.length();
        int m = str2.length();

        // dp[i][j] → min operations to convert str1[i..] to str2[j..]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: str1 finished → insert remaining str2 characters
        for (int j = 0; j <= m; j++) {
            dp[n][j] = m - j;
        }

        // Base case: str2 finished → delete remaining str1 characters
        for (int i = 0; i <= n; i++) {
            dp[i][m] = n - i;
        }

        // Fill table bottom-up (reverse flow of recursion)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                int ans = 0;

                // If characters match → move diagonally
                if (str1[i] == str2[j])
                    ans = dp[i+1][j+1];
                else {
                    int insert = 1 + dp[i][j+1];
                    int deleted = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];

                    ans = min(insert, min(deleted, replace));
                }

                dp[i][j] = ans;
            }
        }

        // Final answer: convert entire word1 → word2
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int i = 0;
        int j = 0;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // int ans = solveRec(word1, word2, i, j);
        // int ans = solveMem(word1, word2, i, j, dp);
        int ans = solveTab(word1, word2);

        return ans;
    }
};