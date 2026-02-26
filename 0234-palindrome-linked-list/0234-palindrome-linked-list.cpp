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
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast =
            head->next; // start fast ahead → gives first middle in even length

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;       // move by 1
            fast = fast->next->next; // move by 2 (IMPORTANT)
        }
        return slow; // slow ends at middle (or first middle)
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* currKaNext = curr->next; // save next node
            curr->next = prev;                 // reverse link
            prev = curr;                       // move prev forward
            curr = currKaNext; // move curr forward using saved pointer
        }

        return prev; // new head of reversed list
    }
    bool isPalindrome(ListNode* A) {
        // 0 or 1 node → always palindrome
    if(A == NULL || A->next == NULL){
        return true;
    }

    ListNode* middlle = getMiddle(A);       // find end of first half

    ListNode* firstHalf = A;
    ListNode* secondHalf = middlle->next;   // start of second half
    middlle->next = NULL;                   // split the list into two halves

    ListNode* reversedSecondHalf = reverse(secondHalf);  // reverse second half

    // compare both halves
    while(firstHalf != NULL && reversedSecondHalf != NULL){
        if(firstHalf->val != reversedSecondHalf->val)
            return false;                       // mismatch → not palindrome

        firstHalf = firstHalf->next;
        reversedSecondHalf = reversedSecondHalf->next;
    }

    return true;                               // all matched → palindrome
    }
};