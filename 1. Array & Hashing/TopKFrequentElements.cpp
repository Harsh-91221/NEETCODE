/*
Given an integer array nums & an integer k, return the k most frequent elements
Ex. nums = [1,1,1,2,2,3] k = 2 -> [1,2], nums = [1] k = 1 -> [1]
Time: O(n)
Space: O(n)*/
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (auto a : nums)
        {
            mp[a]++;
        }
        vector<vector<int>> ans(n + 1);
        for (auto a : mp)
        {
            int element = a.first;
            int freq = a.second;
            ans[freq].push_back(element);
        }
        vector<int> result;
        for (int i = n; i >= 0; i--)
        {
            if (ans[i].size() == 0)
            {
                continue;
            }
            while (ans[i].size() > 0 && k > 0)
            {
                result.push_back(ans[i].back());
                ans[i].pop_back();
                k--;
            }
        }
        return result;
    }
};