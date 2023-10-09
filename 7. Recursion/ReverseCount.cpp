#include <iostream>
using namespace std;
void count(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    count(n - 1);
}
int main()
{
    int n;
    cin >> n;
    count(n);
}