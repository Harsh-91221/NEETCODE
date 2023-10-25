class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[j];
            if (sum == k)
            {
                count++;
            }
            if (prevsum.find(sum - k) != prevsum.end())
            {
                count += prevsum[sum - k];
            }
            prevsum[sum]++;
        }
    }
    return count;
}
};