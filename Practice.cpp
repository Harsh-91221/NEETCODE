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
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &postindex, int size, int inorderstart, int inorderend)
    {
        if (postindex < 0 || inorderstart > inorderend)
        {
            return NULL;
        }
        int element = postorder[postindex];
        postindex--;
        TreeNode *root = new TreeNode(element);
        int pos = find(inorder, size, element);
        root->right = solve(inorder, postorder, postindex, size, pos + 1, inorderend);
        root->left = solve(inorder, postorder, postindex, size, inorderstart, pos - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int postindex = postorder.size() - 1;
        return solve(inorder, postorder, postindex, inorder.size(), 0, inorder.size() - 1);
    }
};