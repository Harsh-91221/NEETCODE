class Solution
{
public:
    bool issub(string &s, string &t, int m, int n)
    {
        if (m == 0)
        {
            return true;
        }
        if (n == 0)
        {
            return false;
        }
        // Traversing from right to left and checking if both characters are equal if both are equal then we increase both of them to the left or only string t is increased
        if (s[m - 1] == t[n - 1])
        {
            return issub(s, t, m - 1, n - 1);
        }
        // As we are checking for subsequence s in t
        return issub(s, t, m, n - 1);
    }
    bool isSubsequence(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        if (issub(s, t, m, n))
        {
            return true;
        }
        return false;
    }
};