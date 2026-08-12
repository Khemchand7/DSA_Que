class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        // value, index
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        // ---------------- FIRST WINDOW ----------------
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        // Maximum of first window
        ans.push_back(pq.top().first);

        // ---------------- REMAINING WINDOWS ----------------
        for (int i = k; i < n; i++) {

            // Add the new element entering the window
            pq.push({nums[i], i});

            // Remove elements that are outside the current window
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            // Maximum of current window
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
/* 
if last element of window is i th then first element will be i - k + 1 
all the elements less than equal to  i - k are not part of current window
proof: 
current window element is i 
assume first window element as x
so : i - x + 1 = k  
    => x = i - k + 1
 */