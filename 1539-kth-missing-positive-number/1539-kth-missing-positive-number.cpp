class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        for(auto ele : arr){
            if(ele <= k)
                k++;
            else
                break;
        }
        return k;
    }
};