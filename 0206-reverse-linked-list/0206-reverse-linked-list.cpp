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

    ListNode* reverseListRecursion(ListNode* &prevNode, ListNode* &currNode){
        ListNode* prev = prevNode;
        ListNode* curr = currNode;

        //Base Case
        if(curr == NULL){
            return prev;//prev jahan pr hai wo ab new head hai
        }
        // 1 case solve karenge
        ListNode* nextNode = curr->next;
        curr->next = prev;
        //recursive call
        return reverseListRecursion(curr,nextNode);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *prevNode = NULL;
        ListNode *currNode = head;
        
/*         //Iterative approach
        while(currNode!=NULL){
            ListNode *nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        head = prevNode;
        return head; */

        //Using Recursion
        return reverseListRecursion(prevNode,currNode);
    }
};