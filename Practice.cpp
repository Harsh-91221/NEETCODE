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
        int element = preorder[preindex++];
        TreeNode *root = new TreeNode(element);
        int pos = find(inorder, size, element);
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