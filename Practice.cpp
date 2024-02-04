class Solution
{
public:
    string minWindow(string s, string t)
    {
        int i = 0;
        int j = 0;
        int n = s.length();
        if (t.size() > s.size())
        {
            return "";
        }
        int minwindowsize = INT_MAX;
        int start_i = 0;
        int requiredcount = t.size();
        unordered_map<char, int> mp;
        for (auto a : t)
        {
            mp[a]++;
        }
        while (j < n)
        {
            char ch = s[j];
            if (mp[ch] > 0)
            {
                requiredcount--;
            }
            mp[ch]--;
            while (requiredcount == 0)
            {
                int currwindowsize = j - i + 1;
                if (minwindowsize > currwindowsize)
                {
                    minwindowsize = currwindowsize;
                    start_i = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                {
                    requiredcount++;
                }
                i++;
            }
            j++;
        }
        return minwindowsize == INT_MAX ? "" : s.substr(start_i, minwindowsize);
    }
};