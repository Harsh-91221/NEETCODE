/*
    Given string, find longest substring w/o repeating chars
    Ex. s = "abcabcbb" -> 3 "abc", s = "bbbbb" -> 1 "b"

    Sliding window, expand if unique, contract if duplicate

    Time: O(n)
    Space: O(n)
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;
        int maxsize = 0;
        unordered_set<char> st;
        while (j < s.size())
        {
            if (st.find(s[j]) != st.end())
            {
                st.erase(s[i]);
                i++;
            }
            else
            {
                maxsize = max(maxsize, j - i + 1);
                st.insert(s[j]);
                j++;
            }
        }
        return maxsize;
    }
};

// Time: O(n^2)
// Space: O(n)
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxsub = 0;
        for (int i = 0; i < s.size(); i++)
        {
            set<int> st;
            int count = 0;
            for (int j = i; j < s.size(); j++)
            {
                if (st.count(s[j]))
                {
                    break;
                }
                st.insert(s[j]);
                count++;
            }
            maxsub = max(maxsub, count);
        }
        return maxsub;
    }
};