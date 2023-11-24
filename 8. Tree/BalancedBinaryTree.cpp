class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        // Recursively find the maximum depth of the left subtree
        int leftDepth = maxDepth(root->left);
        // Recursively find the maximum depth of the right subtree
        int rightDepth = maxDepth(root->right);
        // Return the maximum depth among left and right subtrees, plus 1 for the current node
        return max(leftDepth, rightDepth) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true; // An empty tree is considered balanced
        }
        // Calculate the depths of left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        // Check if the subtrees are balanced and the difference in depth is within 1
        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);
        bool balancedDiff = (abs(leftDepth - rightDepth) <= 1);
        // Return true only if both subtrees are balanced and the depth difference is acceptable
        return leftBalanced && rightBalanced && balancedDiff;
    }
};
