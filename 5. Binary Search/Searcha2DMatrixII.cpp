class Solution
{
public:
    bool searchMatrix(vector < vector<int> & matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
        {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0)
        {
            return false;
        }
        int s = 0;
        int e = n - 1;
        while (s < m && e >= 0)
        {
            if (matrix[s][e] == target)
            {
                return true;
            }
            else if (matrix[s][e] > target)
            {
                e--; // Move left in the same row
            }
            else
            {
                s++; // Move down to the next row
            }
        }
        return false;
    }
};
