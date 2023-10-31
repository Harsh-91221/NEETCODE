int median(vector<vector<int>> &matrix, int m, int n)
{
    vector<int> arr;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            arr.push_back(matrix[i][j]);
        }
    }
    // Sort the array
    sort(arr.begin(), arr.end());
    // Find the median element
    int mid = arr.size() / 2;
    return arr[mid];
}