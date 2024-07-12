class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        int index=0;
        while(index < s.length()){
            //same wala case
            //agar ans string ka rigtmost character and string s ka index wala character 
            if(ans.length()>0 && ans[ans.length()-1]==s[index]){
                //pop
                ans.pop_back();
            }
            else{
                //different wala case
                ans.push_back(s[index]);
            }
            index++;
        }
        return ans;
        
    }
};