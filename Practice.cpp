Node *uniqueSortedList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->next != NULL && (curr->data == curr->next->data))
        {
            Node *next1 = curr->next->next;
            Node *nodetodelete = curr->next;
            delete (nodetodelete);
            curr->next = next1;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}