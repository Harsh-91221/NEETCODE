#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int coins = 0;
        bool found = true;
        while (found)
        {
            found = false;
            int n = s.length();

            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] == 'A' && s[i + 1] == 'B')
                {
                    coins++;
                    s[i] = 'B';
                    s[i + 1] = 'C';
                    found = true;
                    break;
                }
                else if (s[i] == 'B' && s[i + 1] == 'A')
                {
                    coins++;
                    s[i] = 'C';
                    s[i + 1] = 'B';
                    found = true;
                    break;
                }
            }
        }

        cout << coins << endl;
    }

    return 0;
}
