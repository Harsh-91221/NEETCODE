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
                if (a == "-")
                {
                    s.push(op1 - op2);
                }
                if (a == "*")
                {
                    s.push(op1 * op2);
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