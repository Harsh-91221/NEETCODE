class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> mp(26, 0);
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }
        for (auto a : mp)
        {
            if (a > 0)
            {
                count += a;
            }
        }
        return count;
    }
};