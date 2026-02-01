/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

void helper(Node* &root, int level, vector<int> &ans){
    // Base case: if current node is NULL, stop recursion
    if(root == NULL) return;

    // If this is the first node visited at this level,
    // it belongs to the right view
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    // First visit left subtree to ensure rightmost node is picked first
    helper(root->left, level + 1, ans);
    

    // Then visit left subtree
    helper(root->right, level + 1, ans);
}

class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        
        helper(root, 0, ans);
        
        return ans;
        
    }
};