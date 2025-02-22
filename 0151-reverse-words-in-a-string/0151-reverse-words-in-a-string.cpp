class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        // Iterate from the end of the string to extract words in reverse order
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] != ' ') {  // Skip spaces
                string current = "";
                
                // Extract the word
                while(i >= 0 && s[i] != ' ') {
                    current += s[i];
                    i--;
                }
                
                // Reverse the extracted word to restore its correct order
                reverse(current.begin(), current.end());

                // Add space before appending the next word (except for the first word)
                if(!ans.empty()) {
                    ans += ' ';
                }
                ans += current;
            }
        }
        return ans;
    }
};
