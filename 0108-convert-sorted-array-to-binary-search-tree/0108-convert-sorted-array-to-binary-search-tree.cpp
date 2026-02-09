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
    
    TreeNode* helper(vector<int>& nums, int s, int e){
        // Base case: no elements to process
        if(s > e) return NULL;

        // Pick middle element to keep tree height balanced
        int mid = s + (e - s) / 2;

        // Create root node with middle value
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build left subtree from left half
        root->left = helper(nums, s, mid - 1);

        // Recursively build right subtree from right half
        root->right = helper(nums, mid + 1, e);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return helper(nums, 0, nums.size() - 1);
    }
};
