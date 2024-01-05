class Solution
{
public:
    int solve(vector<int> &nums, int i, int prev, vector<vector<int>> &dp)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        if (dp[i][prev + 1] != -1)
        {
            return dp[i][prev + 1];
        }
        int include = 0;
        if (prev == -1 || nums[i] > nums[prev])
            include = 1 + solve(nums, i + 1, i, dp);
        int exclude = solve(nums, i + 1, prev, dp);
        int ans = max(include, exclude);
        return dp[i][prev + 1] = ans;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int prev = -1;
        return solve(nums, 0, prev, dp);
    }
};