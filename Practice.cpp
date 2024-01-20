class Solution
{
public:
    int solve(int n)
    {
        int count = 0;
        while (n != 0)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    bool canSortArray(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size() - i - 1; j++)
            {
                if (nums[j] > nums[j + 1] && solve(nums[j]) == solve(nums[j + 1]))
                {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};