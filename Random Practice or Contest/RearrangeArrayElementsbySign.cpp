class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        int pos = 0;
        int neg = 1;
        vector<int> ans(n, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                ans[pos] = nums[i]; // Place positive numbers at positions pos, pos+2, pos+4, and so on.
                pos += 2;           // Move the positive position by 2 for the next positive number.
            }
            else
            {
                ans[neg] = nums[i]; // Place negative numbers at positions neg, neg+2, neg+4, and so on.
                neg += 2;           // Move the negative position by 2 for the next negative number.
            }
        }
        return ans;
    }
};
