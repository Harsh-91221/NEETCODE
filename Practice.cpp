class Solution
{
public:
    int n;
    int solve(int prev, int i, vector<int> &nums, int k, vector<int> &dp)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int result = 0;
        if (prev == -1 || i - prev <= k)
        {
            int take = nums[i] + solve(i, i + 1, nums, k, dp);
            int not_take = solve(prev, i + 1, nums, k, dp);
            result = max(take, not_take);
        }
        return dp[i] = result;
    }
    int constrainedSubsetSum(vector<int> &nums, int k)
    {

        n = nums.size();
        vector<int> dp(n + 1, -1);
        int ans = solve(-1, 0, nums, k, dp);
        if (ans == 0)
        {
            ans = *max_element(nums.begin(), nums.end());
        }
        return ans;
    }
};