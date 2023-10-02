/*
    Given array of strings, group anagrams together (same letters diff order)
    Ex. strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]

    Count chars, for each string use total char counts (naturally sorted) as key

    Time: O(n x l) -> n = length of strs, l = max length of a string in strs
    Space: O(n x l)
*/
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (auto a : strs)
        {
            string temp = a;
            sort(a.begin(), a.end());
            // KEY PR JO CORRESPONDING VECTOR THA USS VECTOR PR PUSH KR DIYA JO REAL STRING THA TEMP
            mp[a].push_back(temp);
        }
        for (auto a : mp)
        {
            ans.push_back(a.second);
        }
        return ans;
    }
};