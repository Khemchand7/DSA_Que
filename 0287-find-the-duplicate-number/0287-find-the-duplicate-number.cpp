class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n=a.size();
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++){
            hash[a[i]]++;
        }
        for(int i=0;i<n;i++){
            if(hash[a[i]]>1){
                return a[i];
            }
        }
        return-1;
    }
};