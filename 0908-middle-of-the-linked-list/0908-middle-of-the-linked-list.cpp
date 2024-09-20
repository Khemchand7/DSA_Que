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
    int getLength(ListNode* &head){
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
/*         //in this approach we are traversing the linked list twice we need the approach in which we get ans in one traversal
        int position = (getLength(head)/2) + 1;
        ListNode* temp = head;
        while(position!=1){
            temp = temp->next;
            position--;
        }
        return temp; */

        //Slow and Fast Pointer Approach or Two Pointer algorithm or Tortoise Algorithm
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL){
            fast = fast-> next;//ek bar me 2 step islie nhi badae qki possibility hai ki fast NULL pr ho aise me wo null ke next pr chala jaega
            if(fast!=NULL){
                fast = fast -> next;
                //yahan pr fast 2 step chal chuka hai to ab hum slow ko ek step bada sakte hai 
                slow = slow -> next;
            }
        }
        return slow;
    }
};