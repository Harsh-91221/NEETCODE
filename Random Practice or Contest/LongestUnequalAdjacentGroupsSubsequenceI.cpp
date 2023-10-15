class Solution
{
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string> &words, vector<int> &groups)
    {
        vector<string> ans;
        int result = -1;
        for (int i = 0; i < words.size(); i++)
        {
            // If the adjacent element is not equal then we push that corresponding string
            if (groups[i] != result)
            {
                ans.push_back(words[i]);
                // store the current element for further checking
                result = groups[i];
            }
        }
        return ans;
    }
};