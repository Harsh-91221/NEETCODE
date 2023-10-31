class Solution
{
public:
    int findmaxIndex(vector<vector<int>> &mat, int n, int m, int col)
    {
        int maxval = -1;
        int index = -1;
        // Iterate through the rows in the specified column.
        for (int row = 0; row < n; row++)
        {
            // If the current element is greater than the current max value,
            // update the max value and its index.
            if (mat[row][col] > maxval)
            {
                maxval = mat[row][col];
                index = row;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0;
        int e = m - 1;
        // Perform binary search on columns.
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            // Find the row index of the maximum value in the current column.
            int maxrowIndex = findmaxIndex(mat, n, m, mid);
            int left = 0;
            int right = 0;
            // Check if there is an element to the left of the current column.
            if (mid - 1 >= 0)
            {
                left = mat[maxrowIndex][mid - 1];
            }
            else
            {
                left = -1;
            }
            // Check if there is an element to the right of the current column.
            if (mid + 1 < m)
            {
                right = mat[maxrowIndex][mid + 1];
            }
            else
            {
                right = -1;
            }
            // Check if the current element is greater than its adjacent elements.
            if (mat[maxrowIndex][mid] > left && mat[maxrowIndex][mid] > right)
            {
                return {maxrowIndex, mid};
            }
            else if (mat[maxrowIndex][mid] < left)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return {-1, -1};
    }
};
