class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int maxi = *max_element(arr.begin(), arr.end());
        int winner = arr[0];
        int streak = 0;
        if (k >= arr.size())
        {
            return maxi;
        }
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > winner)
            {
                winner = arr[i];
                streak = 1;
            }
            else
            {
                streak++;
            }
            if (streak == k || winner == maxi)
            {
                return winner;
            }
        }
        return winner;
    }
};