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
    // Optimized function to reverse the linked list iteratively to avoid recursion overhead
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    // Main function to double each node's value and handle carryover
    ListNode* doubleIt(ListNode* head) {
        // Step 1: Reverse the linked list to process from least significant digit
        ListNode* reversedHead = reverseLL(head);

        // Step 2: Initialize variables to store carry and traverse the list
        ListNode* temp = reversedHead;
        ListNode* lastNode = NULL; // To track the last node in case of carry at the end
        int carry = 0;

        // Step 3: Iterate through the reversed list to double the value of each node
        while (temp != NULL) {
            lastNode = temp; // Keep track of the last processed node
            int mul = (temp->val * 2) + carry;
            temp->val = mul % 10; // Update the node's value
            carry = mul / 10;     // Calculate the carry
            temp = temp->next;
        }

        // Step 4: If there's a remaining carry, create a new node at the end and attatch to LL
        if (carry!=0) {
            lastNode->next = new ListNode(carry);
        }

        // Step 5: Reverse the list back to its original order
        return reverseLL(reversedHead);
    }
};
