int solve(vector<int> &nums, int i, int &maxi, vector<int> &dp)
{
    if (i >= nums.size())
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int include = nums[i] + solve(nums, i + 2, maxi, dp);
    int exclude = solve(nums, i + 1, maxi, dp);
    dp[i] = max(include, exclude);
}