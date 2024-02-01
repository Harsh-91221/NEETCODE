class Solution
{
public:
    bool contain(string words, char x)
    {
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == x)
            {
                return true;
            }
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++)
        {
            if (contain(words[i], x))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};