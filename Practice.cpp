class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        unordered_map<char, int> mp;
        int n = words.size();
        int ch[26] = {0};
        for (auto st : words)
        {
            for (auto a : st)
            {
                ch[a - 'a']++;
            }
        }
        for (auto a : ch)
        {
            if (a % n != 0)
            {
                return false;
            }
        }
        return true;
    }
};