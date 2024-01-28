class Solution
{
public:
    int countKeyChanges(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int count = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] != s[i + 1])
            {
                count++;
            }
        }
        return count;
    }
};