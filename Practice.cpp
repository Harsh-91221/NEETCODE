class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        int maxlen = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            mp[nums[j]]++;
            if (mp[nums[j]] > k)
            {
                while (j >= i && mp[nums[j]] > k)
                {
                    mp[nums[i]]--;
                    i++;
                }
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};