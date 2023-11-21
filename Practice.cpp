class Solution
{
public:
    int MOD = 1e9 + 7;
    int rev(int n)
    {
        int s = 0;
        while (n != 0)
        {
            int r = n % 10;
            s = s * 10 + r;
            n = n / 10;
        }
        return s;
    }
    int countNicePairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i] - rev(nums[i]);
            mp[temp]++;
            ans = (ans + mp[temp] - 1) % MOD;
        }
        return ans % MOD;
    }
};