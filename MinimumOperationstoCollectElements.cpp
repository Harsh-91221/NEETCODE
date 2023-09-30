class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        unordered_set<int> s;
        int operations = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            operations++;
            if (nums[i] <= k)
            {
                s.insert(nums[i]);
            }
            if (s.size() == k)
            {
                return operations;
            }
        }
        return 0;
        // int len = nums.size();
        // set<int> s;
        // for (int i = 1; i <= k; i++)
        // {
        //     s.insert(i);
        // }
        // int count = 0;
        // for (int i = len - 1; i >= 0; i--)
        // {
        //     int val = nums[i];
        //     if (s.count(val))
        //     {
        //         s.erase(val);
        //     }
        //     count++;
        //     if (s.empty())
        //     {
        //         break;
        //     }
        // }
        // return (s.empty()) ? count : -1;
    }
};