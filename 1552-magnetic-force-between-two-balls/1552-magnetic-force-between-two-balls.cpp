class Solution {
// Approach:
// 1. Sort the positions.
// 2. Binary search the answer (minimum distance between balls).
// 3. For each distance, greedily place balls from left to right.
// 4. If placement is possible, try a larger distance; otherwise, reduce it.
//
// Time Complexity:
// Sorting: O(n log n)
// Binary Search: O(log(maxPosition - minPosition))
// Check Function: O(n) per binary search iteration
//
// Overall: O(n log n + n log(maxPosition - minPosition))
//
// Space Complexity: O(1)
public:
    // Checks if we can place 'm' balls such that
    // minimum distance between any two balls is at least maxDist.
    bool check(vector<int>& position, int m, int maxDist, int n){
        int lastBallPlaced = position[0];
        int totalBallsPlaced = 1;

        for(int i = 1; i < n; i++){
            // Greedily place the next ball if required distance is maintained.
            if(position[i] - lastBallPlaced >= maxDist){
                lastBallPlaced = position[i];
                totalBallsPlaced++;
            }

            // Successfully placed all balls.
            if(totalBallsPlaced >= m)
                return true;
        }

        // Not possible to place all balls.
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();

        // Sorting is required for greedy ball placement.
        sort(position.begin(), position.end());

        // Search space for the minimum distance.
        int start = 1;
        int end = position[n - 1] - position[0];
        int ans = -1;

        // Binary search on the answer.
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(check(position, m, mid, n)){
                // Current distance is possible, try for a larger one.
                ans = mid;
                start = mid + 1;
            }
            else{
                // Distance is too large, reduce it.
                end = mid - 1;
            }
        }

        return ans;
    }
};