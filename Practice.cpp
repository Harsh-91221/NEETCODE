class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        long long mini = INT_MAX;
        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        for (int i = 1; i * i <= n; i++)
        {
            long long res = 1 + solve(n - i * i, dp);
            mini = min(mini, res);
        }
        return dp[n] = mini;
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};