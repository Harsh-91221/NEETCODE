#include <iostream>
using namespace std;
void print(int a[], int i, int n)
{
    if (i == n)
    {
        return;
    }
    cout << a[i] << " ";
    print(a, i + 1, n);
}
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    print(a, 0, 10);
}