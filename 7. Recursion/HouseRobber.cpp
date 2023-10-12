// Brute force - Recursion
class Solution
{
public:
    void solve(vector<int> &nums, int i, int sum, int &maxi)
    {
        if (i >= nums.size())
        {
            maxi = max(sum, maxi);
            return;
        }
        solve(nums, i + 2, sum + nums[i], maxi);
        solve(nums, i + 1, sum, maxi);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        solve(nums, 0, sum, maxi);
        return maxi;
    }
};

// Optimal - DP
class Solution
{
public:
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
        return dp[i] = max(include, exclude);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int maxi = INT_MIN;
        return solve(nums, 0, maxi, dp);
    }
};