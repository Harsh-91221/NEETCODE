class Solution
{
public:
    int solve(int i, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        // Base case: If the target becomes negative, return a large negative value
        if (target < 0)
        {
            return -nums.size();
        }
        // Base case: If the target becomes zero, return zero
        if (target == 0)
        {
            return 0;
        }
        // Base case: If we reach the end of the array, return a large negative value
        if (i >= nums.size())
        {
            return -nums.size();
        }
        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        // Recursive case: Calculate the result by considering and not considering the current element
        int include = solve(i + 1, nums, target - nums[i], dp);
        int exclude = solve(i + 1, nums, target, dp);
        return dp[i][target] = max(1 + include, exclude);
    }
    int lengthOfLongestSubsequence(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = solve(0, nums, target, dp);
        // If the result is non-positive, return -1 as it indicates no valid subsequence
        if (ans <= 0)
        {
            return -1;
        }
        return ans;
    }
};
