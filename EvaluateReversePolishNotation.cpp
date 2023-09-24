/*
    Evaluate RPN, valid operators: +, -, *, /

    Stack, if num push, if operator apply to top 2 nums

    Time: O(n)
    Space: O(n)
*/

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (auto a : tokens)
        {
            if (a == "+" || a == "-" || a == "*" || a == "/")
            {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                if (a == "+")
                {
                    s.push(op1 + op2);
                }
                if (a == "*")
                {
                    s.push(op1 * op2);
                }
                if (a == "-")
                {
                    s.push(op1 - op2);
                }
                if (a == "/")
                {
                    s.push(op1 / op2);
                }
            }
            else
            {
                s.push(stoi(a));
            }
        }
        return s.top();
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