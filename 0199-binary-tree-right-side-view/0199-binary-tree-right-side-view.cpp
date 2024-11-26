/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Recursive function to find the right side view of the binary tree
    void solve(TreeNode* root, vector<int>& ans, int level) {
        // Base case: If the current node is NULL, return
        if (root == NULL) return;

        // If the current level is being visited for the first time
        if (ans.size() == level) {
            // Add the current node's value to the answer
            ans.push_back(root->val);
        }

        // Recursively traverse the right subtree first to prioritize the right view
        solve(root->right, ans, level + 1);

        // Then traverse the left subtree
        solve(root->left, ans, level + 1);
    }

    // Function to return the right side view of the binary tree
    vector<int> rightSideView(TreeNode* root) {
        int level = 0; // Start from level 0
        vector<int> ans; // Vector to store the nodes visible from the right side view
        solve(root, ans, level); // Call the helper function
        return ans; // Return the result
    }
};
