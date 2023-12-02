class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        // If both nodes are less than the current node, recurse on the left subtree
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        // If both nodes are greater than the current node, recurse on the right subtree
        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        // If the nodes are on different sides or one of them is the current node,
        // then the current node is the lowest common ancestor
        return root;
    }
};
