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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // If any list is empty → intersection not possible
    if(headA == NULL || headB == NULL) return NULL;

    ListNode* temp1 = headA;
    ListNode* temp2 = headB;

    // Traverse both lists; when a pointer reaches end,
    // redirect it to the head of the other list
    // This equalizes total distance traveled
    while(temp1 != temp2){

        temp1 = temp1->next;
        temp2 = temp2->next;

        // If they meet → intersection found
        if(temp1 == temp2) return temp1;

        // Redirect to other list after reaching NULL
        if(temp1 == NULL) temp1 = headB;
        if(temp2 == NULL) temp2 = headA;
    }

    // Either intersection node or NULL (no intersection)
    return temp1;
    }
};