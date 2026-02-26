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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
        ListNode* head = NULL; // Head of merged list (final answer)
        ListNode* tail = NULL; // Points to last node in merged list

        ListNode* h1 = A; // Pointer to traverse list A
        ListNode* h2 = B; // Pointer to traverse list B

        //-----if any of list is empty we need to handle as it will not enter in loop and we are only making tail then not head --------------
        if (h1 == NULL && h2 != NULL)
            return h2;
        if (h1 != NULL && h2 == NULL)
            return h1;

        // Merge while both lists have nodes
        while (h1 != NULL && h2 != NULL) {
            if (h1->val < h2->val) { // Choose smaller value node
                if (head == NULL) {  // First node of merged list
                    head = h1;
                    tail = h1;
                } else {
                    tail->next = h1; // Append h1 node
                    tail = h1;       // Move tail forward
                }
                h1 = h1->next; // Advance in list A
            } else {
                if (head == NULL) { // First node of merged list
                    head = h2;
                    tail = h2;
                } else {
                    tail->next = h2; // Append h2 node
                    tail = h2;       // Move tail forward
                }
                h2 = h2->next; // Advance in list B
            }
        }

        // Attach remaining nodes (only one list will be non-empty)
        if (h1 != NULL) {
            tail->next = h1;
        }

        if (h2 != NULL) {
            tail->next = h2;
        }

        return head; // Return head of merged sorted list
    }
};