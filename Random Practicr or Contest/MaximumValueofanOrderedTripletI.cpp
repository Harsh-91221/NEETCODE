// BRUTE FORCE
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
        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
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

// OPTIMIZED
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
long long maximumTripletValue(vector<int> &nums)
{
    long long max1 = 0;
    long long max2 = INT_MIN;
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = max(ans, max2 * (nums[i]));
        max2 = max(max2, max1 - nums[i]);
        max1 = max(max1, (long long)(nums[i]));
    }
    return ans;
}
int main()
{
    vector<int> nums = {12, 6, 1, 2, 7};
    long long result = maximumTripletValue(nums);
    cout << "Maximum Triplet Value: " << result << endl;
    return 0;
}