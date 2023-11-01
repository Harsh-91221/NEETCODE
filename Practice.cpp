bool isAnagram(string str1, string str2)
{
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    if (str1.size() != str2.size())
    {
        return false;
    }
    for (auto a : str1)
    {
        mp1[a]++;
    }
    for (auto a : str2)
    {
        mp2[a]++;
    }
    for (int i = 0; i < str1.size(); i++)
    {
        if (mp1[str1[i]] != mp2[str1[i]])
        {
            return false;
        }
    }
    return true;
}
