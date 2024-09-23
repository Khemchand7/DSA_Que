//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    // Function to reverse a linked list
    Node* reverseLL(Node* prev, Node* current) {
        // Base case: if current node is NULL, return prev (new head of the reversed list)
        if (current == NULL) {
            return prev;
        }
        
        // Store the next node
        Node* nextNode = current->next;
        
        // Reverse the link: current's next now points to the previous node
        current->next = prev;
        
        // Recursively reverse the rest of the list and return the new head
        return reverseLL(current, nextNode);
    }
    
    // Function to add one to the number represented by the linked list
    Node* addOne(Node* head) {
        // Initialize pointers for reversing the linked list
        Node* prev = NULL;
        Node* curr = head;
        
        // Reverse the linked list
        head = reverseLL(prev, curr);
        
        // Temporary pointers for traversing and keeping track of the last node
        Node* temp = head;
        Node* temp1 = NULL; // Used to access the last node in case of carry
        int carry = 1; // We are adding one, so initialize carry to 1
        
        // Traverse the reversed list to add one
        while (temp != NULL) {
            temp1 = temp; // Keep track of the last node
            // Calculate total sum and the digit to store
            int totalSum = temp->data + carry;
            int digit = totalSum % 10; // Get the last digit
            carry = totalSum / 10; // Update carry for next iteration
            
            // Update the current node's data with the digit
            temp->data = digit;
            temp = temp->next; // Move to the next node
            
            // If carry is zero, we can break out of the loop
            if (carry == 0) {
                break;
            }
        }
        
        // If there is still a carry after processing all nodes
        if (carry != 0) {
            // Create a new node for the carry and attach it to the last node
            Node* newNode = new Node(carry);
            temp1->next = newNode;
        }
        
        // Reverse the linked list back to its original order
        prev = NULL;
        curr = head;
        head = reverseLL(prev, curr);
        
        // Return the head of the updated list
        return head;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends