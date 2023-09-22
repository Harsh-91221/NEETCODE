/*
    Given s w/ '(, ), {, }, [, ]', determine if valid
    Ex. s = "()[]{}" -> true, s = "(]" -> false

    Stack of opens, check for matching closes & validity

    Time: O(n)
    Space: O(n)
*/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty())
                {
                    char ch1 = st.top();
                    if (ch == ')' && ch1 == '(')
                    {
                        st.pop();
                    }
                    else if (ch == ']' && ch1 == '[')
                    {
                        st.pop();
                    }
                    else if (ch == '}' && ch1 == '{')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};