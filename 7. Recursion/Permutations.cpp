class Solution
{
public:
    void solve(vector<int> &nums, int i, vector<vector<int>> &output)
    {
        // If 'i' is equal to or greater than the size of 'nums', it means we have
        // successfully generated a permutation, so we add it to the 'output'.
        if (i >= nums.size())
        {
            output.push_back(nums);
            return;
        }
        // Iterate through elements in the range [i, nums.size() - 1].
        for (int j = i; j < nums.size(); j++)
        {
            // Swap the elements at indices 'i' and 'j'.
            swap(nums[i], nums[j]);
            // Recursively call the 'solve' function for the next index (i + 1).
            solve(nums, i + 1, output);
            // Restore the original order by swapping the elements back.
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> output;
        solve(nums, 0, output);
        return output;
    }
};
