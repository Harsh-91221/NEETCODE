/*
    Determine if a 9x9 Sudoku board is valid (no repeats)

    Boolean matrices to store seen values. Check rows, cols, 3x3 sub-boxes

    Time: O(n^2)
    Space: O(n^2)
*/
class Solution
{
public:
    bool valid(vector<vector<char>> &board, int sr, int er, int sc, int ec)
    {
        set<char> st;
        for (int i = sr; i <= er; i++)
        {
            for (int j = sc; j <= ec; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                if (st.find(board[i][j]) != st.end())
                {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // CHECKING VALIDATION OF EACH ROW
        for (int i = 0; i < 9; i++)
        {
            set<char> st;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                if (st.find(board[i][j]) != st.end())
                {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        // CHECKING VALIDATION OF EACH COLUMN
        for (int j = 0; j < 9; j++)
        {
            set<char> st;
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                if (st.find(board[i][j]) != st.end())
                {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        // CHECKING VALIDATION OF EACH 3x3 SUB BOXES
        // sr=STARTING ROW er=ENDING ROW sc=STARTING COLUMN ec=ENDING COLUMN
        for (int sr = 0; sr < 9; sr += 3)
        {
            int er = sr + 2;
            for (int sc = 0; sc < 9; sc += 3)
            {
                int ec = sc + 2;
                if (!valid(board, sr, er, sc, ec))
                {
                    return false;
                }
            }
        }
        return true;
    }
};