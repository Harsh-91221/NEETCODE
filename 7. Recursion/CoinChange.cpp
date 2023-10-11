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