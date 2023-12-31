class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int maxi = -1;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (mp.find(ch) == mp.end())
            {
                mp[ch] = i;
            }
            else
            {
                maxi = max(maxi, i - mp[ch] - 1);
            }
        }
        return maxi;
    }
};