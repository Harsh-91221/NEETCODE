class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        if (s.size() != t.size())
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            // Check if 's[i]' is already mapped to a character in 't' (mp1[s[i]).
            if (mp1[s[i]] && mp1[s[i]] != t[i])
            {
                return false;
            }
            // Check if 't[i]' is already mapped to a character in 's' (mp2[t[i]).
            if (mp2[t[i]] && mp2[t[i]] != s[i])
            {
                return false;
            }
            // Update the mappings in both maps:
            // - Map 's[i]' to 't[i]' in mp1
            // - Map 't[i]' to 's[i]' in mp2
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};
