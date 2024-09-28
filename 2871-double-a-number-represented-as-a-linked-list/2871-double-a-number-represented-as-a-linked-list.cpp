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

    ListNode* reverseLL(ListNode* prev, ListNode* current) {
        // Base case: if current node is NULL, return prev (new head of the reversed list)
        if (current == NULL) {
            return prev;
        }
        
        // Store the next node
        ListNode* nextNode = current->next;
        
        // Reverse the link: current's next now points to the previous node
        current->next = prev;
        
        // Recursively reverse the rest of the list and return the new head
        return reverseLL(current, nextNode);
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* prevNode = NULL;
        ListNode* currNode = head;

        ListNode* tempHead = reverseLL(prevNode,currNode);
        ListNode* temp = tempHead;// to store the head of reverse LL
        ListNode* tempHead2 =NULL;// to track the last node

        int carry = 0;

        while(tempHead!= NULL){
        tempHead2 = tempHead;
        int mul = (tempHead->val * 2)+carry;
        int digit = mul%10;
        carry = mul/10;
        tempHead->val = digit;
        tempHead = tempHead->next;
        }

        if(carry !=0){
        ListNode* newNode = new ListNode(carry);
        tempHead2->next = newNode;
        }
        return reverseLL(prevNode,temp);
    }
};