class Solution
{
public:
    int minChanges(string s)
    {
        int count = 0;
        // Iterate through the string with a step of 2 to compare adjacent characters
        for (int i = 0; i < s.size() - 1; i += 2)
        {
            // Check if the current and next characters are different
            if (s[i] != s[i + 1])
            {
                count++; // Increment count if characters are different
            }
        }
        return count;
    }
};
