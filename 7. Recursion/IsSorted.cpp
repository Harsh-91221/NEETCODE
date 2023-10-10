#include <iostream>
using namespace std;
bool sorted(int a[], int i, int n)
{
    if (i >= n - 1)
    {
        return true;
    }
    if (a[i] > a[i + 1])
    {
        return false;
    }
    return sorted(a, i + 1, n);
}
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << sorted(a, 0, 9);
}