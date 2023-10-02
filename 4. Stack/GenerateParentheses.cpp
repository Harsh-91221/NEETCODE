/*
    Given n pairs of parentheses, generate all combos of well-formed parentheses
    Ex. n = 3 -> ["((()))","(()())","(())()","()(())","()()()"], n = 1 -> ["()"]

    Backtracking, keep valid, favor trying opens, then try closes if still valid

    Time: O(2^n)
    Space: O(n)
*/
class Solution
{
public:
    void solveParentheses(vector<string> &ans, int open, int close, int n, string output)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(output);
            return;
        }
        // INCLUDE THE OPENING BRACKET
        if (open > 0)
        {
            output.push_back('(');
            solveParentheses(ans, open - 1, close, n, output);
            output.pop_back();
        }

        // INCLUDE THE CLOSING BRACKET
        if (close > open)
        {
            output.push_back(')');
            solveParentheses(ans, open, close - 1, n, output);
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        int open = n;
        int close = n;
        string output = "";
        solveParentheses(ans, open, close, n, output);
        return ans;
    }
};

// ANOTHER WAY TO SOLVE
class Solution
{
public:
    void solveParentheses(vector<string> &ans, int open, int close, int n, string output)
    {
        if (output.length() == 2 * n)
        {
            ans.push_back(output);
            return;
        }
        // INCLUDE THE OPENING BRACKET
        else
        {
            if (open < n)
            {
                solveParentheses(ans, open + 1, close, n, output + '(');
            }
            // INCLUDE THE CLOSING BRACKET
            if (close < open)
            {
                solveParentheses(ans, open, close + 1, n, output + ')');
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string output = "";
        solveParentheses(ans, 0, 0, n, output);
        return ans;
    }
};