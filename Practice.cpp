bool solve(int n, vector<int> &arr, int k, int i, int sum)
{
    if (i >= n)
    {
        if (sum == k)
        {
            return true;
        }
        return false; // Add this line to handle the case when sum != k.
    }

    // Include the current element in the subsequence
    if (solve(n, arr, k, i + 1, sum + arr[i]))
    {
        return true;
    }

    // Exclude the current element from the subsequence
    if (solve(n, arr, k, i + 1, sum))
    {
        return true;
    }

    // If neither inclusion nor exclusion leads to a valid subsequence, return false
    return false;
}

bool checkSubsequenceSum(int n, vector<int> &arr, int k)
{
    int sum = 0;
    return solve(n, arr, k, 0, sum);
}