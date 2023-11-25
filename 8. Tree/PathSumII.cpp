class Solution
{
public:
    void solve(TreeNode *root, int targetSum, int sum, vector<int> temp, vector<vector<int>> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL) // If the node is a leaf node
        {
            temp.push_back(root->val); // Add the value to the temporary path
            sum += root->val;          // Update the sum
            if (sum == targetSum)      // If the sum matches the targetSum
            {
                ans.push_back(temp); // Add the current path to the answer
            }
            return;
        }
        temp.push_back(root->val);                     // Add the node's value to the temporary path
        sum += root->val;                              // Update the sum
        solve(root->left, targetSum, sum, temp, ans);  // Recursively explore left subtree
        solve(root->right, targetSum, sum, temp, ans); // Recursively explore right subtree
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> temp;
        solve(root, targetSum, sum, temp, ans);
        return ans;
    }
};
