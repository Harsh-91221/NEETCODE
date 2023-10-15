class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            string temp;
            int count = 0;
            for (int j = i; j < s.size(); j++)
            {
                // Just  entering the string into temp
                temp.push_back(s[j]);
                if (s[j] == '1')
                {
                    count++;
                }
                // If count reaches k then we check certain conditions
                if (count == k)
                {
                    // if the string is empty that means no string is added
                    if (ans == "")
                    {
                        ans = temp;
                    }
                    // Shortest length is pushed to ans
                    else if (temp.size() < ans.size())
                    {
                        ans = temp;
                    }
                    // If size is same then we check lexicographically
                    else if (temp.size() == ans.size() && temp < ans)
                    {
                        ans = temp;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};