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
    // Function to calculate the length of the linked list
    int getLength(ListNode* &head) {
        ListNode* temp = head; 
        int count = 0; 
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    // Function to reverse nodes in k-group
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Calculate the length of the linked list
        int len = getLength(head);
        
        // Base case: if the length is less than k, no reversal is needed
        if(len < k) {
            return head; // Return the original head
        }
        
        int count = 0; // Counter for the number of nodes processed
        ListNode* prev = NULL; // Previous node initialized to NULL
        ListNode* curr = head; // Current node starts at the head
        ListNode* next = NULL; // Next node placeholder
        
        // Reverse the first k nodes of the linked list
        while(count < k && curr != NULL) {
            next = curr->next; // Store the next node
            curr->next = prev; // Reverse the link
            prev = curr; // Move prev to current node
            curr = next; // Move to the next node
            count++; // Increment the count
        }

        // If there are more nodes to process, recursively call for the next group
        if(next != NULL) { // Ensure next is not NULL before the recursive call
            head->next = reverseKGroup(next, k); // Link the reversed part with the result of the next group
        }
        
        // Return the head of the newly reversed list
        return prev; // Prev is the new head after reversal
    }
};
