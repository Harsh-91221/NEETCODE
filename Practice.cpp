class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int result = 0;
        for (auto &a : left)
        {
            result = max(result, a);
        }
        for (auto &a : right)
        {
            result = max(result, n - a);
        }
        return result;
    }
};