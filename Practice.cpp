void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    int m = a.size();
    int n = b.size();
    a.resize(m + n);
    int mainArrayIndex = m + n - 1;
    int leftIndex = m - 1;
    int rightIndex = n - 1;
    while (leftIndex >= 0 && rightIndex >= 0)
    {
        if (a[leftIndex] > b[rightIndex])
        {
            a[mainArrayIndex--] = a[leftIndex--];
        }
        else
        {
            a[mainArrayIndex--] = b[rightIndex--];
        }
    }
    while (rightIndex >= 0)
    {
        a[mainArrayIndex--] = b[rightIndex--];
    }
}