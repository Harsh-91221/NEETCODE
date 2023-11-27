class Solution
{
public:
    // Function to find the index of an element in the inorder traversal
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
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &postindex, int size, int inorderstart, int inorderend)
    {
        if (postindex < 0 || inorderstart > inorderend)
        {
            return NULL;
        }
        int element = postorder[postindex--];   // Decrement postorder index and retrieve element
        TreeNode *root = new TreeNode(element); // Create new node with the element
        int pos = find(inorder, size, element); // Find element's position in inorder traversal
        // Recursively build right and left subtrees
        root->right = solve(inorder, postorder, postindex, size, pos + 1, inorderend);
        root->left = solve(inorder, postorder, postindex, size, inorderstart, pos - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int postindex = postorder.size() - 1; // Initialize postorder index
        return solve(inorder, postorder, postindex, inorder.size(), 0, inorder.size() - 1);
    }
};
