class Solution {
public:
    // Finds maximum value in a BST (rightmost node)
    int maxOfTree(TreeNode* root) {
        // Move to the rightmost node
        while (root->right != NULL) {
            root = root->right;
        }
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: empty tree
        if (root == NULL)
            return NULL;

        // Case 1: node to delete found
        if (root->val == key) {

            // 1️⃣ Leaf node
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // 2️⃣ Only left child exists
            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // 3️⃣ Only right child exists
            if (root->right != NULL && root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // 4️⃣ Both children exist
            // Replace with inorder predecessor (max from left subtree)
            int replaceapbleValue = maxOfTree(root->left);
            root->val = replaceapbleValue;

            // Delete the duplicate value from left subtree
            root->left = deleteNode(root->left, replaceapbleValue);
            return root;
        }

        // Case 2: key lies in right subtree
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        // Case 3: key lies in left subtree
        else {
            root->left = deleteNode(root->left, key);
        }

        // Return updated root
        return root;
    }
};
