#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> &a, int i, int k, int sum, vector<int> &output)
{
    // If we have processed all elements in 'a'
    if (i == a.size())
    {
        // If the current subset's sum is equal to 'k', print it
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
    // Include the current element 'a[i]' in the subset
    output.push_back(a[i]);
    sum += a[i];
    solve(a, i + 1, k, sum, output);

    // Exclude the current element 'a[i]' from the subset
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
    return 0;
}
