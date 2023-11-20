class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int Midx = 0;
        int Pidx = 0;
        int Gidx = 0;
        int time = 0;
        int n = garbage.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < garbage[i].size(); j++)
            {
                if (garbage[i][j] == 'M')
                {
                    Midx = i;
                }
                else if (garbage[i][j] == 'G')
                {
                    Gidx = i;
                }
                else
                {
                    Pidx = i;
                }
                time++;
            }
        }
        for (int i = 1; i < travel.size(); i++)
        {
            travel[i] += travel[i - 1];
        }
        time += Midx > 0 ? travel[Midx - 1] : 0;
        time += Gidx > 0 ? travel[Gidx - 1] : 0;
        time += Pidx > 0 ? travel[Pidx - 1] : 0;
        return time;
    }
};