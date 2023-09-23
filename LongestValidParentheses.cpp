class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int len = 0;
            char ch = s[i];
            if (ch == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    len = i - st.top();
                }
            }
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};