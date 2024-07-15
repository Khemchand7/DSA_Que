class Solution {
public:
    static string str;

    static bool cmp(char ch1, char ch2){
        //this will return true if positon of character in str string is
        // less than the position of character2 in str string
        //when true is returned the ch1 will be placed before ch2 in output string.
        return(str.find(ch1)<str.find(ch2));
    }
    string customSortString(string order, string s) {
        str=order;
        sort(s.begin(),s.end(),cmp);
        return s;
    }
};
string  Solution::str;