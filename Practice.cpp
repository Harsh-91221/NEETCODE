#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPossible(const vector<pair<int, int>> &segments, int maxDistance)
{
    int left = 0, right = 0;
    for (const auto &segment : segments)
    {
        left = max(left - maxDistance, segment.first);
        right = min(right + maxDistance, segment.second);
        if (left > right)
        {
            return false;
        }
    }
    return true;
}

int findMinK(const vector<pair<int, int>> &segments)
{
    int low = 0, high = 1e9;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (isPossible(segments, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> segments(n);
        for (auto &segment : segments)
        {
            cin >> segment.first >> segment.second;
        }
        int minK = findMinK(segments);
        cout << minK << endl;
    }

    return 0;
}
