#include <iostream>
#include <vector>
using namespace std;
void subsequence(string s, int i, string output)
{
    if (i >= s.length())
    {
        cout << output;
        return;
    }
    // INCLUDE
    output.push_back(s[i]);
    subsequence(s, i + 1, output);
    output.pop_back();
    // EXCLUDE
    subsequence(s, i + 1, output);
}
int main()
{
    string s = "abc";
    string output = "";
    subsequence(s, 0, output);
}