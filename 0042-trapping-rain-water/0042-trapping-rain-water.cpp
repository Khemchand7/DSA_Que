/* 
At every index:

Water trapped = min(leftMax, rightMax) - height[i]

Instead of storing left/right max arrays, we use two pointers and maintain lmax and rmax.
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0;         // Maximum height seen from the left
        int rmax = 0;         // Maximum height seen from the right
        int trappedWater = 0; // Total water trapped

        int l = 0;                 // Left pointer
        int r = height.size() - 1; // Right pointer

        while (l < r) {

            // Process the side with the smaller height
            if (height[l] <= height[r]) {

                // If left max is taller, water can be trapped here
                if (lmax > height[l])
                    trappedWater += (lmax - height[l]);

                // Current height becomes the new left maximum
                else
                    lmax = height[l];

                l++;
            } else {

                // If right max is taller, water can be trapped here
                if (rmax > height[r])
                    trappedWater += (rmax - height[r]);
                // Current height becomes the new right maximum
                else
                    rmax = height[r];

                r--;
            }
        }

        return trappedWater;
    }
};