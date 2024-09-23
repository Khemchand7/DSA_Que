//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/*
   // Redirecting input from file
  freopen("/Users/debojyoti.mandal/expt/input.txt", "r", stdin);

  // Redirecting output to file
  freopen("/Users/debojyoti.mandal/expt/output.txt", "w", stdout);
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        // Return immediately if the list is empty or has only one node
        if (head == NULL) {
            return head;
        }
        if (head->next == NULL) {
            return head;
        }

        Node* temp = head; // Pointer to traverse the linked list

        // Traverse the linked list
        while (temp != NULL && temp->next != NULL) {//possibility hai ki temp->next null ho jae kyuki hum temp->next->data access kar rhe hai
            // Check if the current node's data is the same as the next node's data
            if (temp->data == temp->next->data) {
                Node* nextNode = temp->next; // Store reference to the duplicate node
                temp->next = nextNode->next;  // Bypass the duplicate node
                delete nextNode;               // Free memory of the duplicate node
            } else {
                temp = temp->next; // Move to the next node if no duplicate found
            }
        }
        return head; // Return the head of the modified list
    }
};


//{ Driver Code Starts.

int main() {

    // your code goes here
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
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
        Solution obj;
        int data = arr[0];
        Node *head = new Node(data);
        Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        Node *result = ob.removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends