class Solution
{
public:
    long long MOD = 1e9 + 7;
    long long solve(int steps, int len, int i, vector<vector<long long>> &dp)
    {
        if (i < 0 || i >= len)
        {
            return 0; // If i is out of bounds, there are 0 ways to reach it.
        }
        if (steps == 0)
        {
            if (i == 0)
            {
                return 1; // If i is back at the starting position with no steps left, there is 1 way.
            }
            else
            {
                return 0; // If i is not at the starting position with no steps left, there are 0 ways.
            }
        }
        if (dp[steps][i] != -1)
        {
            return dp[steps][i] % MOD;
        }
        long long right = solve(steps - 1, len, i + 1, dp) % MOD; // Moving right.
        long long left = solve(steps - 1, len, i - 1, dp) % MOD;  // Moving left.
        long long stay = solve(steps - 1, len, i, dp) % MOD;      // Staying in the current position.
        return dp[steps][i] = (left + right + stay) % MOD;
    }
    int numWays(int steps, int arrLen)
    {
        int n = min(steps, arrLen);
        vector<vector<long long>> dp(steps + 1, vector<long long>(2 * n + 1, -1));
        return solve(steps, arrLen, 0, dp);
    }
};
