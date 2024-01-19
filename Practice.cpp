class Solution
{
public:
    int solve(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp)
    {
        if (row == 0 and col < matrix[0].size() and col >= 0)
        {
            return matrix[row][col];
        }
        if (col >= matrix[0].size() or c < 0)
        {
            return INT_MAX;
        }
        if (dp[row][col] != INT_MAX)
        {
            return dp[row][col];
        }
        return dp[row][col] = matrix[row][col] + min(min(solve(matrix, row - 1, col + 1, dp), solve(matrix, row - 1, col, dp)), solve(matrix, row - 1, col - 1, dp));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        int ans = INT_MAX;
        for (int c = 0; c < n; c++)
        {
            ans = min(ans, solve(matrix, m - 1, c, dp));
        }
        return ans;
    }
};