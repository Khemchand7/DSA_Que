class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Arrays to store max height to the left and right of each bar
        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);
        
        int trappedWater = 0;

        // Compute lmax: max height to the left of current bar including itself
        lmax[0] = height[0];
        for (int i = 1; i < n; i++) {
            lmax[i] = max(lmax[i - 1], height[i]);
        }

        // Compute rmax: max height to the right of current bar including itself
        rmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = max(rmax[i + 1], height[i]);
        }

        // Calculate trapped water at each bar
        for (int i = 0; i < n; i++) {
            trappedWater += (min(lmax[i], rmax[i]) - height[i]);
        }

        return trappedWater;
    }
};
