class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mp;
        // COUNTING CHARACTERS IN MAGAZINE
        for (int i = 0; i < magazine.size(); i++)
        {
            mp[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (mp[ransomNote[i]] > 0)
            {
                // DECREASING CHARACTERS IN MAGAZINE
                mp[ransomNote[i]]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};