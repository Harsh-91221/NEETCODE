#include <iostream>
using namespace std;
bool solve(int s, int e, string st)
{
    if (s == e)
    {
        return true;
    }
    if (st[s] != st[e])
    {
        return false;
    }
    return solve(s + 1, e - 1, st);
}
int main()
{
    string st = "ok";
    cout << solve(0, st.size() - 1, st);
}