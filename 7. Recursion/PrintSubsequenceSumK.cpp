#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> &a, int i, int k, int sum, vector<int> &output)
{
    if (i == a.size())
    {
        if (sum == k)
        {
            for (auto i : output)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    output.push_back(a[i]);
    sum += a[i];
    solve(a, i + 1, k, sum, output);

    sum -= a[i];
    output.pop_back();
    solve(a, i + 1, k, sum, output);
}
int main()
{
    vector<int> a = {1, 2, 1};
    vector<int> output;
    int k = 2;
    solve(a, 0, k, 0, output);
}