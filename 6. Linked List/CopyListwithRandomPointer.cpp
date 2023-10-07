/*
    Given linked list w/ also a random pointer, construct deep copy

    Hash map {old -> new}, O(n) space
    Optimize interweave old and new nodes, O(1) space
    A -> A' -> B -> B' -> C -> C', A'.random = A.random.next

    Time: O(n)
    Space:O(1)
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        // Step 1 :Insert new nodes in original linked list
        Node *curr = head;
        while (curr != NULL)
        {
            Node *currnext = curr->next;      // B
            curr->next = new Node(curr->val); // A->B
            curr->next->next = currnext;      // A->x->B
            curr = currnext;                  // curr=B
        }
        // Step 2 : Deep copy of random pointers
        curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            // Agar curr ka random pointer NULL hai toh uska next bhi NULL hoga
            if (curr->random == NULL)
            {
                curr->next->random = NULL;
            }
            else
            {
                // Check karega ki curr ke next ke corresponding konsa random node bana tha
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // Step 3 : Seperate linked list
        Node *newhead = head->next;
        Node *newcurr = newhead;
        curr = head;
        while (curr != NULL && newcurr != NULL)
        {
            if (curr->next == NULL)
            {
                curr->next = NULL;
            }
            else
            {
                curr->next = curr->next->next;
            }
            if (newcurr->next == NULL)
            {
                newcurr->next = NULL;
            }
            else
            {
                newcurr->next = newcurr->next->next;
            }
            curr = curr->next;
            newcurr = newcurr->next;
        }
        return newhead;
    }
};