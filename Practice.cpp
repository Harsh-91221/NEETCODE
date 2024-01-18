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
    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;;
        }
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            ListNode *node = new ListNode(gcd(temp->val, temp->next->val));
            ListNode *forward = temp->next;
            temp->next = node;
            node->next = forward;
            temp = forward;
        }
        return head;
    }
};