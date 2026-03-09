/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;                 // If tree is empty, nothing to connect

        Node* ans = root;                // Store original root to return later

        while (root->left != NULL) {     // Works because tree is a PERFECT binary tree
            Node* curr = root;           // Traverse current level using next pointers

            while(curr != NULL){

                curr->left->next = curr->right;  
                // Connect left child → right child of same parent

                if (curr->next != NULL) {
                    curr->right->next = curr->next->left;  
                    // Connect right child → next node's left child
                }

                curr = curr->next;       // Move horizontally across the level
            }

            root = root->left;           // Move to next level (leftmost node)
        }

        return ans;                      // Return original root
    }
};