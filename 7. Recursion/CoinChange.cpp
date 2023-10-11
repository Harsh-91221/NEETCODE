// Brute force - Recursion
class Solution
{
public:
    int solve(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            return -1;
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solve(coins, amount - coins[i]);
            // To ignore the -1 case
            if (ans != -1)
            {
                mini = min(mini, ans + 1);
            }
        }
        if (mini == INT_MAX)
        {
            return -1;
        }
        else
        {
            return mini;
        }
    }
    int coinChange(vector<int> &coins, int amount)
    {
        return solve(coins, amount);
    }
};

// Optimal - DP
class Solution
{
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            return INT_MAX;
        }
        if (dp[amount] != -1)
        {
            return dp[amount];
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solve(coins, amount - coins[i], dp);
            if (ans != INT_MAX)
            {
                mini = min(mini, ans + 1);
            }
        }
        return dp[amount] = mini;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, -1);
        int result = solve(coins, amount, dp);
        if (result == INT_MAX)
        {
            return -1;
        }
        else
        {
            return result;
        }
    }
};