class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<int> ans;
        vector<int> a_index;
        vector<int> b_index;
        int x = s.size();
        int y = a.size();
        int z = b.size();
        for (int i = 0; i <= x - y; i++)
        {
            if (s.substr(i, y) == a)
            {
                a_index.push_back(i);
            }
        }
        for (int i = 0; i <= x - z; i++)
        {
            if (s.substr(i, z) == b)
            {
                b_index.push_back(i);
            }
        }
        for (int i = 0; i < a_index.size(); i++)
        {
            for (int j = 0; j < b_index.size(); j++)
            {
                if (abs(a_index[i] - b_index[j]) <= k)
                {
                    ans.push_back(a_index[i]);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};