/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *temp = new ListNode(0);
        while (curr != NULL)
        {
            ListNode *forward = curr->next;
            ListNode *tempHead = temp;
            while (tempHead->next != NULL && tempHead->next->val < curr->val)
            {
                tempHead = tempHead->next;
            }
            curr->next = tempHead->next;
            tempHead->next = curr;
            curr = forward;
        }
        return temp->next;
    }
};