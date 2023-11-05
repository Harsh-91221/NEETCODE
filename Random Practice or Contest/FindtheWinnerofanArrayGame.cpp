class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int maxi = *max_element(arr.begin(), arr.end);
        int winner = arr[0];
        int streak = 0;
        // If k is greater than or equal to the array size, return the maximum element.
        if (k >= arr.size())
        {
            return maxi;
        }
        for (int i = 1; i < arr.size(); i++)
        {
            // Check if the current element is greater than the current winner.
            if (arr[i] > winner)
            {
                winner = arr[i];
                streak = 1;
            }
            else
            {
                streak++;
            }
            // If the streak reaches k or the winner is the maximum element, return the winner.
            if (streak == k || winner == maxi)
            {
                return winner;
            }
        }
        // Return the winner if the loop completes without reaching k or the maximum element.
        return winner;
    }
};
