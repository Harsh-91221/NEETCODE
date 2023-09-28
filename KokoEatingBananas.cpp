#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long calc(vector<int> &piles, int h)
{
    long long n = piles.size();
    long long totalHour = 0;
    for (int i = 0; i < n; i++)
    {
        totalHour += ceil((double)piles[i] / (double)h);
    }
    return totalHour;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int n = piles.size();
    long long s = 1;
    long long e = *max_element(piles.begin(), piles.end());
    while (s <= e)
    {
        long long mid = s + (e - s) / 2;
        long long totalH = calc(piles, mid);
        if (totalH <= h)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return s;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int result = minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;
    return 0;
}
