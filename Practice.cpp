#include <map>
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int repeating = -1;
    int missing = -1;
    map<int, int> mp;
    for (auto i : a)
    {
        mp[i]++;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (mp[i] == 2)
        {
            repeating = i;
        }
        if (mp[i] == 0)
        {
            missing = i;
        }
        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    return {repeating, missing};
}