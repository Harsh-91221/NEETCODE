int missingK(vector<int> vec, int n, int k)
{
    int s = 0;
    int e = arr.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] - mid <= k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return s + k;
}
