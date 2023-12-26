class Solution
{
public:
    int MOD = 1000000007;
    int solve(int n, int k, int target, vector<vector<int>> &dp)
    {
        int ans = 0;
        if (n < 0)
        {
            return 0;
        }
        if (n == 0 && target == 0)
        {
            return 1;
        }
        if (n != 0 && target == 0)
        {
            return 0;
        }
        if (n == 0 && target != 0)
        {
            return 0;
        }
        if (dp[n][target] != -1)
        {
            return dp[n][target];
        }
        for (int i = 1; i <= k; i++)
        {
            int recans = 0;
            if (target - i >= 0)
            {
                ans = (ans % MOD + solve(n - 1, k, target - i, dp) % MOD) % MOD;
            }
        }
        dp[n][target] = ans;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};