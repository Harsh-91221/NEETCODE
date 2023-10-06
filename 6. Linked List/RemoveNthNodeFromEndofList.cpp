/*
    Given head of a linked list, remove nth node from end of list
    Ex. head = [1,2,3,4,5], n = 2 -> [1,2,3,5]

    Create 2 pointers "n" apart, iterate until end, will be at nth

    Time: O(n)
    Space: O(1)
*/
// BRUTE FORCE
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *reverseHead = reverse(head);
        ListNode *curr = reverseHead;
        int i = 1;
        if (n == 1)
        {
            ListNode *newhead = curr->next;
            curr->next = NULL;
            delete reverseHead;
            return reverse(newhead);
        }
        ListNode *prev = NULL;
        while (i < n)
        {
            prev = curr;
            curr = curr->next;
            i++;
        }
        if (prev != NULL)
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
        ListNode *result = reverse(reverseHead);
        return result;
    }
};

// OPTIMAL
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *slow = dummy;
    ListNode *fast = dummy;
    int i = 1;
    while (i <= n)
    {
        fast = fast->next;
        i++;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
};
