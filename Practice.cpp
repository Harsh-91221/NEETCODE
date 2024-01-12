class Solution
{
public:
    bool isvowel(char s)
    {
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool halvesAreAlike(string s)
    {
        int n = s.size();
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (isvowel(s[i]))
            {
                count1++;
            }
        }
        for (int i = n / 2; i < n; i++)
        {
            if (isvowel(s[i]))
            {
                count2++;
            }
        }
        return count1 == count2;
    }
};