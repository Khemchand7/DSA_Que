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
    ListNode *detectCycle(ListNode *head) {
        // Initialize two pointers, slow and fast, both starting at the head of the list.
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Traverse the list with the two pointers:
        // - slow moves one step at a time.
        // - fast moves two steps at a time.
        // If there is a cycle, slow and fast will eventually meet.
        while(fast != NULL) {
            fast = fast->next; // Move fast pointer one step.
            if(fast != NULL) { 
                fast = fast->next; // Move fast pointer another step (total two steps).
                slow = slow->next; // Move slow pointer one step.
            }
            
            // Check if slow and fast pointers meet, indicating a cycle.
            if(fast == slow) break;
        }
        
        // If fast is NULL or does not meet slow, it means there is no cycle.
        if(fast != slow) return NULL;
        
        // At this point, there is a cycle in the list.
        // Move the slow pointer back to the head.
        slow = head;
        
        // Move both pointers one step at a time until they meet.
        // The meeting point will be the start of the cycle.
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Return the node where both pointers meet, indicating the start of the cycle.
        return slow;
    }
};
