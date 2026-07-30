class Solution {
public:
    int minCost(vector<int>& arr) {

        // Min heap to always get the two smallest ropes
        priority_queue<int, vector<int>, greater<int>> pq;

        int cost = 0;

        // Insert all rope lengths into the min heap
        for (auto len : arr) {
            pq.push(len);
        }

        // Keep connecting ropes until only one rope remains
        while (pq.size() > 1) {

            int len1 = pq.top(); pq.pop();
            int len2 = pq.top(); pq.pop();

            // Cost of connecting the two smallest ropes
            int temp = len1 + len2;
            cost += temp;

            // Push the newly formed rope back into the heap
            pq.push(temp);
        }

        return cost;
    }
};
