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
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans; // To store the final result (2D vector)
    
    // Base case: if the tree is empty, return an empty result
    if (root == NULL) return ans;

    queue<TreeNode*> q;  // Queue to help with the level order traversal
    q.push(root);        // Start by pushing the root node into the queue
    q.push(NULL);        // NULL is used as a marker for the end of a level

    vector<int> temp;    // To store the values of the current level

    // Traverse the tree level by level
    while (!q.empty()) {
        TreeNode* frontElement = q.front(); // Get the front element in the queue
        q.pop();  // Remove it from the queue
        
        // If we encounter a NULL, it means we've completed processing one level
        if (frontElement == NULL) {
            ans.push_back(temp);  // Add the current level values to the result
            temp.clear();         // Clear temp for the next level
            
            // If the queue is not empty, push another NULL to mark the end of the next level
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            // Add the current node's value to the current level
            temp.push_back(frontElement->val);
            
            // If the node has a left child, push it to the queue
            if (frontElement->left != NULL) {
                q.push(frontElement->left);
            }
            
            // If the node has a right child, push it to the queue
            if (frontElement->right != NULL) {
                q.push(frontElement->right);
            }
        }
    }
    
    return ans;  // Return the result which contains values level by level
}

};