class Solution
{
public:
    int countPairs(vector<vector<int>> &coordinates, int k)
    {
        map<pair<int, int>, int> mp;
        int ans = 0;
        for (auto a : coordinates)
        {
            int x1 = a[0];
            int y1 = a[1];
            for (int i = 0; i <= k; i++)
            {
                // TRYING FOR ALL COMBINATIONS
                int x2 = x1 ^ i;
                int y2 = y1 ^ (k - i);
                ans += mp[{x2, y2}];
            }
            // FOR NEXT COORDINATE
            mp[{x1, y1}]++;
        }
        return ans;
        //  int pairs=0;
        //    int n=coordinates.size();
        //    for(int i=0;i<n;i++)
        //    {
        //        for(int j=i+1;j<n;j++)
        //        {
        //            int dist=(coordinates[i][0] ^ coordinates[j][0]) + (coordinates[i][1] ^ coordinates[j][1]);
        //            if(dist==k)
        //            {
        //                pairs++;
        //            }
        //        }
        //    }
        //    return pairs;
    }
};