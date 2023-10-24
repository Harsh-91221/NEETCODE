class Solution
{
public:
    // Mark the entire row as -91221
    void markrow(vector<vector<int>> &matrix, int i)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] != 0)
            {
                matrix[i][j] = -91221;
            }
        }
    }
    // Mark the entire column as -91221
    void markcol(vector<vector<int>> &matrix, int j)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][j] != 0)
            {
                matrix[i][j] = -91221;
            }
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        // Iterate through the matrix to find zeros
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    // If a zero is found, mark the entire row and column
                    markrow(matrix, i);
                    markcol(matrix, j);
                }
            }
        }
        // Iterate through the matrix again to set marked cells to zero
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == -91221)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
