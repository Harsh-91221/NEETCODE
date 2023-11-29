class Solution
{
public:
    void countgood(TreeNode *root, int &count, int maxi)
    {
        if (root == NULL)
        {
            return;
        }
        if (maxi <= root->val)
        {
            count++;
            maxi = root->val;
        }
        countgood(root->left, count, maxi);
        countgood(root->right, count, maxi);
    }
    int goodNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        int count = 0;
        countgood(root, count, INT_MIN);
        return count;
    }
};