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
    // Inorder traversal: Left → Root → Right
    // For a BST, this stores values in sorted order
    void storeInorder(TreeNode* root, vector<int> &temp) {
        if (root == NULL) return;   // Base case

        storeInorder(root->left, temp);   // Visit left subtree
        temp.push_back(root->val);         // Store current node value
        storeInorder(root->right, temp);  // Visit right subtree
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        storeInorder(root, temp);          // Get sorted elements of BST
        return temp[k - 1];                // k-th smallest (0-based index)
    }
};
