class Solution {
public:
      bool checkPalindrome(string s,int i, int j ){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
      }
      bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                //s[i]!=s[j]
                //1 removal allowed, for removal we have two possibility either remove i or j

                // remove ith element, so considered string from i+1 to j for checking palindrome
                bool ans1=checkPalindrome(s,i+1,j);

                //removed j th element, so considered string i to j-1 for checking palindrome
                bool ans2=checkPalindrome(s,i,j-1);
                return ans1 || ans2;
            }
        }
        //agar yahan tak aa gye hai to iska matlab valid palindrome hai
        //0==> removal 
       return true; 
    }
};