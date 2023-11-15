class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = INT_MIN;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                arr[0] = 1;
            }
            else if (abs(arr[i] - arr[i - 1]) > 1)
            {
                arr[i] = arr[i - 1] + 1;
            }
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
};