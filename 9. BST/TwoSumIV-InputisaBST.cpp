class Solution
{
public:
    // Perform inorder traversal to get sorted elements in 'inorder' vector
    void inorderTraverse(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return;
        }
        inorderTraverse(root->left, inorder);  // Traverse left subtree
        inorder.push_back(root->val);          // Store current node value in 'inorder'
        inorderTraverse(root->right, inorder); // Traverse right subtree
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        inorderTraverse(root, inorder);
        int s = 0;
        int e = inorder.size() - 1;

        while (s < e)
        {
            int sum = inorder[s] + inorder[e];
            if (sum == k)
            {
                return true;
            }
            else if (sum < k)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        return false;
    }
};
