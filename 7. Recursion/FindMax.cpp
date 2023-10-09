#include <iostream>
using namespace std;
void find(int a[], int i, int n, int &maxi)
{
    if (i >= n)
    {
        return;
    }
    if (maxi < a[i])
    {
        maxi = a[i];
    }
    find(a, i + 1, n, maxi);
}
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 99, 0};
    int maxi = INT_MIN;
    find(a, 0, 10, maxi);
    cout << maxi;
}