class Solution
{
public:
    // Function to check if it's valid to place character 'c' at the given row and column.
    bool isvalid(vector<vector<char>> &board, int row, int col, char c)
    {
        // Check the current row for the presence of character 'c'.
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c)
            {
                return false;
            }
        }
        // Check the current column for the presence of character 'c'.
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == c)
            {
                return false;
            }
        }
        // Check the 3x3 subgrid for the presence of character 'c'.
        for (int i = 0; i < 9; i++)
        {
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            {
                return false;
            }
        }
        return true;
    }
    // Function to recursively solve the Sudoku puzzle.
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // If the current cell is empty ('.'), try placing digits from '1' to '9'.
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isvalid(board, i, j, c))
                        {
                            // If placing 'c' is valid, set it in the current cell and recursively solve.
                            board[i][j] = c;
                            if (solve(board))
                            {
                                return true; // If the Sudoku puzzle is solved, return true.
                            }
                            else
                            {
                                board[i][j] = '.'; // If not solved, reset the cell and backtrack.
                            }
                        }
                    }
                    return false; // If no valid digit can be placed, return false.
                }
            }
        }
        return true; // If the entire puzzle is solved, return true.
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
