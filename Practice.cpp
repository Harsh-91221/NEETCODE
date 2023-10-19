class Solution
{
public:
    string build(string &s)
    {
        string temp = "";
        int n = s.length();
        int i = 0;
        while (i < n)
        {
            if (s[i] != '#')
            {
                temp.push_back(s[i]); // Append the character to the 'temp' string
            }
            else
            {
                if (!temp.empty())
                {
                    temp.pop_back(); // Remove the last character from 'temp'
                }
            }
            i++;
        }
        return temp;
    }
    bool backspaceCompare(string s, string t)
    {
        return build(s) == build(t);
    }
};
