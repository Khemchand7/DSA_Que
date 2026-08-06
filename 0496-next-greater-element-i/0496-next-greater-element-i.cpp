class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        stack<int> st;
        unordered_map<int, int> mp;   // Stores: element -> next greater element

        // Process nums2 from right to left to find next greater element
        for (int i = n2 - 1; i >= 0; i--) {

            // Remove all smaller or equal elements since they can never
            // be the next greater element for nums2[i]
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If stack is empty, no greater element exists.
            // Otherwise, stack top is the next greater element.
            st.empty() ? mp[nums2[i]] = -1 : mp[nums2[i]] = st.top();

            // Current element can be the next greater for elements on its left
            st.push(nums2[i]);
        }

        vector<int> ans;

        // Answer each query in O(1) using the hashmap
        for (auto it : nums1) {
            ans.push_back(mp[it]);
        }

        return ans;
    }
};

/* st: 4 3 1
mp: 2 -> -1
    4 -> -1
    3 -> 4
    1 -> 3 */
