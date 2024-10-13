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
    // Function to find the lowest common ancestor (LCA) of two nodes (p and q) in a binary tree.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the current root is null, return null (end of the tree).
        if(root == NULL){
            return NULL;
        }
        
        // If the current root is equal to p, we've found one of the nodes, so return root.
        if(root == p){
            return p;
        }

        // If the current root is equal to q, we've found the other node, so return root.
        if(root == q){
            return q;
        }

        // Recursively search for the LCA in the left subtree of the current root.
        TreeNode* leftKaAns = lowestCommonAncestor(root->left, p, q);

        // Recursively search for the LCA in the right subtree of the current root.
        TreeNode* rightKaAns = lowestCommonAncestor(root->right, p, q);

        // If both the left and right recursive calls return null, p and q are not found in this subtree.
        if(leftKaAns == NULL && rightKaAns == NULL){
            return NULL;
        }
        // If only the right subtree contains one of the nodes, return the result from the right.
        else if(leftKaAns == NULL && rightKaAns != NULL){
            return rightKaAns;
        }
        // If only the left subtree contains one of the nodes, return the result from the left.
        else if(leftKaAns != NULL && rightKaAns == NULL){
            return leftKaAns;
        }
        // If both the left and right subtrees return non-null values, it means p and q are found in different subtrees,
        // so the current root is their lowest common ancestor.
        else {
            return root;
        }
    }
};
