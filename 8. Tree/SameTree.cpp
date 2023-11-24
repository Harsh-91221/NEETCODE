class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // If both nodes are NULL, they are identical
        if (p == NULL && q == NULL)
        {
            return true;
        }
        // If one node is NULL while the other is not, they are different
        if (p != NULL && q == NULL)
        {
            return false;
        }
        if (p == NULL && q != NULL)
        {
            return false;
        }
        // Recursively check the left and right subtrees for equality
        bool leftEqual = isSameTree(p->left, q->left);
        bool rightEqual = isSameTree(p->right, q->right);
        // Check if the current nodes have the same value
        bool currentEqual = p->val == q->val;
        // Return true only if both subtrees and current nodes are equal
        return leftEqual && rightEqual && currentEqual;
    }
};
