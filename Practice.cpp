class Solution
{
public:
    bool isPalindrome(int num)
    {
        int temp = num, reversed = 0;
        while (temp > 0)
        {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }
        return num == reversed;
    }

    long long minimumCost(vector<int> &nums)
    {
        int n = nums.size();
        long long minCost = LLONG_MAX;

        for (int x = 1; x <= 100000; ++x)
        {
            if (isPalindrome(x))
            {
                long long cost = 0;
                for (int i = 0; i < n; ++i)
                {
                    cost += abs(nums[i] - x);
                }
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }
};