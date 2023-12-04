class Solution
{
public:
    TreeNode *converttoBST(ListNode *start, ListNode *end)
    {
        // Base case: when start reaches end, return NULL
        if (start == end)
        {
            return NULL;
        }
        // Initialize pointers for finding the midpoint
        ListNode *slow = start;
        ListNode *fast = start;
        // Find the midpoint using slow and fast pointers
        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Create a TreeNode with the value of the midpoint
        TreeNode *head = new TreeNode(slow->val);
        // Recursively build left and right subtrees
        head->left = converttoBST(start, slow);
        head->right = converttoBST(slow->next, end);
        return head;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        // Call the helper function with start as head and end as NULL
        return converttoBST(head, NULL);
    }
};
