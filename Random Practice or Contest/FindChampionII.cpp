class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, int> mp;
        // Iterate through the given edges to count incoming edges for each team
        for (auto edge : edges)
        {
            // Increment the count of incoming edges for the second element of each edge
            mp[edge[1]]++;
        }
        // Initialize count of teams with zero incoming edges and the potential champion
        int count = 0;
        int champion = -1;
        for (int i = 0; i < n; i++)
        {
            if (mp[i] == 0)
            {
                // Increment the count of teams with zero incoming edges
                count++;
                // Update the potential champion to the current team
                champion = i;
            }
        }
        // If there is exactly one team with zero incoming edges, return that team as the champion
        if (count == 1)
        {
            return champion;
        }
        return -1;
    }
};
