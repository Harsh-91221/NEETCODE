int lengthOfLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *entry = head;
    int count = 1;
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (slow != entry)
            {
                entry = entry->next;
                slow = slow->next;
            }
            Node *p = entry;
            while (p->next != entry)
            {
                count++;
                p = p->next;
            }
            return count;
        }
    }
    return 0;
}