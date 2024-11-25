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
    // Map to store the index of each element in the inorder traversal
    map<int, int> search;

    // Function to map the elements of the inorder array with their indices
    void mapping(vector<int>& inorder, int size) {
        for (int i = 0; i < size; i++) {
            int key = inorder[i];
            search[key] = i; // Store the index of each element
        }
    }

    // Recursive function to build the binary tree
    //preIndex need to be passed mandatorly byReference here otherwise it will give wrong ans
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd, int size) {
        // Base case: If the preorder index is out of bounds or inStart > inEnd, return NULL
        if (preIndex >= size || inStart > inEnd) {
            return NULL;
        }

        // Get the current element from preorder using preIndex and increment preIndex
        int element = preorder[preIndex];
        preIndex++;

        // Create a new TreeNode with the current element
        TreeNode* root = new TreeNode(element);

        // Find the position of the current element in the inorder array using the map
        int position = search[element];

        // Recursively build the left subtree
        root->left = solve(preorder, inorder, preIndex, inStart, position - 1, size);

        // Recursively build the right subtree
        root->right = solve(preorder, inorder, preIndex, position + 1, inEnd, size);

        // Return the constructed root node
        return root;
    }

    // Main function to build the binary tree from preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0; // Initialize preorder index
        int size = inorder.size(); // Get the size of the inorder array
        int inStart = 0; // Start index for the inorder traversal
        int inEnd = size - 1; // End index for the inorder traversal

        // Create the mapping of inorder elements to their indices
        mapping(inorder, size);

        // Recursively build the tree
        TreeNode* binaryTreeRoot = solve(preorder, inorder, preIndex, inStart, inEnd, size);

        // Return the root of the constructed binary tree
        return binaryTreeRoot;
    }
};
