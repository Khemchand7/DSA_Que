//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

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


// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    // Function to traverse and collect the left boundary of the tree (excluding leaf nodes).
    void leftBoundary(Node* root, vector<int>& ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;  // Base case: stop if node is NULL or a leaf node.
        }
        ans.push_back(root->data);  // Add current node's data to the result.
        if (root->left != NULL) {
            leftBoundary(root->left, ans);  // Recur for the left subtree.
        } else {
            leftBoundary(root->right, ans);  // If no left child, recur for the right subtree.
        }
    }

    // Function to traverse and collect all leaf nodes of the tree in left-to-right order.
    void leafNodes(Node* root, vector<int>& ans) {
        if (root == NULL) {
            return;  // Base case: stop if node is NULL.
        }
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);  // Add leaf node's data to the result.
        }
        leafNodes(root->left, ans);  // Recur for the left subtree.
        leafNodes(root->right, ans);  // Recur for the right subtree.
    }

    // Function to traverse and collect the right boundary of the tree in reverse order (excluding leaf nodes).
    void reverseRightBoundary(Node* root, vector<int>& ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;  // Base case: stop if node is NULL or a leaf node.
        }
        if (root->right != NULL) {
            reverseRightBoundary(root->right, ans);  // Recur for the right subtree.
        } else {
            reverseRightBoundary(root->left, ans);  // If no right child, recur for the left subtree.
        }
        ans.push_back(root->data);  // Add current node's data after recursion for reverse order.
    }

    // Main function to perform the boundary traversal of the binary tree.
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;  // If the tree is empty, return an empty vector.

        ans.push_back(root->data);  // Include the root node in the boundary traversal.
        
        // Collect the left boundary nodes (excluding the root and leaf nodes).
        leftBoundary(root->left, ans);
        
        // Collect all leaf nodes in left-to-right order.
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
        
        // Collect the right boundary nodes in reverse order (excluding the root and leaf nodes).
        reverseRightBoundary(root->right, ans);
        
        return ans;  // Return the complete boundary traversal result.
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends