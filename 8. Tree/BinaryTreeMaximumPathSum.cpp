class Solution
{
public:
    int solve(TreeNode *root, int &maxi)
    {
        // Base case: if the node is NULL, return 0
        if (root == NULL)
        {
            return 0;
        }
        // Calculate the maximum sum starting from left and right subtrees
        int leftsum = max(0, solve(root->left, maxi));   // Maximum sum from the left subtree
        int rightsum = max(0, solve(root->right, maxi)); // Maximum sum from the right subtree
        // Update the maximum path sum encountered so far
        maxi = max(maxi, leftsum + rightsum + root->val);
        // Return the maximum sum from either the left or right subtree plus the current node's value
        return max(leftsum, rightsum) + root->val;
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        solve(root, maxi); 
        return maxi; 
    }
};
