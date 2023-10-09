#include <iostream>
using namespace std;
bool find(string s, int i, int n, char key)
{
    if (i >= n)
    {
        return false;
    }
    if (s[i] == key)
    {
        return true;
    }
    return find(s, i + 1, n, key);
}
int main()
{
    string s = "Harsh";
    int ans = find(s, 0, s.size(), 'z');
    cout << ans;
}