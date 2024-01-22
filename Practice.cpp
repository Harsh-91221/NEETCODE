class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (auto a : nums)
        {
            mp[a]++;
        }
        int miss = 0;
        for (int i = 1; i <= n; i++)
        {
            if (mp.find(i) == mp.end())
            {
                miss = i;
            }
        }
        for (auto a : mp)
        {
            if (a.second == 2)
            {
                return {a.first, miss};
            }
        }
        return {};
    }
};