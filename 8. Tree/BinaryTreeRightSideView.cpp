class Solution
{
public:
    void solve(TreeNode *root, vector<int> &ans, int level)
    {
        if (root == NULL)
        {
            return;
        }
        if (level == ans.size())
        {                             // Check if the level matches the current size of ans
            ans.push_back(root->val); // If yes, add the current node's data to ans
        }
        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};