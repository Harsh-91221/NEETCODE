/*
    Given a string s & an int k, can change any char k times:
    Return length of longest substring containing same letter
    Ex. s = "ABAB" k = 2 -> 4 "AAAA", s = "AABABBA" k = 1 -> 4

    Sliding window, expand if can change char, contract if > k

    Time: O(n)
    Space: O(26)
*/
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.length();
        int i = 0, j = 0, maxFreq = 0, maxLen = 0;
        unordered_map<char, int> mp;
        for (j = 0; j < n; j++)
        {
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            // SHRINK THE WINDOW
            while ((j - i + 1) - maxFreq > k)
            {
                mp[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};