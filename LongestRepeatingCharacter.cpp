/*
    Given a string s & an int k, can change any char k times:
    Return length of longest substring containing same letter
    Ex. s = "ABAB" k = 2 -> 4 "AAAA", s = "AABABBA" k = 1 -> 4

    Sliding window, expand if can change char, contract if > k

    Time: O(n)
    Space: O(26)
*/

int characterReplacement(string s, int k)
{
    int i = 0;             // Initialize a variable i to track the start of the current window.
    int maxCount = 0;      // Initialize maxCount to track the maximum frequency of any character in the current window.
    vector<int> ch(26, 0); // Create a vector ch to store the frequency of each character ('A' to 'Z').
    int result = 0;        // Initialize result to store the length of the longest valid substring.
    for (int j = 0; j < s.size(); j++)
    {
        // Increment the frequency of the current character s[j] in the vector ch.
        ch[s[j] - 'A']++;
        // Update maxCount to be the maximum frequency of any character in the current window.
        maxCount = max(maxCount, ch[s[j] - 'A']);
        // If the length of the current window minus maxCount is greater than k, we need to shrink the window.
        if (j - i + 1 - maxCount > k)
        {
            // Decrease the frequency of the character at the start of the window (s[i]).
            ch[s[i] - 'A']--;
            // Move the start of the window one position to the right.
            i++;
        }
        // Update the result with the maximum length seen so far.
        result = max(result, j - i + 1);
    }
    // The result now contains the length of the longest valid substring.
    return result;
}
