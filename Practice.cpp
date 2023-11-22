bool isvalid(int board[][9], int row, int col, int num)
{
    // Check the current row for the presence of 'num'.
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }
    // Check the current column for the presence of 'num'.
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
        {
            return false;
        }
    }
    // Check the 3x3 subgrid for the presence of 'num'.
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool solve(int board[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // If the current cell is empty (0), try placing digits from 1 to 9.
            if (board[i][j] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isvalid(board, i, j, num))
                    {
                        // If placing 'num' is valid, set it in the current cell and recursively solve.
                        board[i][j] = num;
                        if (solve(board))
                        {
                            return true; // If the Sudoku puzzle is solved, return true.
                        }
                        else
                        {
                            board[i][j] = 0; // If not solved, reset the cell and backtrack.
                        }
                    }
                }
                return false; // If no valid digit can be placed, return false.
            }
        }
    }
    return true; // If the entire puzzle is solved, return true.
}
bool sudokuSolver(int board[][9])
{
    return solve(board);
}