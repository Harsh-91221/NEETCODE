class Solution
{
public:
    int solve(vector<int> &nums, int i, int sum, int maxi)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        int include = nums[i] + solve(nums, i + 2, sum, maxi);
        int exclude = solve(nums, i + 1, sum, maxi);
        return max(include, exclude);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }

        vector<int> temp1(nums.begin(), nums.end() - 1);
        vector<int> temp2(nums.begin() + 1, nums.end());

        int exclude_first = solve(temp1, 0, 0, INT_MIN);
        int exclude_last = solve(temp2, 0, 0, INT_MIN);

        return max(exclude_first, exclude_last);
    }
};
