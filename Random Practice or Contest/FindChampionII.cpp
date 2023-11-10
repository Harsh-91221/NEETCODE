class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, int> mp;
        for (auto edge : edges)
        {
            mp[edge[1]]++;
        }
        int count = 0;
        int champion = -1;
        for (int i = 0; i < n; i++)
        {
            if (mp[i] == 0)
            {
                count++;
                champion = i;
            }
        }
        if (count == 1)
        {
            return champion;
        }
        return -1;
    }
};