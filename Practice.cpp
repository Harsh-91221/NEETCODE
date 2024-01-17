class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        set<int> s;
        for (auto a : arr)
        {
            mp[a]++;
        }
        for (auto a : mp)
        {
            s.insert(a.second);
        }
        return mp.size() == s.size();
    }
};