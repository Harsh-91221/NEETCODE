class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
        {
            string currentword;
            for (int j = 0; j < words[i].size(); j++)
            {
                if (words[i][j] != separator)
                {
                    currentword += words[i][j];
                }
                else
                {
                    if (!currentword.empty())
                    {
                        ans.push_back(currentword);
                        currentword = "";
                    }
                }
            }
            if (!currentword.empty())
            {
                ans.push_back(currentword);
            }
        }
        return ans;
    }
};