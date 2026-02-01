/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // BFS to find target node and build parent mapping
    TreeNode* findTargetNodeAndCreateParentMap(
        TreeNode* root, int start,
        unordered_map<TreeNode*, TreeNode*>& parent) {

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* targetNode = nullptr;

        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            // Capture the start node
            if (currNode->val == start)
                targetNode = currNode;

            // Map left child to its parent
            if (currNode->left) {
                parent[currNode->left] = currNode;
                q.push(currNode->left);
            }

            // Map right child to its parent
            if (currNode->right) {
                parent[currNode->right] = currNode;
                q.push(currNode->right);
            }
        }
        return targetNode;
    }

    // BFS from target node to simulate infection spread
    int burningTreeHelper(TreeNode* root, TreeNode*& targetNode,
                          unordered_map<TreeNode*, TreeNode*>& parent) {

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        // Start infection from target
        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool isBurnt = false;  // tracks if infection spreads this minute

            for (int i = 0; i < size; i++) {
                TreeNode* currNode = q.front();
                q.pop();

                // Spread to left child
                if (currNode->left && !visited[currNode->left]) {
                    isBurnt = true;
                    visited[currNode->left] = true;
                    q.push(currNode->left);
                }

                // Spread to right child
                if (currNode->right && !visited[currNode->right]) {
                    isBurnt = true;
                    visited[currNode->right] = true;
                    q.push(currNode->right);
                }

                // Spread to parent
                if (parent[currNode] && !visited[parent[currNode]]) {
                    isBurnt = true;
                    visited[parent[currNode]] = true;
                    q.push(parent[currNode]);
                }
            }

            // Increase time only if infection spread
            if (isBurnt) time++;
        }

        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;  // root has no parent

        // Step 1: build parent map + find start node
        TreeNode* targetNode =
            findTargetNodeAndCreateParentMap(root, start, parent);

        // Step 2: BFS infection spread
        return burningTreeHelper(root, targetNode, parent);
    }
};
