class Solution {
public:
    struct Node {
        int val, row, col; // value + its position in matrix
    };

    struct cmp {
        bool operator()(Node& a, Node& b) {
            return a.val > b.val; // min heap based on value
        }
    };
    int kthSmallest(vector<vector<int>>& A, int B) {
        int n = A.size();
        int m = A[0].size();

        // Min heap → stores next smallest candidates
        priority_queue<Node, vector<Node>, cmp> pq;

        // Push first row (smallest elements of each column)
        for (int i = 0; i < m; i++) {
            pq.push({A[0][i], 0, i});
        }

        Node curr;

        // Remove B-1 smallest elements
        for (int count = 1; count < B; count++) {
            curr = pq.top(); // current smallest
            pq.pop();

            int i = curr.row;
            int j = curr.col;

            // Push next element from same column
            if (i + 1 < n) {
                pq.push({A[i + 1][j], i + 1, j});
            }
        }

        // Top now holds Bth smallest element
        return pq.top().val;
    }
};