// Brute force - Recursion
class Solution
{
public:
    int solve(int n)
    {
        if (n == 1)
        {
            return 2;
        }
        if (n == 2)
        {
            return 3;
        }
        return solve(n - 1) + solve(n - 2);
    }
    int countHousePlacements(int n)
    {
        int ans = solve(n);
        return ans * ans;
    }
};

// Optimal - DP
class Solution
{
public:
    int MOD = 1e9 + 7;
    long long solve(int n, vector<int> &dp)
    {
        if (n == 1)
        {
            return 2;
        }
        if (n == 2)
        {
            return 3;
        }
        if (dp[n] != -1)
        {
            return dp[n] % MOD;
        }
        return dp[n] = (solve(n - 1, dp) + solve(n - 2, dp)) % MOD;
    }
    int countHousePlacements(int n)
    {
        vector<int> dp(n + 1, -1);
        long long ans = solve(n, dp) % MOD;
        return (ans * ans) % MOD;
    }
};