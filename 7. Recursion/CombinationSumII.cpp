class Solution
{
public:
    void solve(int i, vector<int> &candidates, int target, vector<int> &ans, vector<vector<int>> &output)
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
                continue; // Skip duplicates to avoid duplicate combinations
            }

            if (candidates[j] > target)
            {
                break; // Skip if the current candidate is greater than the remaining target
            }
            ans.push_back(candidates[j]);
            solve(j + 1, candidates, target - candidates[j], ans, output);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        vector<vector<int>> output;
        solve(0, candidates, target, ans, output);
        return output;
    }
};
