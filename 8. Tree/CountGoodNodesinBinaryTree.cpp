class Solution
{
public:
    void countGoodNodes(TreeNode *root, int &count, int maxi)
    {
        if (root == NULL)
        {
            return;
        }
        // If the current node value is greater than or equal to the maximum encountered value
        // Increment the count and update the maximum value
        if (maxi <= root->val)
        {
            count++;
            maxi = root->val;
        }
        // Recursively traverse left and right subtrees
        countGoodNodes(root->left, count, maxi);
        countGoodNodes(root->right, count, maxi);
    }
    int goodNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int count = 0;                    
        countGoodNodes(root, count, INT_MIN); 
        return count;                     
    }
};
