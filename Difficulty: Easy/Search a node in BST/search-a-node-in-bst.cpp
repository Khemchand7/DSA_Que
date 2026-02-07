/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        if(root == NULL) return false;
        
        if(root->data == key) return true;
        return search(root->left,key) || search(root->right,key);
    }
};