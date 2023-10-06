// BRUTE FORCE
// T.C - O(nlog(n))
// S.C - O(n)
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        vector<int> ans;
        ListNode *temp = head;
        while (temp != NULL)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        sort(ans.begin(), ans.end());
        temp = head;
        for (int i = 0; i < ans.size(); i++)
        {
            temp->val = ans[i];
            temp = temp->next;
        }
        return head;
    }
};

// OPTIMAL
// T.C - O(nlog(n))
// S.C - O(1)
class Solution
{
public:
    ListNode *midnode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *mergesort(ListNode *h1, ListNode *h2)
    {
        if (h1 == NULL)
        {
            return h2;
        }
        if (h2 == NULL)
        {
            return h1;
        }
        ListNode *ans = new ListNode(0);
        ListNode *curr = ans;
        while (h1 != NULL && h2 != NULL)
        {
            if (h1->val < h2->val)
            {
                curr->next = h1;
                h1 = h1->next;
            }
            else
            {
                curr->next = h2;
                h2 = h2->next;
            }
            curr = curr->next;
        }
        if (h1 != NULL)
        {
            curr->next = h1;
            h1 = h1->next;
        }
        if (h2 != NULL)
        {
            curr->next = h2;
            h2 = h2->next;
        }
        return ans->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *mid = midnode(head);
        ListNode *newhead = mid->next;
        mid->next = NULL;
        ListNode *lefthalf = sortList(head);
        ListNode *righthalf = sortList(newhead);
        return mergesort(lefthalf, righthalf);
    }
};