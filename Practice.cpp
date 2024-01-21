class Solution
{
public:
    vector<long long> countOfPairs(int n, int x, int y)
    {
        if (x > y)
        {
            return countOfPairs(n, y, x);
        }
        vector<long long> ans(n, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                int index = i - j;
                index = min(index, abs(j - x) + abs(i - y) + 1);
                if (index >= 1)
                {
                    ans[index - 1] += 2;
                }
            }
        }
        return ans;
    }
};