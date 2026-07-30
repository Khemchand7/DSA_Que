class Solution {
public:
    struct Node{
        int sum;
        int i;
        int j;
    };

    struct cmp{
        bool operator()(Node a, Node b){
            // Min heap based on pair sum
            return a.sum > b.sum;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();
        int m = nums2.size();

        priority_queue<Node, vector<Node>, cmp> pq;
        vector<vector<int>> ans;

        // Push the first pair from each row
        for(int i = 0; i < min(n, k); i++){
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(!pq.empty() && k--){

            // Get the pair with the smallest sum
            auto curr = pq.top();
            pq.pop();

            ans.push_back({nums1[curr.i], nums2[curr.j]});

            // Push the next pair from the same row
            if(curr.j + 1 < m){
                pq.push({
                    nums1[curr.i] + nums2[curr.j + 1],
                    curr.i,
                    curr.j + 1
                });
            }
        }

        return ans;
    }
};