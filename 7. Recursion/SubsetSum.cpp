void solve(vector<int> &num, int i, vector<int> &ans, int n, int sum)
{
    if (i == n)
    {
        ans.push_back(sum);
        return;
    }
    // Include the current element 'num[i]' in the subset sum and move to the next element
    solve(num, i + 1, ans, n, sum + num[i]);

    // Exclude the current element 'num[i]' from the subset sum and move to the next element
    solve(num, i + 1, ans, n, sum);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    int sum = 0;
    int n = num.size();
    solve(num, 0, ans, n, sum);
    sort(ans.begin(), ans.end());
    return ans;
}
