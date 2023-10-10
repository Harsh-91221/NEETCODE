// Brute force
// T.C - O(maxi-mini)*n
// S.c - O(1)
class Solution
{
public:
    bool possible(vector<int> &bloomDay, int day, int m, int k)
    {
        int n = bloomDay.size();
        int count = 0;
        int bouquets = 0;
        for (int i = 0; i < n; i++)
        {
            // Checking if the flower can bloom on that day
            if (bloomDay[i] <= day)
            {
                count++;
            }
            else
            {
                // Maintaing the count of number of days
                bouquets += (count / k);
                count = 0;
            }
        }
        // if we have elements left after the count turns 0
        bouquets += (count / k);
        if (bouquets >= m)
        {
            return true;
        }
        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        for (int i = mini; i <= maxi; i++)
        {
            // Checking for every day between minimum day and maximum day
            if (possible(bloomDay, i, m, k))
            {
                // returning number of days
                return i;
            }
        }
        return -1;
    }
};

// Optimal
// T.C - O(nlog(maxi-mini))
// S.c - O(1)
class Solution
{
public:
    bool possible(vector<int> &bloomDay, int day, int m, int k)
    {
        int n = bloomDay.size();
        int count = 0;
        int bouquets = 0;
        for (int i = 0; i < n; i++)
        {
            // Checking if the flower can bloom on that day
            if (bloomDay[i] <= day)
            {
                count++;
            }
            else
            {
                // Maintaing the count of number of days
                bouquets += (count / k);
                count = 0;
            }
        }
        bouquets += (count / k);
        if (bouquets >= m)
        {
            return true;
        }
        return false;
    }
    int minDays(vector<int> &bloomDay, long long m, long long k)
    {
        long long val = m * k;
        if (val > bloomDay.size())
        {
            return -1;
        }
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        while (mini <= maxi)
        {
            int mid = mini + (maxi - mini) / 2;
            if (possible(bloomDay, mid, m, k))
            {
                // As we want minimum so we will eleminate right half
                maxi = mid - 1;
            }
            else
            {
                mini = mid + 1;
            }
        }
    }
    return mini;
}