class Solution
{
public:
    // Function to find the maximum value in a subtree
    int maxVal(TreeNode *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root->val;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        // If the current node's value matches the key
        if (root->val == key)
        {
            // Case 1: Node has no children
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // Case 2: Node has only a left child
            else if (root->left != NULL && root->right == NULL)
            {
                TreeNode *child = root->left;
                delete root;
                return child;
            }
            // Case 3: Node has only a right child
            else if (root->left == NULL && root->right != NULL)
            {
                TreeNode *child = root->right;
                delete root;
                return child;
            }
            // Case 4: Node has both left and right children
            else
            {
                // Find the inorder predecessor (maximum value in the left subtree)
                int inorderPre = maxVal(root->left);
                root->val = inorderPre;
                root->left = deleteNode(root->left, inorderPre);
                return root;
            }
        }
        // If the key is smaller, go to the left subtree
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        // If the key is larger, go to the right subtree
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
