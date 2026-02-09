/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // Returns length of the linked list
    int getLen(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            len++;               // count nodes
            temp = temp->next;
        }
        return len;
    }

    // Builds BST using inorder simulation on linked list
    TreeNode* solve(ListNode* &head, int n){
        // Base case: no nodes to construct
        if(head == NULL || n <= 0) return NULL;
        
        // Recursively build left subtree with n/2 nodes
        TreeNode* leftSubTree = solve(head, n / 2);

        // Current list node becomes root
        TreeNode* root = new TreeNode(head->val);
        root->left = leftSubTree;

        // Move list pointer to next inorder element
        head = head->next;

        // Build right subtree with remaining nodes
        root->right = solve(head, n - n / 2 - 1);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // Get total number of nodes
        int n = getLen(head);

        // Construct height-balanced BST
        return solve(head, n);
    }
};
