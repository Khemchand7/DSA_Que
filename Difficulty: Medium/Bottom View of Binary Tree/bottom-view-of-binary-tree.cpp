//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

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
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    // Function to return a list of nodes visible from the bottom view
    // from left to right in a Binary Tree.
    vector<int> bottomView(Node *root) {
        // Map to store the last node encountered at each horizontal distance (HD).
        map<int, int> hdToNodeMap;
        
        // Queue to perform level-order traversal.
        // It stores pairs of (Node pointer, horizontal distance).
        queue<pair<Node*, int>> q;
        
        // Vector to store the final bottom view of the binary tree.
        vector<int> ans;
        
        // Initialize the queue with the root node and its horizontal distance (0).
        q.push(make_pair(root, 0));
        
        // Perform level-order traversal.
        while (!q.empty()) {
            // Extract the front node from the queue.
            pair<Node*, int> front = q.front();
            q.pop();
            
            // Get the current node and its horizontal distance.
            Node* temp = front.first;
            int level = front.second;
            
            // Update the map with the current node's data.
            // This ensures that the last node at this HD will remain in the map,
            // effectively representing the bottom view.
            hdToNodeMap[level] = temp->data;
            
            // If the left child exists, add it to the queue with HD decremented by 1.
            if (temp->left != NULL) {
                q.push(make_pair(temp->left, level - 1));
            }
            
            // If the right child exists, add it to the queue with HD incremented by 1.
            if (temp->right != NULL) {
                q.push(make_pair(temp->right, level + 1));
            }
        }
        
        // Traverse the map to extract the bottom view in order of horizontal distance.
        for (const auto &val : hdToNodeMap) {
            ans.push_back(val.second); // Add the node value to the result vector.
        }
        
        // Return the bottom view.
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}



// } Driver Code Ends