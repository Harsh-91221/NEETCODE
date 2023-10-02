//T.C - O(N*K)
//S.C - O(N)
#include <iostream>
#include <vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    vector<int> result;
    for (i = 0; i <= nums.size() - k; i++)
    {
        int maxi = nums[i];
        for (j = i; j <= i + k - 1; j++)
        {
            maxi = max(maxi, nums[j]);
        }
        result.push_back(maxi);
    }
    return result;
}
int main()
{
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the window size (k): ";
    cin >> k;
    vector<int> result = maxSlidingWindow(nums, k); // Call the function to get the result
    cout << "Maximums in sliding windows: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
