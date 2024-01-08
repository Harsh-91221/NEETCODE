/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
        {
            return NULL;
        }
        int ans = 0;
        bool range = false;
        if (root->val >= low && root->val <= high)
        {
            range = true;
            ans = ans + root->val;
        }
        if (range)
        {
            ans = ans + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        if (root->val < low)
        {
            ans = ans + rangeSumBST(root->right, low, high);
        }
        if (root->val > high)
        {
            ans = ans + rangeSumBST(root->left, low, high);
        }
        return ans;
    }
};