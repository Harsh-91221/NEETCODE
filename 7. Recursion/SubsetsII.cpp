class Solution
{
public:
    void solve(vector<int> &nums, int i, vector<int> &ans, vector<vector<int>> &output)
    {
        output.push_back(ans); // Add the current subset to the output list
        for (int j = i; j < nums.size(); j++)
        {
            if (j != i && nums[j] == nums[j - 1])
            {
                continue; // Skip duplicates to avoid duplicate subsets
            }
            ans.push_back(nums[j]);          // Include the current element in the subset
            solve(nums, j + 1, ans, output); // Recursively generate subsets
            ans.pop_back();                  // Backtrack to the previous state
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> ans;
        vector<vector<int>> output;
        sort(nums.begin(), nums.end()); // Sort the input array to handle duplicates
        solve(nums, 0, ans, output);
        return output;
    }
};
