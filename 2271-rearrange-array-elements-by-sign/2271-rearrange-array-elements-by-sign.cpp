class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int>qp;
        queue<int>qn;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0) qp.push(nums[i]);
            if(nums[i]<0) qn.push(nums[i]);
        }
        vector<int>ans;
        for(int i=0;i<n/2;i++){
            if(qp.empty()||qn.empty()) break;
            int pos = qp.front();
            qp.pop();
            int neg = qn.front();
            qn.pop();
            ans.push_back(pos);
            ans.push_back(neg);
        }
        return ans;

    }
};