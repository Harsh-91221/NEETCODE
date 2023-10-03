class Solution
{
public:
    ListNode *solve(ListNode *list1, ListNode *list2)
    {
        if (list1->next == NULL)
        {
            list1->next = list2;
            return list1;
        }
        ListNode *curr1 = list1;
        ListNode *curr2 = list2;
        ListNode *next1 = curr1->next;
        ListNode *next2 = curr2->next;
        while (next1 != NULL && curr2 != NULL)
        {
            if (curr1->val <= curr2->val && curr2->val <= next1->val)
            {
                // ADD NODES IN BETWEEN THE FIRST LIST
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;
                // UPDATE POINTERS
                curr1 = curr2;
                curr2 = next2;
            }
            else
            {
                // CURR1 AUR NEXT1 KO AAGE BADANA PADEGA
                curr1 = next1;
                next1 = next1->next;
                if (next1 == NULL)
                {
                    curr1->next = curr2;
                    return list1;
                }
            }
        }
        return list1;
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }
        if (list1->val <= list2->val)
        {
            return solve(list1, list2);
        }
        else
        {
            return solve(list2, list1);
        }
    }
};