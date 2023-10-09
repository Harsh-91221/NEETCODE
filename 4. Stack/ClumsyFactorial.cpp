class Solution
{
public:
    int clumsy(int n)
    {
        int operations = 0;
        stack<int> s;
        s.push(n);
        for (int i = n - 1; i >= 1; i--)
        {
            if (operations == 0)
            {
                int ans = s.top();
                s.pop();
                s.push(ans * i);
            }
            else if (operations == 1)
            {
                int ans = s.top();
                s.pop();
                s.push(ans / i);
            }
            else if (operations == 2)
            {
                s.push(i);
            }
            else
            {
                s.push(i * (-1));
            }
            operations = (operations + 1) % 4;
        }
        int ans = 0;
        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};