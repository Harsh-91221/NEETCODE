// BRUTE FORCE
class Solution
{
public:
    int func(vector<int> &weights, int capacity)
    {
        int days = 1, load = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (load + weights[i] > capacity)
            {
                days++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int maxelement = *max_element(weights.begin(), weights.end());
        int sum = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
        }
        for (int i = maxelement; i <= sum; i++)
        {
            int daysreq = func(weights, i);
            if (daysreq <= days)
            {
                return i;
            }
        }
        return -1;
    }
};

// BINARY SEARCH
class Solution
{
public:
    int func(vector<int> &weights, int capacity)
    {
        int days = 1, load = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (load + weights[i] > capacity)
            {
                days++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            high += weights[i];
        }
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int daysreq = func(weights, mid);
            if (daysreq <= days)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};