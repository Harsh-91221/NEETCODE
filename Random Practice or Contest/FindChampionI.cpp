class Solution
{
public:
    int findChampion(vector<vector<int>> &grid)
    {
        // Create an unordered map to store the count of wins for each team
        unordered_map<int, int> mp;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                // Skip comparison with itself
                if (i == j)
                {
                    continue;
                }
                // If team i won against team j (grid[i][j] == 1), increment wins for team j
                if (grid[i][j] == 1)
                {
                    mp[j]++;
                }
                // If team i lost to team j (grid[i][j] == 0), increment wins for team i
                else
                {
                    mp[i]++;
                }
            }
        }
        // Iterate through each team to find the team with zero wins (champion)
        for (int team = 0; team < grid.size(); team++)
        {
            if (mp[team] == 0)
            {
                // Return the index of the team with zero wins (champion)
                return team;
            }
        }
        return 0;
    }
};
