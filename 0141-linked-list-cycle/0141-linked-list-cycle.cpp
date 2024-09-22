/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
/*     //using map function
    bool hasCycleUsingMap(ListNode *head) {
        map<ListNode* , bool> table;
        ListNode* temp = head;
        while(temp!=NULL){
            if(table[temp]==false){
                table[temp] = true;
            }
            else{
                return true;
            }
            temp = temp->next;
        }
        return false;
    } */
    // slow and fast pointer || tortoise and hare algorithm || two pointer 
    bool hasCycle(ListNode *&head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
            //if both the pointer meet then cycle present
            if(fast == slow){
                return true;
            }
        }
        //loop se bahar aae matlab fast == NULL => cycle is not present
        return false;
    }
};