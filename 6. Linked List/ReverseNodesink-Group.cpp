/*
    Given head of linked list, reverse nodes of list k at a time
    Ex. head = [1,2,3,4,5], k = 2 -> [2,1,4,3,5]

    Maintain prev, curr, & temp pointers to reverse, count k times

    Time: O(n)
    Space: O(1)
*/
class Solution
{
public:
    int getlen(ListNode *head)
    {
        int count = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            return head;
        }
        int len = getlen(head);
        if (k > len)
        {
            return head;
        }
        // STEP 1: REVERSE FIRST K NODES OF LL
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward = curr->next;
        int count = 0;
        while (count < k)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        // STEP 2: RECURSIVE CALL
        if (forward != NULL)
        {
            head->next = reverseKGroup(forward, k);
        }
        return prev;
    }
};