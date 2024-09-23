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
    // Function to add two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; // To keep track of the carry when summing digits
        int digit = 0; // To store the current digit after summing
        int sum = 0;   // To store the total sum of digits and carry

        // Create a dummy head for the result linked list
        ListNode* l3 = new ListNode(0); 
        ListNode* head1 = l1; // Pointer for the first linked list
        ListNode* head2 = l2; // Pointer for the second linked list
        ListNode* head3 = l3; // Pointer to build the result linked list
        
        // Loop while both linked lists have nodes
        while(head1 != NULL && head2 != NULL) {
            // Calculate sum of corresponding digits and carry
            sum = head1->val + head2->val + carry;
            digit = sum % 10; // Get the last digit of the sum
            carry = sum / 10;  // Update carry for the next iteration
            
            // Create a new node with the calculated digit and attach to result
            l3->next = new ListNode(digit); 
            l3 = l3->next; // Move to the next node in the result list
            
            // Move to the next nodes in the input lists
            head1 = head1->next;
            head2 = head2->next;
        }

        // Process remaining nodes from the first linked list (if any)
        while(head1 != NULL) {
            sum = head1->val + carry; // Add carry to the current node's value
            digit = sum % 10; // Get the last digit of the sum
            carry = sum / 10; // Update carry
            
            l3->next = new ListNode(digit); // Create a new node with the digit
            l3 = l3->next; // Move to the next node in the result
            
            head1 = head1->next; // Move to the next node in the first list
        }

        // Process remaining nodes from the second linked list (if any)
        while(head2 != NULL) {
            sum = head2->val + carry; // Add carry to the current node's value
            digit = sum % 10; // Get the last digit of the sum
            carry = sum / 10; // Update carry
            
            l3->next = new ListNode(digit); // Create a new node with the digit
            l3 = l3->next; // Move to the next node in the result
            
            head2 = head2->next; // Move to the next node in the second list
        }

        // If there's still a carry left after processing both lists, create a new node for it
        if(carry != 0) {
            l3->next = new ListNode(carry);
        }

        // Return the next node of the dummy head, which is the start of the result list
        return head3->next;
    }
};
