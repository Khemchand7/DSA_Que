//{ Driver Code Starts
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

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    // Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast!=NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow){
                //is point pr hume pata laga ki loop exist karti hai aur pointers hume isi point pr chaie the
                break;
            }
        }
        if(fast == NULL) return -1;
        //loop se bahar hum us point pr khade hai jahan hume pata chala loop exist karti hai
        slow = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        //ab loop se bahar aae to fast aur slow equal hai aur wo loop ka starting point hoga
        return slow->data;
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
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        int ans = ob.findFirstNode(head);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends