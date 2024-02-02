class Solution
{
public:
    int reverse(int n)
    {
        int s = 0;
        while (n != 0)
        {
            int r = n % 10;
            s = s * 10 + r;
            n = n / 10;
        }
        return s;
    }
    int countDistinctIntegers(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(reverse(nums[i]));
        }
        return s.size();
    }
};