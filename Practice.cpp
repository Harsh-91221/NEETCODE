class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<int> mp(100001, -1);
        for (auto a : matches)
        {
            int Pwin = a[0];
            int Plost = a[1];
            if (mp[Pwin] == -1)
            {
                mp[Pwin] = 0;
            }
            if (mp[Plost] == -1)
            {
                mp[Plost] = 1;
            }
            else
            {
                mp[Plost]++;
            }
        }
        vector<int> zeroLost, oneLost;
        for (int i = 1; i < 100001; i++)
        {
            if (mp[i] == 0)
            {
                zeroLost.push_back(i);
            }
            else if (mp[i] == 1)
            {
                oneLost.push_back(i);
            }
        }
        return {zeroLost, oneLost};
    }
};