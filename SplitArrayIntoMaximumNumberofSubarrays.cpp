class Solution
{
public:
    int maxSubarrays(vector<int> &nums)
    {
        int l = INT_MAX;
        for (auto i : nums)
        {
            l = l & i;
        }
        if (l != 0)
        {
            return 1;
        }
        int r = INT_MAX;
        int segment = 0;
        for (auto i : nums)
        {
            r = r & i;
            if (l == r)
            {
                segment++;
                r = INT_MAX;
            }
        }
        return segment;
        //           int ans = 1;
        //           int zero = 0;

        //     for (int i = 0; i < nums.size(); i++)
        //     {
        //         if (nums[i] == 0)
        //         {
        //             zero++;
        //         }
        //         else
        //         {
        //             ans += zero;
        //             zero = 0;
        //         }
        //     }
        //     return ans;
    }
};