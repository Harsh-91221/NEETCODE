class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode *removeNodes(ListNode *head)
    {
        head = reverse(head);  // Reverse the list to start from the maximum value node.
        ListNode *curr = head; // Store the current pointer at the beginning of the reversed list.
        int maxi = head->val;  // Initialize the maximum value as the value of the first node.
        ListNode *prev = head; // Store the previous pointer as the current node.
        head = head->next;     // Move the head pointer to the next node.
        // Traverse through the list to remove nodes with values less than the maximum value.
        while (head != NULL)
        {
            if (head->val >= maxi) // If the current node has a value greater than or equal to the maximum value.
            {
                maxi = head->val;  // Update the maximum value.
                prev = head;       // Update the previous pointer.
                head = head->next; // Move to the next node.
            }
            else
            {
                prev->next = head->next; // Remove the current node by updating the next pointer of the previous node.
                head = prev->next;       // Move to the next node.
            }
        }
        head = reverse(curr); // Reverse the list again to restore the original order.
        return head;
    }
};
