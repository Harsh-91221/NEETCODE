// BRUTE FORCE
// T.C -> O(log(n))
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
        {
            return true;
        }
        return false;
    }
};

// OPTIMIZED SOLUTION
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> h(26);
        if (s.size() != t.size())
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            h[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            h[t[i] - 'a']--;
        }
        for (int i = 0; i < h.size(); i++)
        {
            if (h[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};