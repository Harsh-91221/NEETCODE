#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &nums, int target, int i, int sum)
{
    if (i == nums.size())
    {
        if (sum == target)
        {
            return 1;
        }
        return 0;
    }
    sum += nums[i];
    int l = solve(nums, target, i + 1, sum);

    sum -= nums[i];
    int r = solve(nums, target, i + 1, sum);

    return l + r;
}
int main()
{
    vector<int> a = {1, 2, 1};
    int target = 2;
    cout << solve(a, target, 0, 0);
}