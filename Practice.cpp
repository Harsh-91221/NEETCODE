class Solution
{
public:
    int MOD = 1e9 + 7;
    int solve(int m, int n, int maxMove, int startRow, int startColumn, int moves, vector<vector<vector<int>>> &dp)
    {
        if (startRow >= m || startColumn >= n || startRow < 0 || startColumn < 0)
        {
            return 1;
        }
        if (moves == maxMove)
        {
            return 0;
        }
        if (dp[moves][startRow][startColumn] != -1)
        {
            return dp[moves][startRow][startColumn];
        }
        long long ans = 0;
        ans += solve(m, n, maxMove, startRow, startColumn - 1, moves + 1, dp) % MOD;
        ans += solve(m, n, maxMove, startRow - 1, startColumn, moves + 1, dp) % MOD;
        ans += solve(m, n, maxMove, startRow + 1, startColumn, moves + 1, dp) % MOD;
        ans += solve(m, n, maxMove, startRow, startColumn + 1, moves + 1, dp) % MOD;
        return dp[moves][startRow][startColumn] = ans % MOD;
        ;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(m, n, maxMove, startRow, startColumn, 0, dp);
    }
};