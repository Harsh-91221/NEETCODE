class Solution
{
public:
    vector<int> lastVisitedIntegers(vector<string> &words)
    {
        vector<int> temp;
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == "prev")
            {
                count++;
            }
            else
            {
                temp.push_back(stoi(words[i]));
                count = 0;
            }
            if (count != 0)
            {
                if (count > temp.size())
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(temp[temp.size() - count]);
                }
            }
        }
        return ans;
    }
};