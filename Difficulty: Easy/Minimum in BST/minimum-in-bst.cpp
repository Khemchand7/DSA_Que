/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int minValue(Node* root) {
        if(!root) return 0;
        
        while(root->left != NULL) root = root->left;
        
        return root->data;
        
    }
};