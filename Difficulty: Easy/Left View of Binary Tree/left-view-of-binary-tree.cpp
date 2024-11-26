//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};


// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
public:
    // Recursive function to find the left view of the binary tree
    void solve(Node* root, vector<int>& ans, int level) {
        // Base case: If the current node is NULL, return
        if (root == NULL) {
            return;
        }

        // If the current level is being visited for the first time
        if (ans.size() == level) {
            // Add the current node's data to the answer
            ans.push_back(root->data);
        }

        // Recursively traverse the left subtree first to prioritize left view
        solve(root->left, ans, level + 1);

        // Then traverse the right subtree
        solve(root->right, ans, level + 1);
    }
    
    // Function to return the left view of the binary tree
    vector<int> leftView(Node *root) {
        vector<int> ans; // Vector to store the nodes visible from the left view
        int level = 0;   // Start from level 0
        solve(root, ans, level); // Call the helper function
        return ans; // Return the result
    }
};


//{ Driver Code Starts.

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> vec = ob.leftView(root);
        if (vec.size() == 0) {
            cout << "[]";
        }
        for (int x : vec)
            cout << x << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends