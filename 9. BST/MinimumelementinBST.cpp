int minVal(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    Node *curr = root;
    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr->data;
}