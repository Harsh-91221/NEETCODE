class Solution
{
public:
    bool check(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int d = nums[1] - nums[0];
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] != d)
            {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++)
        {
            int start = l[i];
            int end = r[i];
            vector<int> arr(nums.begin() + start, nums.begin() + end + 1);
            bool isAP = check(arr);
            ans.push_back(isAP);
        } 
        return ans;
    }
};