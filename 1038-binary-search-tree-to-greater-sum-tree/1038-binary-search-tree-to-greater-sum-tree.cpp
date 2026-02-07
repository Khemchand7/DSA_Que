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

    void storeInorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        storeInorder(root->left, ans);
        ans.push_back(root->val);          // store current node
        storeInorder(root->right, ans);
    }

    // Replace each node's value using updated inorder array
    void replaceRoots(TreeNode*& root, vector<int> inorder, int& index) {
        if (root == NULL) return;

        replaceRoots(root->left, inorder, index);

        root->val = inorder[index];        // assign greater-sum value
        index++;

        replaceRoots(root->right, inorder, index);
    }
    TreeNode* bstToGst(TreeNode* root) {
       vector<int> inorder;
        storeInorder(root, inorder);       // get sorted inorder values

        int n = inorder.size();
        int idx = 0;

        // Convert inorder array to greater-sum form (suffix sum)
        for (int i = n - 2; i >= 0; i--) {
            inorder[i] += inorder[i + 1];
        }

        replaceRoots(root, inorder, idx);  // update BST nodes
        return root;


    }
};