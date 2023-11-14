class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        unordered_map<int, pair<int, int>> mp;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            mp[ch] = {-1, -1};
        }
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (mp[ch].first == -1)
            {
                mp[ch].first = i;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            char ch = s[i];
            if (mp[ch].second == -1)
            {
                mp[ch].second = i;
            }
        }
        int ans = 0;
        for (auto a : mp)
        {
            char ch = a.first;
            int start = a.second.first;
            int end = a.second.second;
            unordered_set<int> st;
            for (int i = start + 1; i < end; i++)
            {
                st.insert(s[i]);
            }
            ans += st.size();
        }
        return ans;
    }
};