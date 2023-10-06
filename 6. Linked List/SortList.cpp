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