/*
    Given an integer array nums, return an array such that:
    answer[i] is equal to the product of all elements of nums except nums[i]
    Ex. nums = [1,2,3,4] -> [24,12,8,6], nums = [-1,1,0,-3,3] -> [0,0,9,0,0]

    Calculate prefix products forward, then postfix backwards in a 2nd pass

    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);
    int prefix = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = prefix;
        prefix = prefix * nums[i];
    }
    int postfix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = ans[i] * postfix;
        postfix = postfix * nums[i];
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);

    cout << "Input Array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Output Array: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
// Time: O(n)
// Space: O(1)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> right(n);
        vector<int> left(n);
        left[0] = 1;
        for (int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }
        vector<int> ans(n);
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
}