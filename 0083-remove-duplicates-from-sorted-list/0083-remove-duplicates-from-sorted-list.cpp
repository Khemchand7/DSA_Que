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
    ListNode* deleteDuplicates(ListNode* head) {

        // Edge case: empty list
        if(head == nullptr) return head;

        // Edge case: single node
        if(head->next == nullptr) return head;

        ListNode* prev = head;        // Last unique node
        ListNode* curr = head->next;  // Traversal pointer

        while(curr != nullptr){
            if(prev->val == curr->val){
                // Duplicate → remove curr
                prev->next = curr->next;
            }else{
                // New unique value → move prev forward
                prev = curr;
            }
            curr = curr->next;  // Always advance curr
        }

        return head;
    }
};