class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *reversekahead = reverse(slow);
        ListNode *temp1 = head;
        ListNode *temp2 = reversekahead;
        while (temp2 != NULL)
        {
            if (temp1->val != temp2->val)
            {
                return false;
            }
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return true;
    }
};