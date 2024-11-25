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
    map<int, int> search;

    // Helper function to map inorder elements to their indices
    void mapping(vector<int>& inorder, int inSize) {
        for (int i = 0; i < inSize; i++) {
            int key = inorder[i];
            search[key] = i;
        }
    }

    // Recursive function to build the tree
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& postIndex, int inStart, int inEnd) {
        // Base condition
        if (postIndex < 0 || inStart > inEnd) {
            return NULL;
        }

        // Create the root node with the current postorder element
        int element = postorder[postIndex];
        postIndex--; // Decrement postIndex for the next element
        TreeNode* root = new TreeNode(element);

        // Get the position of the current element in inorder traversal
        int position = search[element];

        // Build right subtree first (because postorder is left-right-root)
        root->right = solve(inorder, postorder, postIndex, position + 1, inEnd);
        // Build left subtree
        root->left = solve(inorder, postorder, postIndex, inStart, position - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postSize = postorder.size();
        int inSize = inorder.size();
        int postIndex = postSize - 1; // Initialize postIndex to the last index

        mapping(inorder, inSize); // Map inorder elements to indices

        // Call the recursive function
        return solve(inorder, postorder, postIndex, 0, inSize - 1);
    }
};
