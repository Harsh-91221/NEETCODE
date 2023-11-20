class Solution
{
public:
    int getlen(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        int len = getlen(head);
        int actualrotateK = (k % len);
        if (actualrotateK == 0)
        {
            return head;
        }
        int newlastnodePos = len - actualrotateK - 1;
        ListNode *newLastNode = head;
        for (int i = 0; i < newlastnodePos; i++)
        {
            newLastNode = newLastNode->next;
        }
        ListNode *newhead = newLastNode->next;
        newLastNode->next = NULL;
        ListNode *it = newhead;
        while (it->next)
        {
            it = it->next;
        }
        it->next = head;
        return newhead;
    }
};