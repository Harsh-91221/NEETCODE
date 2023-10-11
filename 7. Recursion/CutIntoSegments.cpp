#include <limits.h>
int solve(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans1 = solve(n - x, x, y, z, dp) + 1;
    int ans2 = solve(n - y, x, y, z, dp) + 1;
    int ans3 = solve(n - z, x, y, z, dp) + 1;
    int ans = 0;
    ans = max(ans1, max(ans2, ans3));
    return dp[n] = ans;
}
int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    int ans = solve(n, x, y, z, dp);
    if (ans < 0)
    {
        return 0;
    }
    return ans;
}