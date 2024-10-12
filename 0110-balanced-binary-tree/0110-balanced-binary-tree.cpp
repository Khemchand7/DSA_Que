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
public:\

    int height(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight , rightHeight)+1;
    }
bool isBalanced(TreeNode* root) {
    // Base case: If the tree is empty, it is balanced.
    if(root == NULL) return true;

    // Calculate the height of the left and right subtrees.
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Calculate the absolute difference between the heights of the left and right subtrees.
    int diff = abs(leftHeight - rightHeight);

    // Check if the current node is balanced (difference between heights is <= 1).
    bool currNode = (diff <= 1);

    // If the current node is not balanced, return false immediately.
    if(currNode == false) return false;

    // Recursively check if the left subtree is balanced.
    bool isLeftSubTreeBal = isBalanced(root->left);

    // Recursively check if the right subtree is balanced.
    bool isRightSubTreeBal = isBalanced(root->right);

    // The tree is balanced if the current node, left subtree, and right subtree are all balanced.
    if(currNode && isLeftSubTreeBal && isRightSubTreeBal) {
        return true;
    }
    else {
        return false;
    }
}
};