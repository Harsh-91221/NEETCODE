class Solution
{
public:
    int findChampion(vector<vector<int>> &grid)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (grid[i][j] == 1)
                {
                    mp[j]++;
                }
                else
                {
                    mp[i]++;
                }
            }
        }
        for (int team = 0; team < grid.size(); team++)
        {
            if (mp[team] == 0)
            {
                return team;
            }
        }
        return 0;
    }
};