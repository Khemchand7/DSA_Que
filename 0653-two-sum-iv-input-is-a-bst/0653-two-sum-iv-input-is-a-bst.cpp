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
    // Inorder traversal to get sorted values from BST
    void storeInorder(TreeNode* root, vector<int>& inorder){
        if(root == NULL) return;          // base case

        storeInorder(root->left, inorder);
        inorder.push_back(root->val);     // store current node value
        storeInorder(root->right, inorder);
    }

    // Two-pointer check to find if any pair sums to k
    bool checkSum(vector<int> inorder, int k){
        int s = 0;                        // start pointer
        int e = inorder.size() - 1;       // end pointer

        while(s < e){
            int currSum = inorder[s] + inorder[e];
            if(currSum == k) return true; // pair found
            else if(currSum > k) e--;     // decrease sum
            else s++;                     // increase sum
        }
        return false;                     // no valid pair
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        storeInorder(root, inorder);      // get sorted inorder traversal
        return checkSum(inorder, k);       // check pair sum
    }
};
