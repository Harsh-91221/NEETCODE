class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int ans = 0;
        int prev = 0;
        int count = 0;
        for (string s : bank)
        {
            count = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '1')
                {
                    count++;
                }
            }
            if (count != 0)
            {
                ans += count * prev;
                prev = count;
            }
        }
        return ans;
    }
};