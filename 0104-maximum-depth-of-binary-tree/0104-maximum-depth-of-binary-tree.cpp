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
    // Function to calculate the maximum depth (or height) of a binary tree
    int maxDepth(TreeNode* root) {
        // If the root is NULL, the tree is empty, so return depth as 0
        if (root == NULL) return 0;

        // Recursively calculate the maximum depth of the left subtree
        int leftNode = maxDepth(root->left);

        // Recursively calculate the maximum depth of the right subtree
        int rightNode = maxDepth(root->right);

        // The height of the current node is the maximum depth of its children + 1 (for root)
        int height = max(leftNode, rightNode) + 1;

        // Return the calculated height for the current node
        return height;
    }
};
