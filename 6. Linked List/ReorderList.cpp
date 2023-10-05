/*
    Given head of linked-list, reorder list alternating outside in
    Ex. head = [1,2,3,4] -> [1,4,2,3], head = [1,2,3,4,5] -> [1,5,2,4,3]

    Find middle node, split in half, reverse 2nd half of list, merge

    Time: O(n)
    Space: O(1)
*/
class Solution
{
public:
    ListNode *reverse(ListNode *list2)
    {
        if (list2 == NULL)
        {
            return NULL;
        }
        ListNode *prev = NULL;
        ListNode *curr = list2;
        ListNode *forward = curr->next;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    // Function to merge two linked lists alternately
    void merge(ListNode *list1, ListNode *list2)
    {
        while (list2 != NULL)
        {
            ListNode *forward = list1->next;
            list1->next = list2;
            list1 = list2;
            list2 = forward;
        }
    }
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        // Finding the middle of the linked list
        while (fast != NULL && fast->next != NULL)
        {
            // prev stores the element before the middle to break the list
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // Break the list into two parts
        prev->next = NULL;
        ListNode *list1 = head;
        // Reverse the second part of the linked list
        ListNode *list2 = reverse(slow);
        // Merge the two lists alternately
        merge(list1, list2);
    }
};
