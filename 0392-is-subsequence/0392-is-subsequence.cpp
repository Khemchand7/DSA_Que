class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        int i = 0, j = 0;
        int count = 0;

        while(i < n && j < m){
            if(s[i] == t[j]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return count == s.length();
    }
};