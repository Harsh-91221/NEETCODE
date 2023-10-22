#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int array_size, divisor;
        cin >> array_size >> divisor;

        vector<int> elements(array_size);

        for (int i = 0; i < array_size; i++)
        {
            cin >> elements[i];
        }

        int min_difference = divisor;

        for (int i = 0; i < array_size; i++)
        {
            if (divisor == 4)
            {
                if (elements[i] % 4 == 0)
                {
                    min_difference = 0;
                    break;
                }
                else
                {
                    int remainder = elements[i] % divisor;
                    if (min_difference > divisor - remainder)
                    {
                        min_difference = divisor - remainder;
                    }
                }
            }
            else
            {
                if (elements[i] % divisor == 0)
                {
                    min_difference = 0;
                    break;
                }
                else
                {
                    int remainder = elements[i] % divisor;
                    if (min_difference > divisor - remainder)
                    {
                        min_difference = divisor - remainder;
                    }
                }
            }
        }

        int result = (divisor == 4) ? 2 : 0;

        for (int i = 0; i < array_size; i++)
        {
            if ((divisor == 4 && elements[i] % 2 == 0) || (divisor != 4 && elements[i] % 2 == 0))
            {
                result = max(result - 1, 0);
            }
        }

        if (divisor == 4)
        {
            cout << min(result, min_difference) << '\n';
        }
        else
        {
            cout << min_difference << '\n';
        }
    }

    return 0;
}
