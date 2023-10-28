class Solution
{
public:
    int M = 1e9 + 7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    long long solve(int ch, int n, vector<vector<long long>> &dp)
    {
        if (n == 0)
        {
            return 1;
        }
        if (dp[ch][n] != -1)
        {
            return dp[ch][n] % M;
        }
        if (ch == a)
        {
            return dp[ch][n] = solve(e, n - 1, dp) % M;
        }
        else if (ch == e)
        {
            return dp[ch][n] = (solve(a, n - 1, dp) + solve(i, n - 1, dp)) % M;
        }
        else if (ch == i)
        {
            return dp[ch][n] = (solve(a, n - 1, dp) + solve(e, n - 1, dp) + solve(o, n - 1, dp) + solve(u, n - 1, dp)) % M;
        }
        else if (ch == o)
        {
            return dp[ch][n] = (solve(i, n - 1, dp) + solve(u, n - 1, dp)) % M;
        }
        else if (ch == u)
        {
            return dp[ch][n] = solve(a, n - 1, dp) % M;
        }
        return 0;
    }
    int countVowelPermutation(int n)
    {
        long result = 0;
        vector<vector<long long>> dp(5, vector<long long>(n + 1, -1));
        result = (result + solve(a, n - 1, dp)) % M;
        result = (result + solve(e, n - 1, dp)) % M;
        result = (result + solve(i, n - 1, dp)) % M;
        result = (result + solve(o, n - 1, dp)) % M;
        result = (result + solve(u, n - 1, dp)) % M;
        return result;
    }
};