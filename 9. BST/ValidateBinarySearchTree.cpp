class Solution
{
public:
    bool solve(TreeNode *root, long long int lowerbound, long long int upperbound)
    {
        if (root == NULL)
        {
            return true;
        }
        // Checking if the current node's value lies within the specified bounds
        if (root->val > lowerbound && root->val < upperbound)
        {
            // Recursively check the left subtree with updated upperbound as current node's value
            bool leftans = solve(root->left, lowerbound, root->val);
            // Recursively check the right subtree with updated lowerbound as current node's value
            bool rightans = solve(root->right, root->val, upperbound);
            // Return true only if both subtrees are valid BSTs
            return leftans && rightans;
        }
        else
        {
            // If the current node's value violates the BST property, return false
            return false;
        }
    }
    bool isValidBST(TreeNode *root)
    {
        long long int lowerbound = -4294967296; // Lowerbound for INT_MIN
        long long int upperbound = 4294967296;  // Upperbound for INT_MAX
        return solve(root, lowerbound, upperbound);
    }
};
