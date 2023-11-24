class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        // Recursively find the maximum depth of the left subtree
        int leftDepth = maxDepth(root->left);
        // Recursively find the maximum depth of the right subtree
        int rightDepth = maxDepth(root->right);
        // Return the maximum depth among left and right subtrees, plus 1 for the current node
        return max(leftDepth, rightDepth) + 1;
    }
};
