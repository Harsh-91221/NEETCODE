/*
    Given array of k sorted linked-lists, merge all into 1 sorted list
    Ex. lists = [[1,4,5],[1,3,4],[2,6]] -> [1,1,2,3,4,4,5,6]

    Min heap -> optimize space w/ divide-and-conquer, merge 2 each time

    Time: O(n log k)
    Space: O(1)
*/
class Solution
{
public:
    ListNode *Mergetwosortedlist(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        if (l1->val < l2->val)
        {
            l1->next = Mergetwosortedlist(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = Mergetwosortedlist(l1, l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode *PartitionandMerge(vector<ListNode *> &lists, int s, int e)
    {
        if (s > e)
        {
            return NULL;
        }
        if (s == e)
        {
            return lists[s];
        }
        int mid = s + (e - s) / 2;
        ListNode *l1 = PartitionandMerge(lists, s, mid);
        ListNode *l2 = PartitionandMerge(lists, mid + 1, e);
        return Mergetwosortedlist(l1, l2);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return NULL;
        }
        return PartitionandMerge(lists, 0, lists.size() - 1);
    }
};