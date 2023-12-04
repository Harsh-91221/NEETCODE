class Solution
{
public:
    int beautifulSubstrings(string s, int k)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int vowels = 0, consonants = 0;
            for (int j = i; j < s.size(); j++)
            {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                {
                    vowels++;
                }
                else
                {
                    consonants++;
                }
                if ((vowels == consonants) && (vowels * consonants) % k == 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};