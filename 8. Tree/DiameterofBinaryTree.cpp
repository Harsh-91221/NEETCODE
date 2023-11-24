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
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        // Recursively find the diameters of left and right subtrees
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        // Calculate the potential diameter passing through the current node
        int throughRoot = maxDepth(root->left) + maxDepth(root->right);
        // Return the maximum among diameters of subtrees and potential diameter through the root
        return max(leftDiameter, max(rightDiameter, throughRoot));
    }
};
