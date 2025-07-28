class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();               // Length of the input string
        int ansLen = 0;                   // Stores maximum length of unique substring
        unordered_set<char> uset;         // Set to store characters in current window

        int j = 0; // Right pointer (was i)
        int i = 0; // Left pointer (was j)

        while(j < n){
            char ch = s[j];

            // If character is not in the current window, insert it
            if(!uset.count(ch)){
                uset.insert(ch);
            }
            else{
                // If duplicate found, move left pointer `i` forward
                // until the repeated character is removed
                while(s[i] != ch){
                    uset.erase(s[i]);
                    i++;
                }
                i++; // Skip the repeated character
            }

            // Update the maximum length of the window
            ansLen = max(ansLen, j - i + 1);
            j++; // Expand the window from the right
        }

        return ansLen;
    }
};
