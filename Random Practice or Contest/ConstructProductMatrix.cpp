class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        long long p = 1;
        int MOD = 12345;
        vector<vector<int>> ans(n, vector<int>(m));
        vector<vector<int>> prefix(n, vector<int>(m));
        vector<vector<int>> suffix(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefix[i][j] = p;
                p = p * grid[i][j];
                p = p % MOD;
            }
        }
        p = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                suffix[i][j] = p;
                p = p * grid[i][j];
                p = p % MOD;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                long long mul = prefix[i][j] * suffix[i][j];
                ans[i][j] = mul % MOD;
            }
        }
        return ans;
    }
};