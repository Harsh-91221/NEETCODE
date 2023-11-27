class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
        {
            return vector<vector<int>>();
        }
        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *Node = q.front();
                q.pop();
                int index = (leftToRight) ? i : (size - 1 - i);
                row[index] = Node->val;
                if (Node->left)
                {
                    q.push(Node->left);
                }
                if (Node->right)
                {
                    q.push(Node->right);
                }
            }
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};