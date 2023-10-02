class Solution
{
public:
    int solve(int x)
    {
        long long s = 0;
        long long e = x;
        long long target = x;
        long long ans = 0;
        while (s <= e)
        {
            long long mid = s + (e - s) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            else if (mid * mid > target)
            {
                e = mid - 1;
            }
            else
            {
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }
    int mySqrt(int x)
    {
        return solve(x);
    }
};