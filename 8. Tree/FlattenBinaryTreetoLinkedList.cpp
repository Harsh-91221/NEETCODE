class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root; // Initialize a pointer to the current node starting from the root
        if (root == NULL)    
        {
            return;
        }
        while (curr) // Iterate through the tree
        {
            if (curr->left) // If the current node has a left subtree
            {
                TreeNode *pred = curr->left; // Find the rightmost node of the left subtree
                while (pred->right)          // Traverse to the rightmost node of the left subtree
                {
                    pred = pred->right;
                }
                pred->right = curr->right; // Connect the rightmost node of left subtree to the right subtree
                curr->right = curr->left;  // Move the entire left subtree to the right
                curr->left = NULL;         // Set the left pointer to NULL
            }
            curr = curr->right; // Move to the next node
        }
    }
};
