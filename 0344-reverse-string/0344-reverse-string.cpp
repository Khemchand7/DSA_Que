class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int j = n-1;
        int i = 0;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }

    }
};