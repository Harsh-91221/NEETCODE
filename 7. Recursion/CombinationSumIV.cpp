#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &nums, int target, int i)
{
    if (target == 0)
    {
        return 1;
    }
    if (i >= nums.size() || target < 0)
    {
        return 0;
    }
    int include = solve(nums, target - nums[i], 0);
    int exclude = solve(nums, target, i + 1);
    return include + exclude;
}
int combinationSum4(vector<int> &nums, int target)
{
    return solve(nums, target, 0);
}
int main()
{
    vector<int> nums = {1, 2, 3};
    int target = 4;
    int result = combinationSum4(nums, target);
    cout << "Output: " << result << endl;
    return 0;
}
