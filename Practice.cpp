class Solution
{
public:
    void solve(vector<int> &nums, int idx, vector<int> &temp, vector<int> &result, int prev, vector<vector<int>> &dp)
    {
        if (idx >= nums.size())
        {
            if (temp.size() > result.size())
            {
                result = temp;
            }
            return;
        }
        if (!dp[idx].empty())
        {
            temp = dp[idx];
            return;
        }
        if (prev == -1 || nums[idx] % prev == 0)
        {
            temp.push_back(nums[idx]);
            solve(nums, idx + 1, temp, result, nums[idx], dp);
            temp.pop_back();
        }
        solve(nums, idx + 1, temp, result, prev, dp);
        dp[idx] = temp;
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> result;
        vector<int> temp;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>());
        solve(nums, 0, temp, result, -1, dp);
        return result;
    }
};