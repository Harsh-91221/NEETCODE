#include <vector>
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    for (int i = 0; i < b.size(); i++)
    {
        a.push_back(b[i]);
    }
    sort(a.begin(), a.end());
    b.clear();
}