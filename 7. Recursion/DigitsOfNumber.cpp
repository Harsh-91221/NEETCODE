#include <iostream>
using namespace std;
void digit(int n)
{
    if (n == 0)
    {
        return;
    }
    int num = n % 10;
    digit(n / 10);
    cout << num << " ";
}
int main()
{
    int n;
    cin >> n;
    digit(n);
}