/*
    Given head of a linked list, determine if it has a cycle in it

    Slow/fast pointers, if they ever intersect then there's a cycle

    Time: O(n)
    Space: O(1)
*/
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};