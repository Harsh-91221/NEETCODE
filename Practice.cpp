class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();
        int quater = n / 4;
        for (int i = 0; i < n - quater; i++)
        {
            if (arr[i] == arr[i + quater])
            {
                return arr[i];
            }
        }
        return 0;
    }
};