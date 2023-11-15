Node *segregateEvenOdd(Node *head)
{
    Node *even = NULL;
    Node *odd = NULL;
    Node *tempeven = NULL;
    Node *tempodd = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        Node *add = new Node(temp->data);
        if (temp->data % 2 == 0)
        {
            if (even == NULL)
            {
                even = add;
                tempeven = add;
            }
            else
            {
                tempeven->next = add;
                tempeven = add;
            }
        }
        else
        {
            if (odd == NULL)
            {
                odd = add;
                tempodd = add;
            }
            else
            {
                tempodd->next = add;
                tempodd = tempodd->next;
            }
        }
        temp = temp->next;
    }
    if (even != NULL)
    {
        Node *head = even;
        while (even->next != NULL)
        {
            even = even->next;
        }
        even->next = odd;
        return head;
    }
    return odd;
}
