int firstOccur(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (k > arr[mid])
        {
            start = mid + 1;
        }
        else if (k < arr[mid])
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
}
int lastOccur(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (k > arr[mid])
        {
            start = mid + 1;
        }
        else if (k < arr[mid])
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
}
int count(vector<int> &arr, int n, int x)
{
    int ans = lastOccur(arr, n, x) - firstOccur(arr, n, x);
    if (ans == 0)
    {
        return 0;
    }
    return ans + 1;
}
