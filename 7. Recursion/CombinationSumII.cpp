#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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
            continue; // Skip duplicates to avoid duplicate combinations
        }
        if (candidates[j] > target)
        {
            return; // Skip if the current number is too large to contribute to the sum
        }
        ans.push_back(candidates[j]);
        solve(candidates, target - candidates[j], j + 1, ans, output);
        // Agar vo element suitable nahi hoga toh usse pop karke next element ko dekhenge karke
        ans.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end()); // Sort the input to handle duplicates efficiently
    vector<int> ans;
    vector<vector<int>> output;
    solve(candidates, target, 0, ans, output);
    return output;
}
int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = combinationSum2(candidates, target);
    for (auto combination : result)
    {
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
