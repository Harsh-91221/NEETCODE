class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = 0;
        for (auto a : nums)
        {
            mp[a]++;
            n = max(n, mp[a]);
        }
        vector<vector<int>> ans(n);
        for (auto a : mp)
        {
            int val = a.first;
            int freq = a.second;
            for (int i = 0; i < freq; i++)
            {
                ans[i].push_back(val);
            }
        }
        return ans;
    }
};