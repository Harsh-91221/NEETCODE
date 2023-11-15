Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
Node *removeKthNode(Node *head, int K)
{
    Node *dummy = new Node();
    dummy->next = head;
    Node *slow = dummy;
    Node *fast = dummy;
    int i = 1;
    while (i <= K)
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
}
