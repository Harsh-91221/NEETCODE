class Solution
{
public:
    void solve(vector<int> &candidates, int target, int i, vector<vector<int>> &ans, vector<int> &output)
    {
        if (i == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(output);
            }
            return;
        }
        // Pick
        if (candidates[i] <= target)
        {
            output.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i, ans, output);
            output.pop_back();
        }
        // Not pick
        solve(candidates, target, i + 1, ans, output);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates, target, 0, ans, output);
        return ans;
    }
};