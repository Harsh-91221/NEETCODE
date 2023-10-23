vector<int> getSecondOrderElements(int n, vector<int> a)
{
    int maxIdx = 0; // Index of the maximum element
    int minIdx = 0; // Index of the minimum element
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[maxIdx])
        {
            maxIdx = i;
        }
        if (a[i] < a[minIdx])
        {
            minIdx = i;
        }
    }
    int secondMaxIdx = (maxIdx == 0) ? 1 : 0;
    int secondMinIdx = (minIdx == 0) ? 1 : 0;
    for (int i = 0; i < n; i++)
    {
        if (i != maxIdx && a[i] > a[secondMaxIdx])
        {
            secondMaxIdx = i;
        }
        if (i != minIdx && a[i] < a[secondMinIdx])
        {
            secondMinIdx = i;
        }
    }

    vector<int> result = {a[secondMaxIdx], a[secondMinIdx]};
    return result;
}
