#include <iostream>
using namespace std;
void find(int a[], int i, int n, int &mini)
{
    if (i >= n)
    {
        return;
    }
    if (mini > a[i])
    {
        mini = a[i];
    }
    find(a, i + 1, n, mini);
}
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 99, -1};
    int mini = INT_MAX;
    find(a, 0, 10, mini);
    cout << mini;
}