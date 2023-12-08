class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;
        for (int i = 0; i < n * 2; i++)
        {
            while (!s.empty() && nums[s.top()] < nums[i % n])
            {
                ans[s.top()] = nums[i % n];
                s.pop();
            }
            if (i < n)
            {
                s.push(i);
            }
        }
        return ans;
    }
};