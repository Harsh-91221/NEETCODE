#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;

        set<pair<int, int>> segments;
        bool intersecting = false;

        while (q--)
        {
            char op;
            int l, r;
            cin >> op >> l >> r;

            if (op == '+')
            {
                segments.insert({l, r});

                // Check for intersections
                auto it = segments.find({l, r});
                if (it != segments.begin())
                {
                    --it;
                    if (it->second >= l)
                    {
                        intersecting = true;
                    }
                }

                it = segments.find({l, r});
                ++it;
                if (it != segments.end() && it->first <= r)
                {
                    intersecting = true;
                }
            }
            else
            {
                segments.erase({l, r});
                if (intersecting)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}
