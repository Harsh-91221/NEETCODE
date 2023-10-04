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
