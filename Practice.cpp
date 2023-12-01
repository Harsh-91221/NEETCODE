class Solution
{
public:
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
        if (root->val == key)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                TreeNode *child = root->left;
                delete root;
                return child;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                TreeNode *child = root->right;
                delete root;
                return child;
            }
            else
            {
                int inorderPre = maxVal(root->left);
                root->val = inorderPre;
                root->left = deleteNode(root->left, inorderPre);
                return root;
            }
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};