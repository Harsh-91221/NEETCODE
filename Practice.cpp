class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        long long xOdd = 0;
        for (int i = 1; i <= n; i += 2)
        {
            xOdd++;
        }
        long long xEven = 0;
        for (int i = 2; i <= n; i += 2)
        {
            xEven++;
        }
        long long yOdd = 0;
        for (int i = 1; i <= m; i += 2)
        {
            yOdd++;
        }
        long long yEven = 0;
        for (int i = 2; i <= m; i += 2)
        {
            yEven++;
        }
        long long ans = 0;
        // x is odd,y is even
        for (int i = 1; i <= n; i += 2)
        {
            ans += yEven;
        }
        // x is even,y is odd
        for (int i = 2; i <= n; i += 2)
        {
            ans += yOdd;
        }
        return ans;
    }
};