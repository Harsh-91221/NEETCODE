
using namespace std;
class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        int numRows = grid.size();
        int numCols = grid[0].size();
        vector<int> modifiedgrid;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                modifiedgrid.push_back(grid[i][j] % 12345);
            }
        }
        int n = numRows * numCols;
        vector<long long> prefix(n);
        prefix[0] = 1;
        vector<long long> finalProd(n);
        for (int i = 1; i < n; i++)
        {
            prefix[i] = (prefix[i - 1] * modifiedgrid[i - 1]) % 12345;
        }
        long long suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            finalProd[i] = (suffix * prefix[i]) % 12345;
            suffix = (suffix * modifiedgrid[i]) % 12345;
        }
        vector<vector<int>> result;
        vector<int> row;
        int colCount = 0;
        for (int i = 0; i < n; i++)
        {
            row.push_back(finalProd[i]);
            colCount++;
            if (colCount == numCols)
            {
                result.push_back(row);
                row.clear();
                colCount = 0;
            }
        }
        return result;
    }
};
