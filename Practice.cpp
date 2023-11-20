#include <vector>
#include <string>
using namespace std;
void solve(string s, int i, string &temp, vector<string> &ans)
{
    if (i == s.size())
    {
        ans.push_back(temp);
        return;
    }
    solve(s, i + 1, temp, ans);
    temp.push_back(s[i]);
    solve(s, i + 1, temp, ans);
    temp.pop_back();
}
vector<string> generateSubsequences(string s)
{
    string temp = "";
    vector<string> ans;
    solve(s, 0, temp, ans);
    return ans;
}
