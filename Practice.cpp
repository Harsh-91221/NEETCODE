class Solution
{
public:
    int solve(vector<int> &nums, vector<int> &pattern, int i, int j)
    {
        if (j == pattern.size())
        {
            return 1;
        }
        if (i == nums.size() - 1)
        {
            return 0;
        }
        if ((pattern[j] == 0 && nums[i] == nums[i + 1]) || (pattern[j] == 1 && nums[i] < nums[i + 1]) || (pattern[j] == -1 && nums[i] > nums[i + 1]))
        {
            return solve(nums, pattern, i + 1, j + 1);
        }
        return 0;
    }
    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += solve(nums, pattern, i, 0);
        }
        return count;
    }
};