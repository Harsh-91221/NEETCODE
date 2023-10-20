class Solution
{
public:
    bool issafe(int row, int col, vector<string> &board, int n)
    {
        int dumrow = row;
        int dumcol = col;
        // Check if there is a queen in the diagonal to the top-left
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }
        row = dumrow;
        col = dumcol;
        // Check if there is a queen in the same column above
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            col--;
        }
        row = dumrow;
        col = dumcol;
        // Check if there is a queen in the diagonal to the bottom-left
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        // If all queens are placed successfully, add the board configuration to the answer
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++)
        {
            if (issafe(row, col, board, n))
            {
                board[row][col] = 'Q';         // Place a queen
                solve(col + 1, board, ans, n); // Recur for the next column
                board[row][col] = '.';         // Backtrack, remove the queen
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.'); // Create a string with n dots
        // Fill the board with empty rows
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        // Start solving the N-Queens problem from the first column (col = 0)
        solve(0, board, ans, n);
        return ans;
    }
};
