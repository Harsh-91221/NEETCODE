class Solution
{
public:
    void solve(int k, int n, int i, vector<int> &ans, vector<vector<int>> &output)
    {
        if (k == ans.size())
        {
            if (n == 0)
            {
                output.push_back(ans);
            }
            return;
        }
        for (int j = i; j <= 9; j++)
        {
            ans.push_back(j);
            solve(k, n - j, j + 1, ans, output);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> ans;
        vector<vector<int>> output;
        solve(k, n, 0, ans, output);
        return output;
    }
};