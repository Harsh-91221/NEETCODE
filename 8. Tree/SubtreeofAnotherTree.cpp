class Solution
{
public:
    bool isSame(TreeNode *root, TreeNode *subRoot)
    {
        // Both nodes are NULL, indicating sameness
        if (root == NULL && subRoot == NULL)
        {
            return true;
        }
        // One node is NULL while the other is not, indicating difference
        if (root != NULL && subRoot == NULL)
        {
            return false;
        }
        if (root == NULL && subRoot != NULL)
        {
            return false;
        }
        // Values of the current nodes are different
        if (root->val != subRoot->val)
        {
            return false;
        }
        // Recursively check left and right subtrees for sameness
        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        // Both nodes are NULL, indicating the subtree exists (an empty tree is a subtree of any tree)
        if (root == NULL && subRoot == NULL)
        {
            return true;
        }
        // One node is NULL while the other is not, indicating difference
        if (root != NULL && subRoot == NULL)
        {
            return false;
        }
        if (root == NULL && subRoot != NULL)
        {
            return false;
        }
        // Check if the subtrees starting at root and subRoot are the same
        if (isSame(root, subRoot))
        {
            return true;
        }
        // Recursively check left and right subtrees of the main tree for the subtree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
