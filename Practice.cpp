#include <iostream>
using namespace std;
int countnum(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}
int main()
{
    int n = 12111;
    cout << countnum(n) << endl;
}