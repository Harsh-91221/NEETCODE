class Solution
{
public:
    int findMinimumOperations(string s1, string s2, string s3)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        int ans = -1;
        int len = min({n1, n2, n3});
        for (int i = 0; i < len; i++)
        {
            string pref1 = s1.substr(0, i + 1);
            string pref2 = s2.substr(0, i + 1);
            string pref3 = s3.substr(0, i + 1);
            if (pref1 == pref2 && pref2 == pref3)
            {
                ans = n1 - (i + 1) + n2 - (i + 1) + n3 - (i + 1);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};