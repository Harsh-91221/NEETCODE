class Solution
{
public:
    void solve(vector<int> &candidates, int target, int i, vector<int> &ans, vector<vector<int>> &output)
    {
        if (target == 0)
        {
            output.push_back(ans);
            return;
        }
        for (int j = i; j < candidates.size(); j++)
        {
            if (j > i && candidates[j] == candidates[j - 1])
            {
                continue;
            }
            if (candidates[j] > target)
            {
                break;
            }
            ans.push_back(candidates[j]);
            solve(candidates, target - candidates[j], j + 1, ans, output);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        vector<vector<int>> output;
        solve(candidates, target, 0, ans, output);
        return output;
    }
};