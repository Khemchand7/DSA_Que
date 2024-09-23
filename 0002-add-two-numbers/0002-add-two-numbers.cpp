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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int digit = 0;
        int sum = 0;
        ListNode* l3 = new ListNode(0);
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* head3 = l3;
        
        //when both the Linked List are of equal length
        while(head1 != NULL && head2 != NULL){
             sum = head1->val + head2->val + carry;
             digit = sum % 10;
             carry = sum / 10; 
            l3->next = new ListNode(digit); 
            l3 = l3->next;      
            head1 = head1->next;
            head2 = head2->next;
        }
        //Lenght of Linked List1 is greater
         while(head1 != NULL){
             sum = head1->val+ carry;
             digit = sum % 10;
             carry = sum / 10;
            l3->next = new ListNode(digit); 
            l3 = l3->next;
            head1 = head1->next;
        }
        //lenth of LInked list 2 is greater
         while(head2 != NULL){
             sum = head2->val + carry;
             digit = sum % 10;
             carry = sum / 10;
            l3->next = new ListNode(digit); 
            l3 = l3->next;
            head2 = head2->next;
        }
        if(carry!=0){
            l3->next = new ListNode(carry);
        }
    return head3->next;
    }
};