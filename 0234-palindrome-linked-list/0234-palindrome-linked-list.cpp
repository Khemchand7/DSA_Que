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
    ListNode* reverseLLrec(ListNode* &prev,ListNode* &curr){
        ListNode* prevNode = prev;
        ListNode* currNode = curr;
        //Base Case
        if(currNode == NULL){
            return prev;
        }
        //Solve one Case
        ListNode* nextNode = currNode->next;
        curr->next = prevNode;
        //Call Recursive Function
        return reverseLLrec(curr,nextNode);
    }
    ListNode* findMid(ListNode* &head){
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
    bool compareList(ListNode* &head1, ListNode* &head2){
        ListNode* headA = head1;
        ListNode* headB = head2;
        while(headA != NULL && headB != NULL){//odd wala case handle kia hai odd me last wala jo bachega use compare hi nhi kia // note point is headA is always greater than headB if conditionis headB!=NULL will also give the same result
            if(headA->val != headB->val){
                return false;
            }
            else{
                headA = headA->next;
                headB = headB->next;
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