class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;    // To store the maximums of each window
        deque<int> dq;      // Deque to store indices of useful elements within each window

        // Process the first window of size 'k'
        for(int i = 0; i < k; i++) {
            int element = nums[i];

            // Remove elements from the back of the deque that are smaller than the current element
            while(!dq.empty() && element >= nums[dq.back()]) {
                dq.pop_back();
            }

            // Add the index of the current element to the deque
            dq.push_back(i);
        }

        // The front of the deque contains the index of the maximum element for the first window
        //here we have not checked if dq is empty or not becuase anything out of 3 will definitely be the maximum 
        ans.push_back(nums[dq.front()]);

        // Process the remaining windows
        for(int i = k; i < nums.size(); i++) {
            int element = nums[i];

            // Remove the element from the front of the deque if it's outside the current window
            if(!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }

            // Remove elements from the back of the deque that are smaller than the current element
            while(!dq.empty() && element >= nums[dq.back()]) {
                dq.pop_back();
            }

            // Add the index of the current element to the deque
            dq.push_back(i);

            // The front of the deque contains the index of the maximum element for the current window
            ans.push_back(nums[dq.front()]);
        }

        // Return the list of maximums for each window
        return ans;
    }
};
