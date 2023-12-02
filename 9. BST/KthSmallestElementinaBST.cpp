class Solution
{
public:
    int kthSmallest(TreeNode *root, int &k)
    {
        if (root == NULL) 
        {
            return -1; 
        }
        int leftans = kthSmallest(root->left, k); // Traverse left subtree
        if (leftans != -1) // If the kth smallest is found in the left subtree
        {
            return leftans; // Return the result
        }
        k--; // Decrement k when visiting a node
        if (k == 0) // If k becomes 0, current node is the kth smallest
        {
            return root->val; // Return the value of the current node
        }
        return kthSmallest(root->right, k); // Traverse right subtree
    }
};
