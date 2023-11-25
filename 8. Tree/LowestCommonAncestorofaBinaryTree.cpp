class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == p->val) // If the root's value matches node p, return p
        {
            return p;
        }
        if (root->val == q->val) // If the root's value matches node q, return q
        {
            return q;
        }
        TreeNode *leftans = lowestCommonAncestor(root->left, p, q);   // Recursively find p and q in the left subtree
        TreeNode *rightans = lowestCommonAncestor(root->right, p, q); // Recursively find p and q in the right subtree
        if (leftans == NULL && rightans == NULL)                      // If both left and right subtrees return NULL, return NULL
        {
            return NULL;
        }
        else if (leftans != NULL && rightans == NULL) // If only left subtree has the common ancestor, return left subtree's result
        {
            return leftans;
        }
        else if (leftans == NULL && rightans != NULL) // If only right subtree has the common ancestor, return right subtree's result
        {
            return rightans;
        }
        else // If both left and right subtrees have the common ancestor, return the root
        {
            return root;
        }
    }
};
