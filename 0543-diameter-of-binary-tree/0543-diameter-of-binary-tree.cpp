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
/*     int height(TreeNode* root){
        if(root == NULL) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int height = max(leftHeight,rightHeight)+1;
        return height;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = height(root->left) + height(root->right);
        int length = max(option1,max(option2,option3)); // yahan pr +1 islie nhi kia kyuki length me edges count karni hai aur height me humne nodes count kari hai 2 nodes ke beech me ek edge hogi
        return length;
    } */

    
 // Variable to store the maximum diameter found
int diameter = 0;

// Helper function to calculate the height of the tree and update the diameter
int height(TreeNode* root) {
    // Base case: If the current node is NULL, its height is 0
    if (root == NULL) return 0;

    // Recursively calculate the height of the left and right subtrees
    int leftHt = height(root->left);
    int rightHt = height(root->right);

    // Calculate the diameter through the current node
    int currDiameter = leftHt + rightHt;

    // Update the maximum diameter found so far
    diameter = max(currDiameter, diameter);

    // Return the height of the current node, which is 1 + maximum of left and right subtree heights
    return 1 + max(leftHt, rightHt);
}


int diameterOfBinaryTree(TreeNode* root) { 
    height(root);
    // Return the maximum diameter found
    return diameter;
}

};