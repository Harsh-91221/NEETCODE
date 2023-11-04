class Solution
{
public:
    int beautySum(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            unordered_map<char, int> mp;
            for (int j = i; j < s.size(); j++)
            {
                int maxi = INT_MIN;
                int mini = INT_MAX;
                mp[s[j]]++; // Increment the frequency of the current character.
                // Calculate the maximum and minimum frequencies in the current substring.
                for (auto a : mp)
                {
                    maxi = max(maxi, a.second);
                    mini = min(mini, a.second);
                }
                ans += (maxi - mini); // Update the answer by the beauty of the current substring.
            }
        }
        return ans;
    }
};
