class Solution
{
public:
    void solve(vector<vector<int>> &rooms, int s, vector<bool> &visited)
    {
        visited[s] = true;
        for (int i = 0; i < rooms[s].size(); i++)
        {
            if (!visited[rooms[s][i]])
            {
                solve(rooms, rooms[s][i], visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> visited(n, false);
        solve(rooms, 0, visited);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                return false;
            }
        }
        return true;
    }
};