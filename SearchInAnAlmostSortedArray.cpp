#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> &a, int target)
{
    int s = 0;
    int e = a.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        if (mid - 1 >= s && a[mid - 1] == target)
        {
            return mid - 1;
        }
        if (mid + 1 <= e && a[mid + 1] == target)
        {
            return mid + 1;
        }
        if (a[mid] > target)
        {
            e = mid - 2;
        }
        else
        {
            s = mid + 2;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int target;
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = search(a, target);
    cout << ans;
}