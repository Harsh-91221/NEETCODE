void solve(string &str, int i, vector<vector<string>> &output)
{
    // If 'i' is equal to or greater than the size of 'str', it means we have
    // successfully generated a permutation, so we add it to the 'output'.
    if (i >= str.size())
    {
        output.push_back(str);
        return;
    }
    // Iterate through elements in the range [i, str.size() - 1].
    for (int j = i; j < str.size(); j++)
    {
        // Swap the elements at indices 'i' and 'j'.
        swap(str[i], str[j]);
        // Recursively call the 'solve' function for the next index (i + 1).
        solve(str, i + 1, output);
        // Restore the original order by swapping the elements back.
        swap(str[i], str[j]);
    }
}
vector<string> generatePermutations(string &str)
{
    vector<vector<string>> output;
    solve(str, 0, output);
    return output;
}