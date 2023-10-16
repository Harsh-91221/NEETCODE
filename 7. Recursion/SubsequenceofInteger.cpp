#include <iostream>
#include <vector>
using namespace std;
void solve(int a[], int i, int n, vector<int> &output)
{
    if (i >= n)
    {
        for (auto i : output)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    output.push_back(a[i]);
    solve(a, i + 1, n, output);
    output.pop_back();
    solve(a, i + 1, n, output);
}
int main()
{
    int a[3] = {1, 2, 3};
    vector<int> output;
    solve(a, 0, 3, output);
}