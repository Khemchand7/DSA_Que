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

    arr idx : 0 1 2 3 4 5 6 7

    Condition1:
    -----------
    suppose we are at idx = 4 and k = 3 so last first element of window will be i - k + 1;
    How ? 
    let's do it assume index of first element of window is x ans last element index is i 
    and window size is k 
    so k = i - x + 1  ==> x = i - k + 1;
    any index with index <= i - k is actually out of current window 

    Condition2:
    ----------
    when i = k - 1 first window will be formed so after that we need to add all max


 */