void solve(vector<string> &ans, string digits, int index, vector<string> &mapping, string output)
{
    if (index >= digits.size())
    {
        ans.push_back(output);
        return;
    }
    int digit = digits[index] - '0';
    string value = mapping[digit];
    for (int i = 0; i < value.size(); i++)
    {
        char ch = value[i];
        output.push_back(ch);
        solve(ans, digits, index + 1, mapping, output);
        output.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    string output = "";
    if (digits.size() == 0)
    {
        return ans;
    }
    vector<string> mapping(10);
    int index = 0;
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";
    solve(ans, digits, index, mapping, output);
    return ans;
}