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
    ListNode* reverseLLrec(ListNode* prev,ListNode* curr){
        //Base Case
        if(curr == NULL){
            return prev;
        }
        //Solve one Case
        ListNode* nextNode = curr->next;
        curr->next = prev;
        //Call Recursive Function
        return reverseLLrec(curr,nextNode);
    }
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    bool compareList(ListNode* head1, ListNode* head2){
        while(head2 != NULL){//odd wala case handle kia hai odd me last wala jo bachega use compare hi nhi kia // note point is headA is always greater than headB if conditionis headB!=NULL will also give the same result
            if(head1->val != head2->val){
                return false;
            }
            else{
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
       
        //find the mid;
        ListNode* mid = findMid(head);
        ListNode* head2 = mid->next;
        
        //break
        mid->next = NULL;

        //reverse
        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseLLrec(prev,curr);
        

        //compare both the list
        return compareList(head,head2);


    }
};