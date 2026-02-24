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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int size = 0;
        ListNode* temp = head;

        // If list is empty OR has only one node → result becomes empty list
        if(head == NULL || head->next == NULL) return NULL;

        // Count total number of nodes
        while(temp != NULL){
            size++;
            temp = temp->next;
        }

        // If n > size → remove first node
        if(n >= size){
            head = head->next;
            return head;
        }

        temp = head;

        // Move to node just BEFORE the node to delete
        for(int i = 0; i < size - n - 1; i++){
            temp = temp->next;
        }

        // Remove nth node from end
        temp->next = temp->next->next;

        return head;
    }
};