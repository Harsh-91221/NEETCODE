// BRUTE FORCE
// T.C -> O(log(n))
// S.C -> O(1)
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
// T.C -> O(n)
// S>C -> O(n)
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

// ANOTHER OPTIMIZED SOLUTION USING MAP
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp1, mp2;
        if (s.size() != t.size())
        {
            return false;
        }
        for (auto a : s)
        {
            mp1[a]++;
        }
        for (auto a : t)
        {
            mp2[a]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (mp1[s[i]] != mp2[s[i]])
            {
                return false;
            }
        }
        return true;
    }
};