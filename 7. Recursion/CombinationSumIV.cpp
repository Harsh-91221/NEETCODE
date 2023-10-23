#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &nums, int target, int i)
{
    // Base case: If the target is 0, we found a valid combination.
    if (target == 0)
    {
        return 1;
    }
    // Base case: If we've exceeded the array size or the target is negative,
    // we can't form a combination.
    if (i >= nums.size() || target < 0)
    {
        return 0;
    }
    // Include the current element in the combination and recursively
    // find combinations for the reduced target.
    int include = solve(nums, target - nums[i], 0);
    // Exclude the current element and move on to the next one.
    int exclude = solve(nums, target, i + 1);
    // Total combinations are the sum of included and excluded combinations.
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
