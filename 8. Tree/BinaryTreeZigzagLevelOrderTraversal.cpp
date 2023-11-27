class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result; // Store the final zigzag traversal
        if (root == NULL)
        {
            return vector<vector<int>>();
        }
        queue<TreeNode *> q;     // Queue for level-order traversal
        q.push(root);            // Push the root node
        bool leftToRight = true; // Flag to determine traversal direction
        while (!q.empty())
        {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *Node = q.front();
                q.pop();
                int index = (leftToRight) ? i : (size - 1 - i); // Determine the index based on traversal direction
                row[index] = Node->val;                         // Store node value in the correct index
                // Add child nodes to the queue if they exist
                if (Node->left)
                {
                    q.push(Node->left);
                }
                if (Node->right)
                {
                    q.push(Node->right);
                }
            }
            leftToRight = !leftToRight; // Change traversal direction for the next level
            result.push_back(row);      // Store the nodes at the current level in the result
        }
        return result; // Return the final zigzag traversal of the tree
    }
};
