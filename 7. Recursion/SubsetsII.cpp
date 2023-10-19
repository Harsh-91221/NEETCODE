// T.C - O(2^n*n)
// S.C - O(2^n)*O(k)
class Solution
{
public:
    void solve(vector<int> &nums, int idx, vector<int> &ans, vector<vector<int>> &output)
    {
        output.push_back(ans); // Add the current subset to the output list
        // Remember this step where i have to start loop from idx
        for (int i = idx; i < nums.size(); i++)
        {
            if (i != idx && nums[i] == nums[i - 1])
            {
                continue; // Skip duplicates to avoid duplicate subsets
            }
            ans.push_back(nums[i]);          // Include the current element in the subset
            solve(nums, i + 1, ans, output); // Recursively generate subsets
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
