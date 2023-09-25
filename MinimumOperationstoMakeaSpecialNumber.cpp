#include <iostream>
#include <string>
using namespace std;
int minimumOperations(string num)
{
    bool zerofound = false;
    bool fivefound = false;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        // FOR 00
        if (zerofound && num[i] == '0')
        {
            return num.size() - i - 2;
        }
        // FOR 50
        if (zerofound && num[i] == '5')
        {
            return num.size() - i - 2;
        }
        // FOR 25
        if (fivefound && num[i] == '2')
        {
            return num.size() - i - 2;
        }
        // FOR 75
        if (fivefound && num[i] == '7')
        {
            return num.size() - i - 2;
        }
        if (num[i] == '0')
        {
            zerofound = true;
        }
        if (num[i] == '5')
        {
            fivefound = true;
        }
    }
    if (zerofound)
    {
        return num.size() - 1;
    }
    return num.size();
}
int main()
{
    string input = "2245047";
    int result = minimumOperations(input);
    cout << "Minimum operations: " << result << endl;
    return 0;
}
