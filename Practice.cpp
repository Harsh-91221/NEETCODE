//BRUTE FORCE
class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long n = nums.size();
        if (n < 3)
        {
            return 0;
        }
        long long maxval = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    long long triplet_value = (long long)(nums[i] - nums[j]) * nums[k];
                    maxval = (long long)max(maxval, triplet_value);
                }
            }
        }
        return maxval;
    }
};

//OPTIMIZED
class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long max1 = 0;
        long long max2 = INT_MIN;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = max(ans, max2 * nums[i]);
            max2 = max(max2, max1 - nums[i]);
            max1 = max(max1, (long long)nums[i]);
        }
        return ans;
    }
};