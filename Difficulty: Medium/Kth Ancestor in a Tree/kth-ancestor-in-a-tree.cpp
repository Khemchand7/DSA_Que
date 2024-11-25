//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
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
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function

bool solve(Node* root, int& k, int node, int& ans) {
    // **Base Case 1:** If the current node is NULL, the target node cannot be found in this subtree.
    if (root == NULL) {
        return false;
    }

    // **Base Case 2:** If the current node matches the target node, return true.
    // This signals that the node is found, and we begin moving up the recursion stack.
    if (root->data == node) {
        return true;
    }

    // **Recursive Calls:**
    // Search for the target node in the left and right subtrees.
    bool leftKaAns = solve(root->left, k, node, ans);
    bool rightKaAns = solve(root->right, k, node, ans);

    // **Processing After Recursive Calls:**
    // If the target node is found in either the left or right subtree:
    if (leftKaAns || rightKaAns) {
        // Decrement `k` to indicate that we are one level closer to the ancestor.
        --k;

        // **Check if this node is the kth ancestor:**
        if (k == 0) {
            ans = root->data; // Store the current node's value as the kth ancestor.
        }

        // Return true to continue propagating the success of finding the target node.
        return true;
    }

    // If the target node is not found in either subtree, return false.
    return false;
}

int kthAncestor(Node* root, int k, int node) {
    // Initialize `ans` to store the result (-1 indicates no ancestor found).
    int ans = -1;

    // Start the recursive function to find the kth ancestor.
    solve(root, k, node, ans);

    // Return the result after the recursive traversal.
    return ans;
}
/*
Logic for Finding the kth Ancestor of a Node in a Binary Tree
Concept:
The problem requires finding the kth ancestor of a given node in a binary tree.
To achieve this:
We traverse the tree recursively, searching for the target node.
Once the target node is found, we move up the recursive stack, decrementing k at each level.
When k == 0, the current node in the recursion stack is the kth ancestor.
*/
