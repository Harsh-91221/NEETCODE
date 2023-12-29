class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (n < d)
        {
            return -1;
        }
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        for (int i = 0; i < n; i++)
        {
            dp[i][1] = *max_element(jobDifficulty.begin() + i, jobDifficulty.end());
        }
        for (int days = 2; days <= d; days++)
        {
            for (int i = 0; i <= n - days; i++)
            {
                int maxD = INT_MIN;
                int result = INT_MAX;
                for (int j = i; j <= n - days; j++)
                {
                    maxD = max(maxD, jobDifficulty[j]);
                    result = min(result, maxD + dp[j + 1][days - 1]);
                }
                dp[i][days] = result;
            }
        }
        return dp[0][d];
    }
};