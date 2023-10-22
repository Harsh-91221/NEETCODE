class Solution
{
public:
    void solve(int k, int n, int i, vector<int> &ans, vector<vector<int>> &output)
    {
        // If 'k' elements have been selected and their sum is equal to 'n'
        if (k == ans.size())
        {
            if (n == 0)
            {
                // Add the current combination to the 'output' vector
                output.push_back(ans);
            }
            return; // Return to the previous recursive call
        }
        for (int j = i; j <= 9; j++)
        {
            ans.push_back(j);                    // Include the current number in the combination
            solve(k, n - j, j + 1, ans, output); // Recursively explore combinations
            ans.pop_back();                      // Backtrack by removing the last added number
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> ans;
        vector<vector<int>> output;
        solve(k, n, 1, ans, output);
        return output;
    }
};
