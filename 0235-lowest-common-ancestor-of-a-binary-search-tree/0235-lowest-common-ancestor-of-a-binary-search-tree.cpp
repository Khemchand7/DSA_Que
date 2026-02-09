/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;   // Base case

        // Both p and q are smaller → LCA lies in left subtree
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        // Both p and q are greater → LCA lies in right subtree
        else if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        // Split point (or one equals root) → current node is LCA
        else
            return root;
    }
};
