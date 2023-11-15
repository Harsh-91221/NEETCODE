class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *odd = head;             // pointer for odd nodes
        ListNode *even = head->next;      // pointer for even nodes
        ListNode *evenStart = head->next; // pointer to start of even nodes
        // Loop through the list to rearrange odd and even nodes
        while (even != NULL && even->next != NULL)
        {
            // Adjust the pointers to rearrange odd and even nodes
            odd->next = even->next;        // link odd node to the next odd node
            even->next = even->next->next; // link even node to the next even node
            // Move to the next odd and even nodes
            odd = odd->next;
            even = even->next;
        }
        // Connect the last odd node to the start of even nodes
        odd->next = evenStart;
        return head;
    }
};
