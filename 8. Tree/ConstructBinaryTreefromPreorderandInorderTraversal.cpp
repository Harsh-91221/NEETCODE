class Solution
{
public:
    // Function to find the index of an element in inorder traversal
    int find(vector<int> &inorder, int size, int element)
    {
        for (int i = 0; i < size; i++)
        {
            if (inorder[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preindex, int size, int inorderstart, int inorderend)
    {
        if (preindex >= size || inorderstart > inorderend)
        {
            return NULL;
        }
        // Create a new node using the current element from preorder
        int element = preorder[preindex++];
        TreeNode *root = new TreeNode(element);

        // Find the position of the element in inorder traversal
        int pos = find(inorder, size, element);

        // Recursively build left and right subtrees
        root->left = solve(preorder, inorder, preindex, size, inorderstart, pos - 1);
        root->right = solve(preorder, inorder, preindex, size, pos + 1, inorderend);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int preindex = 0;
        return solve(preorder, inorder, preindex, inorder.size(), 0, inorder.size() - 1);
    }
};
