class Solution
{
public:
    int minimumAddedCoins(vector<int> &coins, int target)
    {
        long long int n = coins.size();
        long long int pre = 0;
        sort(coins.begin(), coins.end());
        long long int i = 0;
        long long int count = 0;
        for (int j = 1; j <= target;)
        {
            if (i < n && coins[i] <= j)
            {
                pre += coins[i];
                i++;
            }
            else
            {
                if (pre >= j)
                {
                    continue;
                }
                pre += j;
                count++;
            }
            j = pre + 1;
        }
        return count;
    }
};