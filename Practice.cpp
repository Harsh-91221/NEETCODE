class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        string previous = countAndSay(n - 1);
        string ans = "";
        int len = previous.size();
        int i = 0;
        while (i < len)
        {
            int count = 1;
            while (i + 1 < len && previous[i] == previous[i + 1])
            {
                count++;
                i++;
            }
            ans += to_string(count) + previous[i];
            i++;
        }
        return ans;
    }
};