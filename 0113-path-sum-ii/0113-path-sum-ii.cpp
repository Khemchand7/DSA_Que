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
    // Helper function to recursively find all paths
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>temp) {
        // Base case: If the current node is NULL, simply return
        if (root == NULL) {
            return;
        }

        // Check if the current node is a leaf node
        if (root->left == NULL && root->right == NULL) {
            // If the leaf node's value matches the remaining targetSum
            if (targetSum == root->val) {
                // Add the current node's value to the temporary path
                temp.push_back(root->val);
                // Add the complete path to the result
                ans.push_back(temp);
            }
            return; // Return since we've processed the leaf node
        }

        // Subtract the current node's value from the target sum
        targetSum -= root->val;

        // Add the current node's value to the temporary path
        temp.push_back(root->val);

        // Recur for the left subtree
        solve(root->left, targetSum, ans, temp);

        // Recur for the right subtree
        solve(root->right, targetSum, ans, temp);
    }

    // Main function to return all paths that sum to the targetSum
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans; // To store all valid paths
        vector<int> temp;        // To store the current path during recursion
        solve(root, targetSum, ans, temp); // Start the recursive process
        return ans; // Return all valid paths
    }
};
