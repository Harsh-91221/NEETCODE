/*
    Given 2 linked lists, digits stored in reverse order, add them
    Ex. l1 = [2,4,3] l2 = [5,6,4] -> [7,0,8] (342 + 465 = 807)

    Sum digit-by-digit + carry, handle if one list becomes null

    Time: O(max(m, n))
    Space: O(max(m, n))
*/
class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        ListNode *head1 = l1;
        ListNode *head2 = l2;
        // ADD BOTH LINKED LIST
        ListNode *anshead = NULL;
        ListNode *anstail = NULL;
        int carry = 0;
        while (head1 != NULL && head2 != NULL)
        {
            // Find sum
            int sum = carry + head1->val + head2->val;
            // Find digit to create node
            int digit = sum % 10;

            // Calculate carry
            carry = sum / 10;

            // Create a new node for digit
            ListNode *newnode = new ListNode(digit);
            // Attach the newnode to the anshead list
            if (anshead == NULL)
            {
                // First node insert kr rahe ho
                anshead = newnode;
                anstail = newnode;
            }
            else
            {
                anstail->next = newnode;
                anstail = newnode;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        // Jab head1 ki length head2 se jyada hogi
        while (head1 != NULL)
        {
            int sum = carry + head1->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode *newnode = new ListNode(digit);
            anstail->next = newnode;
            anstail = newnode;
            head1 = head1->next;
        }
        // Jab head2 ki length head1 se jyada hogi
        while (head2 != NULL)
        {
            int sum = carry + head2->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode *newnode = new ListNode(digit);
            anstail->next = newnode;
            anstail = newnode;
            head2 = head2->next;
        }
        // Handle karo carry ko alag se
        while (carry != NULL)
        {
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode *newnode = new ListNode(digit);
            anstail->next = newnode;
            anstail = newnode;
        }
        return anshead;
    }
};