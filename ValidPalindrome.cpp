/*
    Given a string s, return true if it's a palindrome
    Ex. s = "A man, a plan, a canal: Panama" -> true

    2 pointers, outside in, skip non-letters & compare

    Time: O(n)
    Space: O(1)
*/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        if (s.size() <= 1)
        {
            return true;
        }
        while (start < end)
        {
            while (start < end && !isalnum(s[start]))
            {
                start++;
            }
            while (start < end && !isalnum(s[end]))
            {
                end--;
            }
            if (start < end && tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};