/*
    Given 2 strings, return true if s2 contains permutation of s1
    Ex. s1 = "ab", s2 = "eidbaooo" -> true, s2 contains "ba"

    Sliding window, expand + count down char, contract + count up char

    Time: O(n)
    Space: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool checkInclusion(string s1, string s2)
{
    if (s1.length() > s2.length())
    {
        return false;
    }
    vector<int> s1hash(26, 0);
    vector<int> s2hash(26, 0);
    int left = 0, right = 0;
    while (right < s1.length())
    {
        s1hash[s1[right] - 'a']++;
        s2hash[s2[right] - 'a']++;
        right++;
    }
    right = right - 1; // TO POINT RIGHT TO THE END OF WINDOW
    while (right < s2.length())
    {
        if (s1hash == s2hash)
        {
            return true;
        }
        right++;
        if (right != s2.length())
        {
            s2hash[s2[right] - 'a']++;
            s2hash[s2[left] - 'a']--;
        }
        left++;
    }
    return false;
}
int main()
{
    string s1 = "cab";
    string s2 = "dbabcd";
    bool result = checkInclusion(s1, s2);
    cout << (result ? "True" : "False") << endl;
    return 0;
}
