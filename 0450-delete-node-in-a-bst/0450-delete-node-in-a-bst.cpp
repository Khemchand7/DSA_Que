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
    int maxOfTree(TreeNode* root){
        if(root == NULL) return -1;

        while(root->right != NULL){
            root = root->right;
        }
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key){
            //need to delete here
            // leaf node
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            // having left child only
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp; 
            }
            // having right child only
            if(root->right != NULL && root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // have both the child
            if(root->left != NULL && root->right != NULL){
                int replaceapbleValue = maxOfTree(root->left);
                root->val = replaceapbleValue;
                root->left = deleteNode(root->left,replaceapbleValue);
                return root;
            }
        }
        
            if(key > root->val){
                root->right = deleteNode(root->right,key);
                return root;
            }
            else{
                root->left = deleteNode(root->left,key);
                return root;
            }
        
        return root;


    }
};