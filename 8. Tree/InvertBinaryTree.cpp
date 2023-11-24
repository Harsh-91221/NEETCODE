class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        // Invert the right subtree
        invertTree(root->right);
        // Invert the left subtree
        invertTree(root->left);
        // Swap the left and right subtrees of the current node
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};
