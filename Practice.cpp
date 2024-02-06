class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for (auto a : strs)
        {
            string temp = a;
            sort(a.begin(), a.end());
            mp[a].push_back(temp);
        }
        for (auto a : mp)
        {
            result.push_back(a.second);
        }
        return result;
    }
};