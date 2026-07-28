class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // Max Heap -> {distance, index}
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            // Calculate squared distance from the origin
            int dist = x * x + y * y;

            pq.push({dist, i});

            // Keep only the k closest points
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        // Extract the k closest points
        while (!pq.empty()) {

            int idx = pq.top().second;
            pq.pop();

            ans.push_back(points[idx]);
        }

        return ans;
    }
};