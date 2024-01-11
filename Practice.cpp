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
    int solve(TreeNode *root, int maxval, int minval)
    {
        if (root == NULL)
        {
            return maxval - minval;
        }
        maxval = max(maxval, root->val);
        minval = min(minval, root->val);
        int maxleftdiff = solve(root->left, maxval, minval);
        int maxrightdiff = solve(root->right, maxval, minval);
        return max(maxleftdiff, maxrightdiff);
    }
    int maxAncestorDiff(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return solve(root, root->val, root->val);
    }
};