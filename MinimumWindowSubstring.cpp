/*
    Given 2 strings s & t, return min window substring
    of s such that all chars in t are included in window
    Ex. s = "ADOBECODEBANC" t = "ABC" -> "BANC"

    Sliding window + hash map {char -> count}
    Move j until valid, move i to find smaller

    Time: O(m + n)
    Space: O(m + n)
*/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        // BECAUSE WE HAVE TO FIND t IN s
        if (t.length() > s.length())
        {
            return "";
        }
        unordered_map<char, int> mp;
        // STORE IN MAP
        for (auto ch : t)
        {
            mp[ch]++;
        }
        int i = 0;
        int j = 0;
        int requiredcount = t.length();
        int minWindowSize = INT_MAX;
        int start_i = 0;
        // TRAVERSING
        while (j < n)
        {
            char ch = s[j];
            // IF THAT CHARACTER IS GREATER THAN ZERO THEN IT IS REQUIRED
            if (mp[ch] > 0)
            {
                requiredcount--;
            }
            mp[ch]--;
            // IF COUNT IS 0 THEN START SHRINKING THE WINDOW FROM i
            while (requiredcount == 0)
            {
                int currWindowSize = j - i + 1;
                // UPDATE THE MINIMUM WINDOW SIZE
                if (minWindowSize > currWindowSize)
                {
                    minWindowSize = currWindowSize;
                    start_i = i;
                }
                // WE WILL INCREASE THE FREQUENCY AS WE ARE SHRINKING
                mp[s[i]]++;
                // IF THAT CHARACTER IS GREATER THAN ZERO THEN IT IS REQUIRED
                if (mp[s[i]] > 0)
                {
                    requiredcount++;
                }
                i++;
            }
            j++;
        }
        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};