class Solution
{
public:
    bool isPathCrossing(string path)
    {
        set<pair<int, int>> s;
        int x = 0, y = 0;
        s.insert({0, 0});
        for (auto a : path)
        {
            if (a == 'N')
            {
                y++;
            }
            else if (a == 'S')
            {
                y--;
            }
            else if (a == 'E')
            {
                x++;
            }
            else
            {
                x--;
            }
            if (s.find({x, y}) != s.end())
            {
                return true;
            }
            s.insert({x, y});
        }
        return false;
    }
};