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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // If the tree is empty, there's no path sum
        if (root == NULL) {
            return false;
        }

        // Check if the current node is a leaf node
        if (root->left == NULL && root->right == NULL) {
            return targetSum == root->val;
        }

        // Subtract the current node's value from the target sum and recurse on children
        targetSum -= root->val;

        // Recursively check the left and right subtrees
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
