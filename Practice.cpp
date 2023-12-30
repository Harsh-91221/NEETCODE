class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        unordered_map<char, int> mp;
        int n = words.size();
        for (auto st : words)
        {
            for (auto a : st)
            {
                mp[a]++;
            }
        }
        for (auto a : mp)
        {
            int freq = a.second;
            if (freq % n != 0)
            {
                return false;
            }
        }
        return true;
    }
};