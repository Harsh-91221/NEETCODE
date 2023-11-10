class Solution
{
public:
    int solve(int i, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        if (target < 0)
        {
            return -nums.size();
        }
        if (target == 0)
        {
            return 0;
        }
        if (i >= nums.size())
        {
            return -nums.size();
        }
        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        return dp[i][target] = max(1 + solve(i + 1, nums, target - nums[i], dp), solve(i + 1, nums, target, dp));
    }
    int lengthOfLongestSubsequence(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = solve(0, nums, target, dp);
        if (ans <= 0)
        {
            return -1;
        }
        return ans;
    }
};