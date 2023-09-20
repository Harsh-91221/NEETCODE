/*
    Given 2 strings, return true if s2 contains permutation of s1
    Ex. s1 = "ab", s2 = "eidbaooo" -> true, s2 contains "ba"

    Sliding window, expand + count down char, contract + count up char

    Time: O(n)
    Space: O(1)
*/

class Solution
{
public:
    // Helper function to check if a character count vector is a permutation
    bool ispermutation(vector<int> &count)
    {
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
    // Main function to check if s2 contains a permutation of s1
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size(); // Length of s1
        int n = s2.size(); // Length of s2
        // If s1 is longer than s2, it's impossible for s1 to be a permutation of s2
        if (m > n)
        {
            return false;
        }
        // Initialize a character count vector with 26 zeros
        vector<int> count(26);
        // Initialize the character counts based on the first m characters of s1 and s2
        for (int i = 0; i < m; i++)
        {
            count[s1[i] - 'a']++; // Increment count for s1 character
            count[s2[i] - 'a']--; // Decrement count for s2 character
        }
        // Check if the initial window is a permutation of s1
        if (ispermutation(count))
        {
            return true;
        }
        // Move the sliding window through s2
        for (int i = m; i < n; i++)
        {
            count[s2[i] - 'a']--;     // Decrease count for new character in the window
            count[s2[i - m] - 'a']++; // Increase count for character going out of the window
            // Check if the current window is a permutation of s1
            if (ispermutation(count))
            {
                return true;
            }
        }
        // If no permutation is found, return false
        return false;
    }
};
