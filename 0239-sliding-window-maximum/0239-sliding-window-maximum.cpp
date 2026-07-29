class Solution {
public:

/* 
One-line memory trick
----------------------
    i >= k-1 → "Has the first window been formed?"
    index <= i-k → "Is this element outside the current window?"

These two lines are enough to derive the conditions during an interview instead of memorizing them.
 */

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        // Max-heap -> {value, index}
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for(int i = 0; i < n; i++){

            // Insert current element along with its index
            pq.push({nums[i], i});

            // Remove elements that are outside the current window
            while(!pq.empty() && pq.top().second <= i - k)
                pq.pop();

            // First complete window is formed when i >= k-1
            if(i >= k - 1)
                ans.push_back(pq.top().first);   // Heap top is the maximum element
        }

        return ans;
    }
};
/* 
Time Complexity
---------------
    Each element is inserted once → O(n log n)
    Each element is removed at most once → O(n log n)
    Overall: O(n log n)
Space Complexity
----------------
    Heap can contain up to O(n) elements (expired elements stay until they reach the top).
    Overall: O(n)
 */