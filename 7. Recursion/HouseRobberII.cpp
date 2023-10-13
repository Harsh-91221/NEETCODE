// Brute force - Recursion
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
        vector<int> temp1;
        vector<int> temp2;
        if (n == 1)
        {
            return nums[0];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0)
            {
                temp1.push_back(nums[i]);
            }
            if (i != n - 1)
            {
                temp2.push_back(nums[i]);
            }
        }
        int exclude_first = solve(temp1, 0, 0, INT_MIN);
        int exclude_last = solve(temp2, 0, 0, INT_MIN);
        return max(exclude_first, exclude_last);
    }
};

// Optimal - DP
class Solution
{
public:
    int solve(vector<int> &nums, int i, int sum, int maxi, vector<int> &dp)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int include = nums[i] + solve(nums, i + 2, sum, maxi, dp);
        int exclude = solve(nums, i + 1, sum, maxi, dp);
        return dp[i] = max(include, exclude);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        vector<int> temp1;
        vector<int> temp2;
        if (n == 1)
        {
            return nums[0];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0)
            {
                temp1.push_back(nums[i]);
            }
            if (i != n - 1)
            {
                temp2.push_back(nums[i]);
            }
        }
        int exclude_first = solve(temp1, 0, 0, INT_MIN, dp);
        dp.assign(n + 1, -1);
        int exclude_last = solve(temp2, 0, 0, INT_MIN, dp);
        return max(exclude_first, exclude_last);
    }
};
