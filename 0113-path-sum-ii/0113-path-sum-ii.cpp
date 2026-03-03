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
    void helper(TreeNode* root, int targetSum, int sum, 
                vector<int> &temp, vector<vector<int>> &ans) {

        if(root == NULL) return;   // Base case

        sum += root->val;          // Add current node to running sum
        temp.push_back(root->val); // Add node to current path

        // If leaf node
        if(root->left == NULL && root->right == NULL){
            if(targetSum == sum){  // Valid root-to-leaf path
                ans.push_back(temp);
            }
        }
        else{
            // Explore children
            helper(root->left, targetSum, sum, temp, ans);
            helper(root->right, targetSum, sum, temp, ans);
        }

        temp.pop_back(); // Backtrack: remove current node before returning
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp; 
        vector<vector<int>> ans;

        helper(root, targetSum, 0, temp, ans);
        return ans;
    }
};