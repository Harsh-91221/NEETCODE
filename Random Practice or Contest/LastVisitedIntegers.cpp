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
                // We keep track of prev in the array
                count++;
            }
            else
            {
                // push the integers in the vector and reset the count
                temp.push_back(stoi(words[i]));
                count = 0;
            }
            if (count != 0)
            {
                // if count is greater than tenp size then there is no element for it
                if (count > temp.size())
                {
                    ans.push_back(-1);
                }
                else
                {
                    // pushing element from the reverse order
                    ans.push_back(temp[temp.size() - count]);
                }
            }
        }
        return ans;
    }
};